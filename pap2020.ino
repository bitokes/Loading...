#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>
#include <DHT.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

//parametros das funções
#define FIREBASE_HOST "pap2021-92c05-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "s1m84sljeSoSZfXUUgFJZWOjgle4nmqUNBICu8ve"
#define WIFI_SSID "TP-Link_Extender"
#define WIFI_PASSWORD ""

WiFiUDP ntp;

NTPClient timeClient(ntp, "europe.pool.ntp.org", 3600, 60000);

int hora; 
int minu;
int a = timeClient.getHours() ;
int b = timeClient.getMinutes() ;

 
//pinos
#define FOG        D3
#define MOV        D6
#define RELE1      D0
#define RELE2      D1
#define RELE3      D2
#define RELE4      D5
#define DHTPIN     D7 
#define FUM        D4   
#define DHTTYPE    DHT11


DHT dht(DHTPIN, DHTTYPE);


//ojectos da firebase

FirebaseData firebaseData;
FirebaseData reles;
FirebaseData hi;
FirebaseData mi;
FirebaseData hf;
FirebaseData mf;

FirebaseJson json;



void setup() {

pinMode(RELE1,OUTPUT);
pinMode(RELE2,OUTPUT);
pinMode(RELE3,OUTPUT);
pinMode(RELE4,OUTPUT);



pinMode(MOV,INPUT);
pinMode(FUM,INPUT);
pinMode(FOG,INPUT);

   dht.begin();
  Serial.begin(9600);
 // Serial.setTimeout(20);
 // connect to wifi.

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
   Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  
 
 
}


void loop() {
sensores();
Auto();
btn();
}









void sensores(){

    float h = dht.readHumidity();
  
  float t = dht.readTemperature();
 
  float f = dht.readTemperature(true);
  
  int al  = digitalRead(FOG);

  int mo  = digitalRead(MOV);

  int fum = digitalRead(FUM);

  

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("C  ,"));
  Serial.print(f);
  Serial.println(F("F  "));

  if (Firebase.setFloat(firebaseData, "Temperatura", t))
  {
    Serial.println("Temperatura enviada");
  }
  else
  {
    Serial.println("Temperatura falhou");
    Serial.println("razão: " + firebaseData.errorReason());
    Serial.println("------------------------------------");
    Serial.println();
  }

  if (Firebase.setFloat(firebaseData, "Humidade", h))
  {
    Serial.println("humidade enviada");
   
  }
  else
  {
    Serial.println("Humidade falhou");
    Serial.println("razão: " + firebaseData.errorReason());
    Serial.println("------------------------------------");
    Serial.println();
  }
   if (Firebase.setFloat(firebaseData, "Alarme", al))
  {
    Serial.println("fogo enviado");
   
  }
  else
  {
    Serial.println("Alarme falhou");
    Serial.println("razão: " + firebaseData.errorReason());
    Serial.println("------------------------------------");
    Serial.println();
  }

  if (Firebase.setFloat(firebaseData, "Movimento", mo))
  {
    Serial.println("Movimento enviado");
   
  }
  else
  {
    Serial.println("Movimento falhou");
    Serial.println("razão: " + firebaseData.errorReason());
    Serial.println("------------------------------------");
    Serial.println();
  }

   if (Firebase.setFloat(firebaseData, "Fumo", fum))
  {
    Serial.println("Fumo enviado");
   
  }
  else
  {
    Serial.println("Fumo falhou");
    Serial.println("razão: " + firebaseData.errorReason());
    Serial.println("------------------------------------");
    Serial.println();
  }
  }







  

void btn(){


  
    if (Firebase.getString(reles, "luz1")) {

    if (reles.dataType() == "string") {
      Serial.println(reles.stringData());
       if (reles.stringData() == "1") {
         digitalWrite(RELE1, LOW);
       }
        else if (reles.stringData() == "0"){
       digitalWrite(RELE1, HIGH);
        }
    }

  } else {
    Serial.println(reles.errorReason());
  }     

 
if (Firebase.getString(reles, "luz2")) {

    if (reles.dataType() == "string") {
      Serial.println(reles.stringData());
       if (reles.stringData() == "1") {
         digitalWrite(RELE2, LOW);
       }
        else if (reles.stringData() == "0"){
       digitalWrite(RELE2, HIGH);
        }
    } 

  } else {
    Serial.println(reles.errorReason());
  }     

 
 if (Firebase.getString(reles, "luz3")) {

    if (reles.dataType() == "string") {
      Serial.println(reles.stringData());
       if (reles.stringData() == "1") {
         digitalWrite(RELE3, LOW);
       }
        else if (reles.stringData() == "0"){
       digitalWrite(RELE3, HIGH);
        }
    }

  } else {
    Serial.println(reles.errorReason());
  }     



  if (Firebase.getString(reles, "luz4")) {

    if (reles.dataType() == "string") {
      Serial.println(reles.stringData());
       if (reles.stringData() == "1") {
         digitalWrite(RELE4, LOW);
       }
        else if (reles.stringData() == "0"){
       digitalWrite(RELE4, HIGH);
        }
    }

  } else {
    Serial.println(reles.errorReason());
  } 

  
  }






void Auto(){
  
  

  if (Firebase.getString(reles, "/auto/confi")) {

    if (reles.dataType() == "string") {
   
       if (reles.stringData() == "1") {
         
 timeClient.update();

hora = timeClient.getHours() ;
minu = timeClient.getMinutes() ;


String h = "1";
int c;
int d;
int c2;
int d2; 

  if (Firebase.getInt(reles, "/auto/hora ini")) {

    if (reles.dataType() == "int") {
      c =reles.intData();



       if (Firebase.getInt(reles, "/auto/min ini")) {

            if (reles.dataType() == "int") {
              
              d =reles.intData();

               if (hora == c){

                 if (minu == d){
              
                       
                       
                       
                        if (Firebase.getString(reles, "/auto/Luz1")) {

                              if (reles.dataType() == "string") {
                                Serial.println(reles.stringData());
                                 if (reles.stringData() == "1") {
                                
                                   if (Firebase.setString(reles, "/luz1", "0"))
                                        {
                                          Serial.println("sucesso");
   
                                        }

                                   
                                 }
                                 
                              }
                          
                            } else {
                              Serial.println(reles.errorReason());
                            }     
                          
                           
                          
                        if (Firebase.getString(reles, "/auto/Luz2")) {

                              if (reles.dataType() == "string") {
                                Serial.println(reles.stringData());
                                 if (reles.stringData() == "1") {
                                 
                                   if (Firebase.setString(reles, "/luz2", "0"))
                                        {
                                          Serial.println("sucesso");
   
                                        }
                                 }
                                  
                              }
                          
                            } else {
                              Serial.println(reles.errorReason());
                            }    
                        
                         
                        
                        if (Firebase.getString(reles, "/auto/Luz3")) {

                              if (reles.dataType() == "string") {
                                Serial.println(reles.stringData());
                                 if (reles.stringData() == "1") {
             
                                   if (Firebase.setString(reles, "/luz3", "0"))
                                        {
                                          Serial.println("sucesso");
   
                                        }
                                 }
                                
                              }
                          
                            } else {
                              Serial.println(reles.errorReason());
                            } 
                        
                        
                        
                          
                        if (Firebase.getString(reles, "/auto/Luz4")) {

                              if (reles.dataType() == "string") {
                                Serial.println(reles.stringData());
                                 if (reles.stringData() == "1") {
                                
                                   if (Firebase.setString(reles, "/luz4", "0"))
                                        {
                                          Serial.println("sucesso");
   
                                        }
                                 }
                               
                              }
                          
                            } else {
                              Serial.println(reles.errorReason());
                            } 
                       
                       Serial.println("deu");
              
                  }
              }
          }
       }
    }
  }







if (Firebase.getInt(reles, "/auto/hora fin")) {

    if (reles.dataType() == "int") {
      c2 =reles.intData();



       if (Firebase.getInt(reles, "/auto/min fin")) {

            if (reles.dataType() == "int") {
              
              d2 =reles.intData();

               if (hora == c2){

                 if (minu == d2){
              
                       
                       
                       
                        if (Firebase.getString(reles, "/auto/Luz1")) {

                              if (reles.dataType() == "string") {
                                Serial.println(reles.stringData());
                                 if (reles.stringData() == "1") {
                                
                                   if (Firebase.setString(reles, "/luz1", "1"))
                                        {
                                          Serial.println("sucesso");
   
                                        }

                                   
                                 }
                                 
                              }
                          
                            } else {
                              Serial.println(reles.errorReason());
                            }     
                          
                           
                          
                        if (Firebase.getString(reles, "/auto/Luz2")) {

                              if (reles.dataType() == "string") {
                                Serial.println(reles.stringData());
                                 if (reles.stringData() == "1") {
                                 
                                   if (Firebase.setString(reles, "/luz2", "1"))
                                        {
                                          Serial.println("sucesso");
   
                                        }
                                 }
                                  
                              }
                          
                            } else {
                              Serial.println(reles.errorReason());
                            }    
                        
                         
                        
                        if (Firebase.getString(reles, "/auto/Luz3")) {

                              if (reles.dataType() == "string") {
                                Serial.println(reles.stringData());
                                 if (reles.stringData() == "1") {
             
                                   if (Firebase.setString(reles, "/luz3", "1"))
                                        {
                                          Serial.println("sucesso");
   
                                        }
                                 }
                                
                              }
                          
                            } else {
                              Serial.println(reles.errorReason());
                            } 
                        
                        
                        
                          
                        if (Firebase.getString(reles, "/auto/Luz4")) {

                              if (reles.dataType() == "string") {
                                Serial.println(reles.stringData());
                                 if (reles.stringData() == "1") {
                                
                                   if (Firebase.setString(reles, "/luz4", "1"))
                                        {
                                          Serial.println("sucesso");
   
                                        }
                                 }
                               
                              }
                          
                            } else {
                              Serial.println(reles.errorReason());
                            } 
                       
                       Serial.println("também deu");
              
                  }
              }
          }
       }
    }
  }













  

         
       } else{
        Serial.println(reles.errorReason());
        }
    }

     


    }


  
  }
