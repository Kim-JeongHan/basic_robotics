#define Sound A5
#define sw 8

#define C 262
#define D 294
#define E 330
#define F 349
#define G 392
#define A 440
#define B 494

int tempo = 500;
int notes[] = {C,D,E,F,G,A,B};
int nSize = sizeof(notes)/sizeof(int);

int bigsound_number = 0;
int mission = 1;

void setup()
{
    pinMode(Sound, INPUT);
    pinMode(sw, INPUT_PULLUP);
    Serial.begin(9600);
}

void soundChecker()
{
    bool buttonState = (digitalRead(sw) != HIGH);
    int soundValue = analogRead(Sound);
    if(buttonState && soundValue > 500 && bigsound_number < 5)
    {
        bigsound_number++;
        delay(1000);
    }
    if(bigsound_number==5)
    {
        bigsound_number=0;
        mission++;
    }
    delay(1);
}

void loop(){

    switch(mission)
    {
    case 1:
        soundChecker();        
    case 2:
        
    case 3:

    case 4:

    case 5:

    case 6:

    }
}
