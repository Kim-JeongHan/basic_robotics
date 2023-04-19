#led switch

led와 스위치를 사용해서 구성한 코드이다.

## Hardware structure
---
sw : digital Pin

LED : digital Pin

```
int LED_PIN = 9;
int sw = 8;

void setup(){
    pinMode(LED_PIN, OUTPUT);
    pinMode(sw, INPUT_PULLUP);
}

void loop(){
    if(digitalRead(sw)==LOW)
    {
        digitalWrite(sw, HIGH);
    }
    else
        digitalWrite(sw, LOW);
}
```
