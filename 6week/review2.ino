int TILT_PIN = 10;
int LED_PIN = 9;

void setup(){
    pinMode(LED_PIN, OUTPUT);
    pinMode(TILT_PIN, INPUT);
}

void loop(){
    if(digitalRead(TILT_PIN) == HIGH){
        digitalWrite(LED_PIN, LOW);
    }
    else{
        digitalWrite(LED_PIN, HIGH);
    }
}