#include <SoftwareSerial.h>

SoftwareSerial rfSerial(2, 3);  // YUL262RTX 모듈을 연결할 핀 번호

void setup() {
  rfSerial.begin(9600);  // YUL262RTX 모듈과의 시리얼 통신 초기화
  Serial.begin(9600);     // 아두이노의 기본 시리얼 포트와의 통신 초기화
}

int number = 0;

void loop() {
  // 라즈베리 파이로 숫자 송신
  rfSerial.write(number);

  // 라즈베리 파이로부터 숫자 수신
  if (rfSerial.available() > 0) {
    int receivednumber = rfSerial.read();
    if (receivednumber > number) {
      number = receivednumber;
    }
  }

  // 숫자 출력 (아두이노의 시리얼 모니터에 출력)
  Serial.print("Received number: ");
  Serial.println(number);

  // 숫자 1 증가
  number++;
  delay(1000);
}


