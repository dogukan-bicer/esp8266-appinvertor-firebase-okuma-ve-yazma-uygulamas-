#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "deneme" //real time database in host adresi
#define FIREBASE_AUTH "deneme" //database secret adresi
#define WIFI_SSID "deneme" //wifi adı
#define WIFI_PASSWORD "deneme"//wifi şifresi
#include "DHTesp.h"
DHTesp dht;

void setup() {
  Serial.begin(9600);
  dht.setup(D4, DHTesp:: DHT11);
  pinMode(D8,OUTPUT);
  digitalWrite(D8,HIGH);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); //wifi kontrolleri
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);//firebase başlat
}

int n = 0;

void loop() {
  float hum= dht.getHumidity();
  float temp= dht.getTemperature();

  Serial.print("hum: ");Serial.println(hum);
  Serial.print("temp: ");Serial.println(temp);

  Firebase.setFloat("hum", hum); /////////////////////////////////////////////////////////////////////float tipi veri gönderme
    if (Firebase.failed()) {//hata kontrolü 
      Serial.print("setting /hum failed:");
      Serial.println(Firebase.error()); 
  }
  
   Firebase.setFloat("temp", temp);/////////////////////////////////////////////////////////////////////float tipi veri gönderme
    if (Firebase.failed()) {
      Serial.print("setting /temp failed:");
      Serial.println(Firebase.error());//hata kontrolü 
  }

 String lambadurum =Firebase.getString("lamp");/////////////////////////////////////////////////////////////string tipi veri okuma
 Serial.print("lambadurum=");Serial.println(lambadurum);

 if(lambadurum=="0"){
 digitalWrite(D8,LOW);
 }
 else if(lambadurum=="1"){
 digitalWrite(D8,HIGH);
 //delay(50);
 }
}#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "sensorveri-default-rtdb.firebaseio.com" //real time database in host adresi
#define FIREBASE_AUTH "HmQqJB2yeiYUBZdSOvKIT6Ib4T5AgyPZjgG1oVTB" //database secret adresi
#define WIFI_SSID "KENANBiCER" //wifi adı
#define WIFI_PASSWORD "7F8F77372552b"//wifi şifresi
#include "DHTesp.h"
DHTesp dht;

void setup() {
  Serial.begin(9600);
  dht.setup(D4, DHTesp:: DHT11);
  pinMode(D8,OUTPUT);
  digitalWrite(D8,HIGH);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); //wifi kontrolleri
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);//firebase başlat
}

int n = 0;

void loop() {
  float hum= dht.getHumidity();
  float temp= dht.getTemperature();

  Serial.print("hum: ");Serial.println(hum);
  Serial.print("temp: ");Serial.println(temp);

  Firebase.setFloat("hum", hum); /////////////////////////////////////////////////////////////////////float tipi veri gönderme
    if (Firebase.failed()) {//hata kontrolü 
      Serial.print("setting /hum failed:");
      Serial.println(Firebase.error()); 
  }
  
   Firebase.setFloat("temp", temp);/////////////////////////////////////////////////////////////////////float tipi veri gönderme
    if (Firebase.failed()) {
      Serial.print("setting /temp failed:");
      Serial.println(Firebase.error());//hata kontrolü 
  }

 String lambadurum =Firebase.getString("lamp");/////////////////////////////////////////////////////////////string tipi veri okuma
 Serial.print("lambadurum=");Serial.println(lambadurum);

 if(lambadurum=="0"){
 digitalWrite(D8,LOW);
 }
 else if(lambadurum=="1"){
 digitalWrite(D8,HIGH);
 //delay(50);
 }
}
