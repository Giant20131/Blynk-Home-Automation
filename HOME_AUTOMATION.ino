//Prateek
//www.justdoelectronics.com
#define BLYNK_TEMPLATE_ID "TMPL3od4lCwra"
#define BLYNK_TEMPLATE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "-it8ycxECfceYe93J3IkqvzBJL4zqQP2"


#include <Wire.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

#define DHTPIN 25 // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11  // DHT 11  
DHT dht(DHTPIN, DHTTYPE);


#define relay1 13
#define relay2 14
#define relay3 27
#define relay4 26



char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Airtel_Bharat";
char pass[] = "22042013";



BLYNK_WRITE(V0) {
  bool value1 = param.asInt();
  if (value1 == 1) {
    digitalWrite(relay1, LOW);
  } else {
    digitalWrite(relay1, HIGH);
  }
}

BLYNK_WRITE(V1) {
  bool value2 = param.asInt();
  if (value2 == 1) {
    digitalWrite(relay2, LOW);
  } else {
    digitalWrite(relay2, HIGH);
  }
}

BLYNK_WRITE(V2) {
  bool value3 = param.asInt();
  if (value3 == 1) {
    digitalWrite(relay3, LOW);
  } else {
    digitalWrite(relay3, HIGH);
  }
}

BLYNK_WRITE(V3) {
  bool value4 = param.asInt();
  if (value4 == 1) {
    digitalWrite(relay4, LOW);
  } else {
    digitalWrite(relay4, HIGH);
  }
}

BLYNK_WRITE(V4) {
  bool value5 = param.asInt();
  if (value5 == 1) {
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
    digitalWrite(relay3, HIGH);
    digitalWrite(relay4, HIGH);
       
  }
}


void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  float temperature = dht.readTemperature();
  Blynk.virtualWrite(V5, temperature);
  Blynk.run();

}