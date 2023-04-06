#include <iostream>


int LED_PIN = 9; 
int sw = 5;
bool a= 0;

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
        if(a==0)
        {
            a=1;
        }
        else
        {
            a=0;
        }
    }
    if(a==1)
    {
        digitalWrite(LED_PIN, HIGH);
    }
    else
    {
        digitalWrite(LED_PIN, LOW);
    }
}