#include <KrsSevoLite.h>

//myKrsSevo( [Rxピン] , [Txピン] , [Enピン] , [ボーレート(通信速度)] );
KrsSevoLite myKrsSevo(22,19,23,115200);

void setup() {
  Serial.begin(115200);

//myKrsSevo.setDEG( [度数] ).sendICS( [サーボID] );
  myKrsSevo.setDEG(45).sendICS(0);

//myKrsSevo.setRAD( [弧度法] ).sendICS( [サーボID] );
  myKrsSevo.setRAD(PI/4.0).sendICS(0);

}

void loop() {
  Serial.println(myKrsSevo.setFREE().sendICS(0));
}


/*
　<角度司令関数>
・構文
[オブジェクト].[角度指定].sendICS( [サーボID] );

・例
myKrsSevo.setDEG(45).sendICS(0);
オブジェクト  :myKrsSevo
角度         :45°
サーボID     :0番

　<角度指定>
・setDEG  :度数法指定
・setRAD  :弧度法指定
・setICS  :ICS指定
・setFREE :脱力
*/
