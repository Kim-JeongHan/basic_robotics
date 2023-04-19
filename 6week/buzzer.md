# buzzer
부저내의 판이 수축과 확장을 하면서 공기를 진동시켜서 소리 발생
진동수에 따라 다른 소리가 발생한다.

## Hardware Structrue
---
부저는 + - 가 표시되어 있다.  

### digiwalWrite method
```
int Buzzer_pin = 5;

void setup(){
    pinMode(Buzzer_pin, OUTPUT);
}

void loop(){
    digitalWrite(Buzzer_pin, HIGH);
    delay(1000);
    digitalWrite(Buzzer_pin, LOW);
    delay(1000);
}

```

### tone method
```
int Buzzer_pin = 5;

#define C 262
#define D 294
#define E 330
#define F 349
#define G 392
#define A 440
#define B 494

void setup(){
    int tempo = 500;
    int notes[] = {C,D,E,F,G,A,B};
    int nsize = sizeof(notes)/sizeof(notes[0]);

}

void loop(){
    for(int i=0; i<nsize; i++){
        tone(Buzzer_pin, notes[i], tempo);
        delay(500);
    }
    noTone(Buzzer_pin);
    delay(1000);
}
```
