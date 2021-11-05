#include <nRF24L01.h>
#include <RF24.h>
#include <SPI.h>

RF24 radio(8, 7); // CE, CSN

struct dataPackage{
  byte msg;
};

dataPackage data;

void setup() {
  const byte address[6] = "11111";
  radio.begin();
  radio.openWritingPipe(address);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);
}

void loop() {
  data.msg = 12;
  radio.write(&data, sizeof(dataPackage));

  delay(75);
}
