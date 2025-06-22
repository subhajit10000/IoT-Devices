#include <ESP8266WiFi.h>

const char* ssid = "ESP8266";
const char* password = "NJPVandeBharat";

int ledPin1 = D5; // LED 1 connected to D5
int ledPin2 = D6; // LED 2 connected to D6



WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Match the request
  if (request.indexOf("/LED1=ON") != -1)  {
    digitalWrite(ledPin1, HIGH); // Turn on LED1
  }
  if (request.indexOf("/LED1=OFF") != -1)  {
    digitalWrite(ledPin1, LOW); // Turn off LED1
  }
  if (request.indexOf("/LED2=ON") != -1)  {
    digitalWrite(ledPin2, HIGH); // Turn on LED2
  }
  if (request.indexOf("/LED2=OFF") != -1)  {
    digitalWrite(ledPin2, LOW); // Turn off LED2
  }

  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); // do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  client.print("LED 1 is now: ");
  if (digitalRead(ledPin1) == HIGH) {
    client.print("ON");
  } else {
    client.print("OFF");
  }

  client.println("<br><br>");

  client.print("LED 2 is now: ");
  if (digitalRead(ledPin2) == HIGH) {
    client.print("ON");
  } else {
    client.print("OFF");
  }

  client.println("<br><br>");
  client.println("<a href=\"/LED1=ON\"\"><button>Turn On LED1</button></a>");
  client.println("<a href=\"/LED1=OFF\"\"><button>Turn Off LED1</button></a><br />");
  client.println("<a href=\"/LED2=ON\"\"><button>Turn On LED2</button></a>");
  client.println("<a href=\"/LED2=OFF\"\"><button>Turn Off LED2</button></a><br />");
  client.println("</html>");

  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
}
















