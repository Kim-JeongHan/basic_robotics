# tilt sensor
tilt sensor 즉, 기울기센서는 안에 있는 전도성 구가 움직이면서 스위치 역할을 해준다.
위를 향했을 때 : 전도성구가 단자 사이 연결
아래를 향했을 때 : 전류가 끊김

## Hardware Structure
---
- 극성이 존재하지 않는다.
- 저항은 10옴을 사용하자.

`한쪽 다리` : 저항 + 5V, digital Pin

`한쪽 다리` : GND

```
int tilt = 3;

void setup(){
    Serial.begin(9600);
    pinMode(tilt, INPUT);
}

void loop(){
    if(digitalRead(tilt)==HIGH)
    {
        Serial.println("straight");
        delay(2000);
    }
    else
    {
        Serial.println("Reverse");
    }
}
