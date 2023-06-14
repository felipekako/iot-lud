#include "./config.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

#define led D8

bool stateLedApi;

void setup() {

  Serial.println();
  Serial.print("Conectando o wifi");
  Serial.println(ssid);
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED){
     delay(1000);
  Serial.print('.');
  }
  Serial.println("");
  Serial.println("wifi conectado");
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);


  WiFiClientSecure client;
  HTTPClient http;

  client.setInsecure();
  http.begin(client,"https://iot-lead.onrender.com");
  int httpCode = http.GET();
  if(httpCode > 0){
    String payload = http.getString();
    Serial.println(payload);
    }else{
      Serial.print("erro ao entrar");
      }
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
  delay(500);
}
