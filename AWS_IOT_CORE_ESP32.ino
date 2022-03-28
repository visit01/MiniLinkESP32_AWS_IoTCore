#include <ModbusMaster.h>
#include <HardwareSerial.h>

#include "AWSkey.h"
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "WiFi.h"

/*###############################################################################*/

#define AWS_CLIENT_ID       "clientid_iot_airnode2"
#define AWS_PUBLISH          "airnode/uplink"
#define AWS_SUBSCRIBE        "airnode/downlink"

const char WIFI_SSID[] =    "plutter";
const char WIFI_PASS[] =    "visit012";
const char AWS_ENDPOINT[] = "a11e9qm2kfd54f-ats.iot.us-east-1.amazonaws.com";

/*###############################################################################*/

HardwareSerial ModbusSerial(2);
#define MAX485_DE      4
ModbusMaster node;

WiFiClientSecure net = WiFiClientSecure();
PubSubClient client(net);

unsigned long last1;
unsigned int result;
float t[2] = {};
int p[3] = {};

void setup() {
  
  Serial.begin(115200);

  pinMode(MAX485_DE, OUTPUT);
  digitalWrite(MAX485_DE, 0);

  ModbusSerial.begin(9600, SERIAL_8N1, 19, 18);

  node.begin(1, ModbusSerial);
  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission);

  AWS_CONNECT();
}

void loop() {
  
  if (millis() - last1 >= 10000) {
    last1 = millis();
    uplink();
  }

  client.loop();
  delay(1000);
}

/*-----------------------------------------------------------------------*/
void AWS_CONNECT() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  Serial.println("Wi-Fi Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  net.setCACert(AWS_CERT_CA);
  net.setCertificate(AWS_CERT_CRT);
  net.setPrivateKey(AWS_CERT_PRIVATE);

  client.setServer(AWS_ENDPOINT, 8883);
  client.setCallback(downlink);

  while (!client.connect(AWS_CLIENT_ID)) {
    Serial.print(".");
    delay(100);
  }
  Serial.println();

  if (!client.connected()) {
    Serial.println("AWS-IoT-Core Timeout!");
    return;
  }

  client.subscribe(AWS_SUBSCRIBE);
  Serial.println("AWS-IoT-Cotre Connected.");
}

/*-----------------------------------------------------------------------*/
void uplink()
{
  result = node.readHoldingRegisters(0, 5);
  if (result == node.ku8MBSuccess) {
    t[0] = node.getResponseBuffer(0) / 10.0;
    t[1] = node.getResponseBuffer(1) / 10.0;
    p[0] = node.getResponseBuffer(2);
    p[1] = node.getResponseBuffer(3);
    p[2] = node.getResponseBuffer(4);
  }

  StaticJsonDocument<200> sensor_data;
  sensor_data["nid"] = AWS_CLIENT_ID;
  sensor_data["temperature"] = t[0];
  sensor_data["humidity"] = t[1];
  sensor_data["pm1"] = p[0];
  sensor_data["pm2.5"] = p[1];
  sensor_data["pm10"] = p[2];
  
  char json[512];
  serializeJson(sensor_data, json); // print to client
  client.publish(AWS_PUBLISH, json);
  Serial.println(json);
}

/*-----------------------------------------------------------------------*/
void downlink(char* topic, byte* payload, unsigned int length)
{
  Serial.print("incoming: ");
  Serial.println(topic);

  StaticJsonDocument<200> doc;
  deserializeJson(doc, payload);
  const char* message = doc["message"];
  Serial.println(message);
}

/*-----------------------------------------------------------------------*/
void preTransmission() {
  digitalWrite(MAX485_DE, 1);
}

/*-----------------------------------------------------------------------*/
void postTransmission() {
  digitalWrite(MAX485_DE, 0);
}
