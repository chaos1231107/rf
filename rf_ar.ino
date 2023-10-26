#include <SoftwareSerial.h>

SoftwareSerial rfSerial(2, 3);  

void setup() {
  rfSerial.begin(9600);  
  Serial.begin(9600);     
}

int number = 0;

void loop() {

  rfSerial.write(number);

  // 라즈베리 파이로부터 숫자 수신
  if (rfSerial.available() > 0) {
    int receivednumber = rfSerial.read();
    if (receivednumber > number) {
      number = receivednumber;
    }
  }

  
  Serial.print("Received number: ");
  Serial.println(number);

 
  number++;
  delay(1000);
}


