#include <iostream>


int LED_PIN = 9; 
int sw = 5;
bool flag=0;

void setup()
{
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
    pinMode(sw, INPUT_PULLUP);
}

void loop()
{
    if(digitalRead(sw)==LOW)
    {   
        flag=1;
        digitalWrite(LED_PIN, HIGH);
        delay(300);
        digitalWrite(LED_PIN, LOW);
    }
    else
    {
        if(flag==1)
        {
            if(digtalRead(sw)==LOW)
            {
            digitalWrite(LED_PIN, HIGH);
            }
        }
        else
        {
            digitalWrite(LED_PIN, LOW);
        }
        flag=0;
    }

}