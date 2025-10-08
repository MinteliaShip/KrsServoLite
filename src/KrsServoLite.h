/*
  KrsServoLite- 近藤サーボを動かすclass
  作者 : MinteliaShip　最終更新 : 2025/10/08
*/

#ifndef KRS_SERVO_LITE_H
#define KRS_SERVO_LITE_H

#include <HardwareSerial.h>
#include <Arduino.h> 

class KrsServoLite {

  public:

    //セットアップ
    KrsServoLite(int Rx,int Tx,int En,unsigned long int baudRate,HardwareSerial* serialPort_ = &Serial2);

    KrsServoLite& setFREE();
    // ICS規格の角度数値
    KrsServoLite& setICS(unsigned int ics);
    // 度数法の数値
    KrsServoLite& setDEG(double deg);
    // 弧度法の数値
    KrsServoLite& setRAD(double rad);

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