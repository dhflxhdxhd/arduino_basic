#include <SoftwareSerial.h>
SoftwareSerial HM10(2,3);
int LED = 9;

void setup(){
  //시리얼 시작
  Serial.begin(9600);
  Serial.println("AT 명령어를 쳐보세요:");
  
  //블루투스 시리얼 포트 시작
  HM10.begin(9600);

  //LED핀 설정
  pinMode(LED,OUTPUT);
  }

void loop(){
  if (HM10.available()){           //HM10이 작동할때 
    char c =(char)HM10.read();     //char = 문자 값을 저장하는 1바이트 메모리를 차지하는 자료형입니다    
    Serial.print(c);               //시리얼모니터에 내가 쓴 값을 전송합니다.
    if(c == 'a')                   // 'a'를 입력하면
      digitalWrite(LED, HIGH);     // LED가 on
    if(c == 'b')                   // 'b'를 입력하면
      digitalWrite(LED, LOW);      // LED가 off    
  }
  
  //시리얼 모니터에서 HM-10으로 데이터 쓰기
  if(Serial.available()){
    char c = (char)Serial.read();
    HM10.print(c);
  }
}
