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
  http.begin(client,"https://iot-lead.onrender.com/");
  int httpCode = http.GET();
  if(httpCode > 0){
    String payload = http.getString();
    Serial.println(payload);
    }else{
      Serial.print("erro ao entrar");
      }
}

void loop() {
  
  WiFiClientSecure client;
  HTTPClient http;
  client.setInsecure();
  http.begin(client,"https://iot-lead.onrender.com/led/state-led");
  int httpCode = http.GET();
  String payload = http.getString();
  Serial.println(payload);

  StaticJsonDocument<54> doc;

  DeserializationError error = deserializeJson(doc,payload);
  if(error){
    Serial.print(F ("deu ruim a transformar doc em  json da api "));
    Serial.println(error.f_str());
    }
  bool state = doc["state"];
  Serial.println(state);
  digitalWrite(led,state);
  delay(10);
  // put your main code here, to run repeatedly:
  digitalWrite(led,HIGH);
  delay(500);
  digitalWrite(led,LOW);
  delay(500);
}
