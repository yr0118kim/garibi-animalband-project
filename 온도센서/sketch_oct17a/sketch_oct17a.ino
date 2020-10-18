#include <SoftwareSerial.h>
#include "DHT.h"
#define DHTPIN      4
#define DHTTYPE     DHT11
#define BTtx        7
#define BTrx        8
SoftwareSerial BT(BTtx, BTrx);
DHT dht(DHTPIN, DHTTYPE);
unsigned long previousTime = 0;

void setup() {
  BT.begin(9600);
  dht.begin();
}

void loop(){
  unsigned long currentTime = millis();
  if((unsigned long)(currentTime - previousTime) >= 2000) {
    previousTime = currentTime;
    byte t = dht.readTemperature();//Celsius
    byte h = dht.readHumidity();
    if(!(isnan(h) || isnan(t))) {//return 1 if not a num 
      BT.print(t);
      BT.print(",");
      BT.println(h);
    }
  }
}
