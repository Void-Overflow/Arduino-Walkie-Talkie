#include <nRF24L01.h>
#include <RF24.h>
#include <SPI.h>

struct dataPackage{
  byte msg;
};

dataPackage data;

RF24 radio(8, 7); // CE, CSN

void setup() {
  Serial.begin(9600);

  const byte address[6] = "11111";
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    radio.read(&data, sizeof(dataPackage));
    Serial.println(String(data.msg));
  }

  delay(4);
}
