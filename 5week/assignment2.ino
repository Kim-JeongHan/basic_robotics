#include <iostream>


int LED_PIN = 9; 
int sw = 5;
bool flag=0;

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(sw, INPUT_PULLUP);
}

void loop()
{
    if(digitalRead(sw) == LOW)
    {
        int flag == 1;
        digitalWrite(LED_PIN, HIGH);
        delay(300);
        digitalWrite(LED_PIN, LOW);
    }
    else
    {
        if(flag==0)
        {
            digitalWrite(LED_PIN, LOW);
            if(digitalRead)
        }
        else(flag==1)
    }

}