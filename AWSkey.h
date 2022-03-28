#include <pgmspace.h>

static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";
 
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAM9ubc+nz12VC1lsv+yicMYPlvCrMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMjAzMjcwOTU1
NThaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCuVpFDyPmS6rmVu+DV
rcTgT/Ki7RoFSPeHOR3bPsxfbsXaylajWeBgQme0Gknux/ex6hO4R1Zm0gmngBRZ
yOO32fj4rud4SXlvLyAKme73cecBIZBi6kZF7Y7LyP8VCKVRAtg/jOSj8vtoNax3
kXsNsY5DewsI4rSda8+h2MMPzlo9pjrmz6mTxHSm3Mn8/RTXI0xh5XKzp+tvXqdu
Nn5KbxK3Ek5V6uC+ftDyCoJx7Jeeg1DvSxyVsfUiRgpnspfFPurajpdZqhyDfw6+
SyOrpduMSMGPx4NyUTgxt+ZvQdJDOMVzE0Zk5+M4uiB1wlK3JJfxQ//tmyfeccM7
5mCDAgMBAAGjYDBeMB8GA1UdIwQYMBaAFGntHCiAhm867A63uY+eab4qa4VBMB0G
A1UdDgQWBBQX+M9N7xbWfXFtgsQPRBquomzs+DAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAdMfIL1xN82DFTY2ZZ2rzV5Ga
MPcnRTm0zze0oaU5a3cJgC54K861Dj0zK0uU/p2rDiGowmCQmrPAzXNfkI5WlhjF
7G6otsy5/UuQqeBmHe55/UJbQmbpiu5jOc1utrfQjnQvlX6w0ltawfWMjv5eS2nD
iLQM7UBEbeUqr3MxP2ZT/3dzKcEKb9l4EhNBhavcIx8uD43NUvNqS+lnRHqTkiq6
t6K2eIIuhvRxCocIsD7axdvEtuUzooc4dAHvCkUUoudDq+jnU6AQkVjdiA3x7cb7
t+xcG6QjXuU9x1sTZmDTaIGjTpKsyUMpiaJ+S6ex2XeT0DARWfs93wl5bYFzhQ==
-----END CERTIFICATE-----
 
 
)KEY";
 
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEogIBAAKCAQEArlaRQ8j5kuq5lbvg1a3E4E/you0aBUj3hzkd2z7MX27F2spW
o1ngYEJntBpJ7sf3seoTuEdWZtIJp4AUWcjjt9n4+K7neEl5by8gCpnu93HnASGQ
YupGRe2Oy8j/FQilUQLYP4zko/L7aDWsd5F7DbGOQ3sLCOK0nWvPodjDD85aPaY6
5s+pk8R0ptzJ/P0U1yNMYeVys6frb16nbjZ+Sm8StxJOVergvn7Q8gqCceyXnoNQ
70sclbH1IkYKZ7KXxT7q2o6XWaocg38Ovksjq6XbjEjBj8eDclE4Mbfmb0HSQzjF
cxNGZOfjOLogdcJStySX8UP/7Zsn3nHDO+ZggwIDAQABAoIBAARA6nRr7+LsxTBp
EBhGkBok+TeOb2cXm6p580eJJbViX4NyEmET7UyL8jnLtmgUCvAVVPvXCb2ifEfQ
8S4rn5q5v8BZjB48NLFIxhBcJx90cP1vEzXGn4ZPQH+qXMbnmhj658nNJzr0z7uA
K8ATFZyE64Kr+t3xohSBL+S0BDZbeTgjri9aQ2TOBWiN10DfFujNhuhpdHa8nacu
gOJLe0hN4xwCYpUVmZF0WXGlKCmvOxp51QCZrtqpzkgeDki3s26DdimHFCP8WAHx
eykj2YQjOdxjxJKJ4jAcBgaULb4U51CHOiuQ+OU1qi4Mlc1Ht0LDnhhLT19hQNEw
VxT+NUECgYEA3Xs8SVC+eJ5zGRUnLLHSEbARSRuRRs6OZOuD9fJdeVQfGWC46zts
NDmc/SArDdpdiQsxaFPC/EWZY6WzTKkRnr3djy1vIRunUkgt1eCxHuELOzvr3MGh
lB0Kz4OuTZS1ppnyPsMkQt0ETyjMWdpRpkfgE+VBbTnEBNOVifSl+2ECgYEAyYJj
ztbV/q0L1xMHxs48LZir6k8TgsxueeZKbsEczzPsfFDTm90ltsG7vWgcUv8UnUWF
i1wut7ZLVC468SxMvHoHbwzS/LdKCRrmGTn6SzzL7/H2mIxvJPe+JGF6GJJmKdS8
aHYdXnBDvHQHamk+9LkX3tZ4x77JfzB1ZWmgamMCgYBY4WekFF8bkJqn6jE6YnHm
3z1QlVuLisDiBxGB1a1lTzjbulD7NXGK08QIYKxmdscqg+9j6plJG7UepBR8Iy0L
Ay6yko0SQEK5ZnXearkppy4Wq0lP4fSxt6Xq+PEt+QucvBLW1QDsRD3CdqDrPg2e
KSHnWg0ThCcBuNc98YvagQKBgD/NBujgYJToGU2ZeubZOXh+VEA1lUnejEQQRBTZ
E9QO7ptVxAofdOduY5DOu9kTZmV9M5EyOKB2GVen44Wkrw8l2+CvQMY/CjPjzmLC
VpsnvrJT++3E2RPtVMiUDGJnR+2Kq7SvYREbnna2jfqFJCe7yvEFGuyzXXzlzOW1
EdNdAoGACKnBXwxnD5KA+cTyCMvyyJDUwnj9Ou5KuvJ0ZjD4abFdO/jF34PkBjLy
hZk1fjBLj+lj+ZLTleDnBikCWK2QWR5azVC2JHwwX5+mwqPFk2yUMp+4cigvOSFZ
0FJH1CxGhh/FbXYjP5pp759psczxrzNu1YBpgN7sFj10K5XvIts=
-----END RSA PRIVATE KEY-----
 
 
)KEY";
