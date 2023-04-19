## Hardware structure
led connect to pin 9
potetiometer connect to  pin A5


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