/* 
    El programa se encarga de enviar un mensaje a un bot de Whatsapp y otro a un bot de Telegram
    Programado en ESP32.

    Autor: Martín Cioffi
    Fecha: 08-04-02024
    Versión: 1.00
    Repositorio: 
*/

#include <WiFi.h>    
#include <HTTPClient.h>
#include <UrlEncode.h>

const char* ssid = "wifi01-ei";
const char* password = "Ax32MnF1975-ReB";

// +international_country_code + phone number
// Portugal +351, example: +351912345678
String phoneNumber = "+5491150519109";
String username = "Martuan85";
String apiKey = "1356182";

void sendMessageWhatsapp(String message){

  // Data to send with HTTP POST
  String url = "https://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message);    
  HTTPClient http;
  http.begin(url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200){
    Serial.print("Message sent successfully");
  }
  else{
    Serial.println("Error sending the message");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }

  // Free resources
  http.end();
}

void sendMessageTelegram(String message){

  // Data to send with HTTP POST
  //String url = "https://api.callmebot.com/text.php?user=" + phoneNumber + "&text=" + message;   
  String url = "https://api.callmebot.com/text.php?user=" + username + "&text=" + message; 
  HTTPClient http;
  http.begin(url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200){
    Serial.print("Message sent successfully");
  }
  else{
    Serial.println("Error sending the message");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }

  // Free resources
  http.end();
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  // Send Message to WhatsAPP
  sendMessageWhatsapp("Hello from ESP32!");
  sendMessageTelegram("Hello from ESP32!");
}

void loop() {
  
}
