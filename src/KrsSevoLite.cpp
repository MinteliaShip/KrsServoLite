#include "KRSservoLite.hpp"

KrsSevoLite::KrsSevoLite(int Rx,int Tx,int En,unsigned long int baudRate,HardwareSerial* serialPort_){
  serialPort = serialPort_;
  serialPort -> begin(baudRate,SERIAL_8E1,Rx,Tx);
  serialPort -> setTimeout(TIMEOUT);  
  if(Rx==-1||En==-1){
    sendOnly  = 1;
  }else{
    pinMode(En,OUTPUT);
    EnPin = En;  
  }

}


bool KrsSevoLite::exchangeData(char *txByte, char txLen, char *rxByte, char rxLen){
  digitalWrite(EnPin, HIGH);
  serialPort -> flush(); 
  serialPort -> write(txByte, txLen);
  serialPort -> flush();
  while (serialPort -> available() > 0)serialPort -> read();
  digitalWrite(EnPin, LOW);
  int val = serialPort -> readBytes(rxByte, rxLen);
  if(val == rxLen)return 0;
  return 1;
}


KrsSevoLite& KrsSevoLite::setFREE() {pos = 0;return *this;}
KrsSevoLite& KrsSevoLite::setICS(unsigned int ics) {pos = ics;return *this;}
KrsSevoLite& KrsSevoLite::setDEG(double deg) {pos = (unsigned int)((deg * 800.0) / 27.0) + 7500;return *this;}
KrsSevoLite& KrsSevoLite::setRAD(double rad) {pos = (unsigned int)(rad * 1697.6527263 + 7500);return *this;}

unsigned long KrsSevoLite::sendICS(int ID,int sendOnly_){
  if (!serialPort) {
    Serial.print("[E] ポートを設定していない");
    return 1;
  }

  char txByte[3];
  char reByte[3];

  if (pos == 0) {

  } else if (pos > 11500) {
    return pos;
  } else if (pos < 3500) {
    return pos;
  }

  
  txByte[0] = 0b10011111 & (0b10000000 | ID);
  txByte[1] = char((pos & 0b00011111110000000) >> 7);
  txByte[2] = char(pos & 0b00000000001111111);

  delayMicroseconds(100);

  if (sendOnly || sendOnly_ ==1) {
    exchangeData(txByte, 3, reByte, 0);
    return 0;
  } else if (exchangeData(txByte, 3, reByte, 3)) {
    return 1;
  }
  
  return (unsigned int)(reByte[1] << 7) | reByte[2];
}