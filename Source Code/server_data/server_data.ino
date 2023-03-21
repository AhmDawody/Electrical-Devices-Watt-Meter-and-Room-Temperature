#include <ESP8266WiFi.h>

// Set the SSID and password for the access point
const char* ssid = "ESP8266AP";
const char* password = "password";

// Create an instance of the WiFiServer
WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  // Start the access point
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  // Print the IP address of the access point
  Serial.print("Access Point IP address: ");
  Serial.println(WiFi.softAPIP());

  // Start the server
  server.begin();
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  while (!client.available()) {
    delay(1);
  }

  // Read the data from the client
  String request = client.readStringUntil('\r');

  // Print the request to the serial monitor
  Serial.print("Request: ");
  Serial.println(request);

  // Send the HTTP response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); // this line is important

  // Print the data received from UART
  client.print("Data received: ");
  client.println(Serial.readString());

  // Close the connection
  client.stop();
}

