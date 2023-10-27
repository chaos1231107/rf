#include <SoftwareSerial.h>

SoftwareSerial rfSerial(2, 3);  

void setup() {
  rfSerial.begin(2000000);  
  Serial.begin(2000000);     
}

int number = 0;

void loop() {

  rfSerial.write(number);
  Serial.print("Received number: ");
  Serial.println(number);
  number++;

  // 라즈베리 파이로부터 숫자 수신
  if (rfSerial.available() > 0) {
    int receivednumber = rfSerial.read();
    if (receivednumber > number) {
      number = receivednumber;
    }
  }

  delay(100);
}


