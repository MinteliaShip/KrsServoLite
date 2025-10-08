# KrsServoLite
近藤化学のKRSサーボモータをESP32(M5Atom等)で動かすためのライブラリ。

KRSに指令送信と角度受信を行うことができる。

#  <KRSポート設定> 
・ピン設定

 [Rxピン] , [Txピン] , [Enピン] , [ボーレート(通信速度)] 
 
KrsServoLite myKrsSevo(19,33,23,115200);

※Txのみ使用する場合はRxとEnピンは-1を指定する。


# <角度司令関数>
 
・構文

[オブジェクト].[角度指定].sendICS( [サーボID] );

・例

myKrsSevo.setDEG(45).sendICS(0);

オブジェクト  :myKrsSevo

角度         :45°

サーボID     :0番


# <角度指定>
 
・setDEG  :度数法指定

・setRAD  :弧度法指定

・setICS  :ICS指定

・setFREE :脱力

