#include <iostream>


int LED_PIN = 9; 
int sw = 5;
int number=0;
bool sw_state=false;
bool last_sw_state=false;

void setup()
{
    pinMode(LED_PIN, OUTPUT);
    pinMode(sw, INPUT_PULLUP);
}

void loop()
{
    sw_state = digitalRead(sw);
    if(sw_state != last_sw_state)
    {
        number++
    }
    if(sw_state==HIGH || last_sw_state==HIGH)
    {
        digitalWrite(LED_PIN, HIGH);
    }
    else
    {
        if(number%2==0)
        {
            digitalWrite(LED_PIN, HIGH);
        }
        else
        {
            digitalWrite(LED_PIN, LOW);
        }
    }
    last_sw_state = sw_state;

}