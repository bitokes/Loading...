#include <ArduinoJson.h>


// conexões
#define FIREBASE_HOST "pap2020-8183b.firebaseio.com"
#define FIREBASE_AUTH "vb63xs9WJTOGoGfiSWrB9GYL0IS90VSP0TXKXOO9"
#define WIFI_SSID "Vodafone-4BCBC1"
#define WIFI_PASSWORD "2f4pnn6UyF"


#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <FirebaseArduino.h>


#define MOV       D1
#define DHTPIN    D3
#define DHTTYPE   DHT11
#define BAUDRATE  115200
#define LUZrua    D2
#define RELE1     D5
#define RELE2     D6
#define RELE3     D7
#define RELE4     D8
  
struct readings {

  float hum;          // Humidity     
  float temp;         // Temperature 
  bool  mov;          // Sensor de Movimento
  String  rel1;
  String  rel2;
  String  rel3;
  String  rel4;
} readings;

DHT dht(DHTPIN, DHTTYPE);

unsigned long previousMillis = 0;
const long interval = 2000;

void connectToWiFi(char const *ssid, char const *password);
void readSensors(struct readings *r);
void displaySensors(struct readings r);
void sendDataToFirebase(struct readings r);

void setup() {
  pinMode(RELE1, OUTPUT);
  pinMode(RELE2, OUTPUT);
  pinMode(RELE3, OUTPUT);
  pinMode(RELE4, OUTPUT);
  pinMode(MOV,    INPUT);
  Serial.begin(BAUDRATE);
  connectToWiFi(WIFI_SSID, WIFI_PASSWORD);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  dht.begin();
  
 
  
}
void reles (){
  
  }
  
void loop() {

  unsigned long currentMillis = millis();
   

  if (currentMillis - previousMillis >= interval) {
 
    previousMillis = currentMillis;

    readSensors(&readings);

    displaySensors(readings);

    sendDataToFirebase(readings);
    
    
  }
  String path1 = "rele1";
  FirebaseObject object = Firebase.get(path1);
  Serial.println(path1);
}

void connectToWiFi(char const *ssid, char const *password) {
  delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.print(ssid);
  
  WiFi.mode(WIFI_STA);

  WiFi.disconnect();

  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("");
}

void readSensors(struct readings *r) {
  #ifdef DONT_HAVE_SENSORS
  
    readings.mov  = !readings.mov;
    readings.temp = random(0, 80);
    readings.hum  = random(0, 80);
  #else
  
    r->mov = digitalRead(MOV);
    
    r->hum = dht.readHumidity();
   
    r->temp = dht.readTemperature();
    
    if (isnan(r->hum) || isnan(r->temp)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }
  #endif
}

void displaySensors(struct readings r) {

  Serial.print("[INFO] Movimento: ");
  Serial.println(r.mov);
  Serial.print("[INFO] Humidity: ");
  Serial.print(r.hum);
  Serial.println("%");
  Serial.print("[INFO] Temperature: ");
  Serial.print(r.temp);
  Serial.println("°C ");

}

   
void sendDataToFirebase(struct readings r) {
 
    String gasStatusID = Firebase.pushInt("movimento", r.mov);
  if (Firebase.failed()) {
    Serial.print("[ERROR] pushing movimento/movStatus failed:");
    Serial.println(Firebase.error());
    return;
  }

  String humValueID = Firebase.pushFloat("dht11/humidity", r.hum);
  if (Firebase.failed()) {
    Serial.print("[ERROR] pushing /dht11/humidity failed:");
    Serial.println(Firebase.error());
    return;
  }

  String tempValueID = Firebase.pushFloat("dht11/temperature", r.temp);
  if (Firebase.failed()) {
    Serial.print("[ERROR] pushing /dht11/temperature failed:");
    Serial.println(Firebase.error());
    return;
  }
    
      
  }
   
   
