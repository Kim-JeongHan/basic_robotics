## Hardware structure
led : Digital PIN

potetiometer : 오른쪽이 vcc왼쪽이 ground이다.가운데에는 analogpin을 연결


```
int LED_PIN = 9;
int Potentiometer = A5;

void setup(){
    Serial.begin(9600);
    PinMode(LED_PIN, OUTPUT);
}

void loop(){
    int val = analogRead(Potentiometer);
    val = map(val,0,1023,0,255);
    analogWrite(LED_PIN, val);
}
```