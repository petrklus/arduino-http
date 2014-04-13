#include <SmoothAnalogInput.h>

SmoothAnalogInput smooth_A0;
SmoothAnalogInput smooth_A1;
SmoothAnalogInput smooth_A2;
SmoothAnalogInput smooth_A3;
SmoothAnalogInput smooth_A4;
SmoothAnalogInput smooth_A5;

void setup(){
  // not DRY but does not matter..
  smooth_A0.attach(A0);
  smooth_A1.attach(A1);
  smooth_A2.attach(A2);
  smooth_A3.attach(A3);  
  smooth_A4.attach(A4);  
  smooth_A5.attach(A5);    
  Serial.begin(19200);
  Serial.println("NODE ACTIVE");
}

unsigned long last_sent = 0;
int INTERVAL_millis = 1000;
void loop(){  
  int readingA0 = smooth_A0.read();
  int readingA1 = smooth_A1.read();
  int readingA2 = smooth_A2.read();
  int readingA3 = smooth_A3.read();
  int readingA4 = smooth_A4.read();  
  int readingA5 = smooth_A5.read();

  if (millis() - last_sent > INTERVAL_millis) {
    Serial.print("[[");
    Serial.print(readingA0); Serial.print(";");
    Serial.print(readingA1); Serial.print(";");
    Serial.print(readingA2); Serial.print(";");
    Serial.print(readingA3); Serial.print(";");
    Serial.print(readingA4); Serial.print(";");  
    Serial.print(readingA5); Serial.print(";");    
    Serial.println("]]");    
    last_sent = millis();
  }

  delay(100); //just here to slow down the output for easier reading
}
