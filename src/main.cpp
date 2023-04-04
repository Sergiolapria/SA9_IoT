
#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include "credentials.h"
//This firmware makes a multisensor node with a ESP32
//I programmed this for a DOIT ESP32, so if you want 
//to try with another board you´d 
//indicate the board in platformio.ini
WiFiClient espClient;
PubSubClient client_mqtt(espClient);
long lastMsg=0;
char msg[50];
int val=0;
const int led=4;
///CALLBACK
void callback(char* topic,byte* message,unsigned int length){
  Serial.print("Mensaje con el topic:");
  Serial.println(topic);
  String msgTemp;
  for(int i=0;i<length;i++){
    Serial.print((char)message[i]);
    msgTemp +=(char)message[i];
  }
  Serial.println();
  //topic "esp32/output1"
  if(String(topic)=="esp32/output1"){
    Serial.print("Changing output to");
    if(msgTemp=="on"){
      digitalWrite(led,HIGH);
    }else if(msgTemp=="off"){
      digitalWrite(led,LOW);
    }
  }
}
////MQTT
void setup_mqtt(){
  client_mqtt.setServer(mqtt_server,1883);
  client_mqtt.setCallback(callback);
  pinMode(led,OUTPUT);
}
/// WiFi
void setup_WiFi(){
  WiFi.begin(ssid,psk);
  while (WiFi.status() !=WL_CONNECTED){
    delay(100);
    Serial.println("Connecting to WiFi......");
  }
  Serial.print("Connected to the Network with ");
  Serial.print("IP ADDRESS: ");
  Serial.println(WiFi.localIP());
}
void reconnect(){
  while (!client_mqtt.connected()){
    Serial.println("Esperando conexion...");
    if(client_mqtt.connect("ID")){
      Serial.println("Connected");
      client_mqtt.subscribe("esp32/output1");//me subscribo si quiero mensajes entrantes
    }else{
      Serial.print("failed, rc=");
      Serial.print(client_mqtt.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

/// program
void setup() {
  Serial.begin(115200);
  setup_WiFi();
  setup_mqtt();
}
void loop() {
 long now=millis();
 if(now-lastMsg>5000){
  lastMsg=now;
 } 
 //READ SENSOR
int value_IN;
 //Convert the value to a char array
 char valString[8];
 dtostrf(value_IN,1,2,valString);
 client_mqtt.publish("esp32/value",valString);
}