# 아두이노 가변저항(Potentiometer)

왼쪽에서 오른쪽으로 돌릴떄 저항이 감소한다. 오른쪽이 vcc왼쪽이 ground이다.가운데에는 analogpin을 연결

```
int Analog_pin = A5;
//decrease to 
 
void setup(){
    Serial.begin(9600);
}

void loop(){
    int val = analogRead(Analog_pin);
    Serial.println(val);
}
```
