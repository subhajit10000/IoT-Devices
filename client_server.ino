#include<ESP8266WiFi.h>

const char* ssid="NIHAR";
const char* pass="NIHAR264666";

WiFiServer server(80);

void setup() {
Serial.begin(9600);
// put your setup code here, to run once:
WiFi.begin(ssid,pass);
while(WiFi.status()!=WL_CONNECTED)
{
delay(100);
Serial.print("@");

}
Serial.println("connected");
server.begin();
Serial.println(WiFi.localIP());
}

void loop() 
{
WiFiClient client=server.available();
client.print("ardent");
// put your main code here, to run repeatedly:
}