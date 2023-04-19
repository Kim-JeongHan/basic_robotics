# sound sensor
소리가 감지하게 되면 진동판이 떨려서 고정 전극판에 자극이 생기면서 전압에 영향을 준다.


## Hardware structure
---
`vcc` : 5v

`GND` : ground

`OUT` : analog PIN

```
int Sound_pin = A5;

void setup(){
    pinMode(sound, INPUT);
    Serial.begin(9600);
}

void loop(){
    int sensorValue = analogRead(sound);
    Serial.println(sensorValue);
    delay(100);
}