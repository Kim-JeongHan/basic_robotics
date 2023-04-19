int LED_PIN = 9;
ind sw = 10;
int Potetiometer = A1;

void setup(){
    pinMode(LED_PIN, OUTPUT);
    pinMode(sw, INPUT_PULLUP);
}

void loop(){
    if(digitalRead(sw)==HIGH)
    {
        digitalWrite(LED_PIN, HIGH);
    }
    else
    {
        int val = analogRead(Potetiometer);
        val = map(val, 0, 1023, 0, 255);
        analogWrite(LED_PIN, val);
    }
}