#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>
 
char serialData;
int nsong;
int v;
 
SoftwareSerial comm(10,11);
DFRobotDFPlayerMini mp3;
 
void setup() {
  Serial.begin(9600);
  comm.begin(9600);
 
  mp3.begin(comm);serialData = (char)((' '));
 
}
 
void loop() {
  if (Serial.available()) {
    serialData = (Serial.read());
    if (serialData == ('w')) {
      Serial.println("Play Song");
      mp3.start();
    } else if (serialData == ('a')) {
      Serial.println("Previous Song");
      mp3.previous();
    } else if (serialData == ('s')) {
      Serial.println("Pause");
      mp3.pause();
    } else if (serialData == ('d')) {
      Serial.println("Next Song");
      mp3.next();
    } else if (serialData == ('x')) {
      Serial.println("Stop");
      mp3.stop();
    } else if (serialData == ('r')) {
      Serial.println("Random");
      mp3.randomAll();
    } else if (serialData == ('e')) {
      nsong = (int)(((Serial.readString()).toInt()));
      Serial.print("Play Song Number");
      Serial.println(nsong);
      mp3.play(nsong);
    } else if (serialData == ('c')) {
      v = (int)(((Serial.readString()).toInt()));
      Serial.print("Set Volume (Max 30) to ");
      Serial.println(v);
      mp3.volume(v);
    }
  }
 
}
