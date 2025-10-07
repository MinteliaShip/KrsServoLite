/*
  KrsSevoLite- 近藤サーボを動かすclass
  作者 : MinteliaShip　最終更新 : 2025/10/07
*/

#ifndef KRS_SERVO_LITE_H
#define KRS_SERVO_LITE_H

#include <HardwareSerial.h>
#include <Arduino.h> 

class KrsSevoLite {

  public:

    //セットアップ
    KrsSevoLite(int Rx,int Tx,int En,unsigned long int baudRate,HardwareSerial* serialPort_ = &Serial2);

    KrsSevoLite& setFREE();
    // ICS規格の角度数値
    KrsSevoLite& setICS(unsigned int ics);
    // 度数法の数値
    KrsSevoLite& setDEG(double deg);
    // 弧度法の数値
    KrsSevoLite& setRAD(double rad);

    unsigned long sendICS(int ID,int sendOnly_ = -1);

  private:

    HardwareSerial* serialPort = nullptr;
    bool sendOnly;
    int EnPin;
    long TIMEOUT = 1000;

    bool exchangeData(char *txBuf, char txLen, char *rxBuf, char rxLen);

    int pos;
};

#endif