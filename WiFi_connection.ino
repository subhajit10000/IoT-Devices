#include<ESP8266WiFi.h>
const char* ssid="*****";
const char* pass="*****";
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
// put your main code here, to run repeatedly:
}
