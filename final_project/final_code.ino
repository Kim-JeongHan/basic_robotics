#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <IRremote.h>
#include <DS1302.h>

//soundChecker
#define Sound A2
#define sw 1

//VR
#define clockpinR 8  //yellow
#define latchpinR 9  //orange
#define datapinR 10
#define clockpinB 11
#define latchpinB 11  //orange
#define datapinB 13
#define reg A0  //green

//water
#define piezo 6
#define water_pin A1

//tiltCount
#define tilt 7

//multiplyGame
#define receiverPin 2


//IR, LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);
IRrecv irrecv(receiverPin);

//sounde check
int bigsound_number = 0;

long rd = random(0, 5);
int timernumber;
int VR_num = 0;

//timer
DS1302 rtc(5, 4, 3);

int mission = 0;
//df
bool Creation_quiz = false;
int num1, num2;
int order = 1;
decode_results results;
int Ten, zero;
//system setup
bool clear;
int loopCount = 0;

void setup() {
  //serial
  Serial.begin(9600);

  //soundChecker
  pinMode(Sound, INPUT);
  pinMode(sw, INPUT_PULLUP);

  //VR
  pinMode(latchpinR, OUTPUT);
  pinMode(clockpinR, OUTPUT);
  pinMode(clockpinB, OUTPUT);
  pinMode(latchpinB, OUTPUT);
  pinMode(datapinR, OUTPUT);
  pinMode(datapinB, OUTPUT);
  digitalWrite(latchpinB, LOW);
  digitalWrite(latchpinR, LOW);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  long rd = random(0, 5);
  int VR_num = 0;

  irrecv.enableIRIn();

  //piezo
  pinMode(piezo, OUTPUT);

  //timer
  //rtc.setTime(13, 30, 10);
  //rtc.setDate(13, 06, 2023);

  timernumber = 0;
}

int getEnteredNumber(int receivedValue) {
  int enteredNumber = 0;

  switch (receivedValue) {
    case 0xFF30CF: enteredNumber = 1; break;
    case 0xFF18E7: enteredNumber = 2; break;
    case 0xFF7A85: enteredNumber = 3; break;
    case 0xFF10EF: enteredNumber = 4; break;
    case 0xFF38C7: enteredNumber = 5; break;
    case 0xFF5AA5: enteredNumber = 6; break;
    case 0xFF42BD: enteredNumber = 7; break;
    case 0xFF4AB5: enteredNumber = 8; break;
    case 0xFF52AD: enteredNumber = 9; break;
    case 0xFF6897:
      enteredNumber = 0;
      break;
      // 다른 리모컨 버튼에 대한 처리 추가 가능
  }

  return enteredNumber;
}

void QuizDisplay(int &num1, int &num2) {
  lcd.clear();
  num1 = random(2, 10);
  num2 = random(2, 10);
  lcd.setCursor(1, 0);
  lcd.print(num1);
  lcd.print(" * ");
  lcd.print(num2);
  lcd.print(" = ");
  lcd.setCursor(1, 1);
  lcd.print("Answer is ");
  Creation_quiz = true;
}

void multiplyGame() {
  if (!Creation_quiz) {
    QuizDisplay(num1, num2);
  }
  if (order == 1) {
    Serial.println("order==1");
    if (irrecv.decode(&results)) {
      Serial.println("fsfmsldmksdkls");
      Serial.println(results.value);
      Ten = getEnteredNumber(results.value);
      irrecv.resume();
      lcd.setCursor(11,1);
      lcd.print(Ten);
      order++;
    }
  } else if (order == 2) {
    if (irrecv.decode(&results)) {
      zero = getEnteredNumber(results.value);
      irrecv.resume();
      lcd.print(zero);
      order++;
    }
  } else {
    if (num1 * num2 == 10 * Ten + zero) {
      lcd.clear();
      lcd.print("Correct");
      delay(500);
      lcd.clear();
      lcd.print("Correct");
      delay(500);
      lcd.clear();
      lcd.print("Correct");
      delay(500);
      Creation_quiz = false;
      mission=0;
      digitalWrite(piezo, LOW);
      order = 1;

    } else {
      lcd.clear();
      lcd.print("Discorrect");
      delay(500);
      lcd.clear();
      lcd.print("Discorrect");
      delay(500);
      lcd.clear();
      lcd.print("Discorrect");
      delay(500);
      Creation_quiz = false;
      order = 1;
    }
  }
  delay(500);
}
void twinkl0B(int a) {
  digitalWrite(latchpinB, LOW);
  shiftOut(datapinB, clockpinB, MSBFIRST, a);
  digitalWrite(latchpinB, HIGH);
  delay(5);
}

void twinkl0R(int a) {
  digitalWrite(latchpinR, LOW);
  shiftOut(datapinR, clockpinR, MSBFIRST, a);
  digitalWrite(latchpinR, HIGH);
  delay(5);
}

void twinkl1(int a) {
  twinkl0B(3 << a);
  twinkl0R(3 << a);
}

void twinkl2(int a) {
  twinkl0B(192 >> a);
  twinkl0R(192 >> a);
}

void twinkle() {
  for (int i = 0; i <= 8; i += 1) {
    twinkl0B(170);
    twinkl0R(85);
    delay(200);

    twinkl0B(85);
    twinkl0R(170);
    delay(200);
  }
  twinkl0B(1);
  twinkl0R(1);
  twinkl0B(0);
  twinkl0R(0);

  delay(100);

  for (int i = 0; i <= 5; i += 1) {
    twinkl1(i);
    delay(100);
  }
  for (int i = 0; i <= 7; i += 1) {
    twinkl2(i);
    delay(100);
  }
}

void VR() {
  int VR_val = analogRead(reg);
  VR_val = map(VR_val, 0, 1023, 0, 5);

  digitalWrite(latchpinB, LOW);
  shiftOut(datapinB, clockpinB, MSBFIRST, 1 << rd);
  digitalWrite(latchpinB, HIGH);
  delay(5);


  digitalWrite(latchpinR, LOW);
  shiftOut(datapinR, clockpinR, MSBFIRST, 1 << VR_val);
  digitalWrite(latchpinR, HIGH);

  if (rd == VR_val) {
    Serial.println("complit");
    rd = random(0, 5);
    VR_num += 1;
    delay(1000);
  }
  if (VR_num == 3) {
    digitalWrite(latchpinB, LOW);
    shiftOut(datapinB, clockpinB, MSBFIRST, 0);
    digitalWrite(latchpinB, HIGH);



    digitalWrite(latchpinR, LOW);
    shiftOut(datapinR, clockpinR, MSBFIRST, 0);
    digitalWrite(latchpinR, HIGH);
    ++mission;
    clear = true;
  }
  // delay(2000);
}


void water() {
  int water = analogRead(water_pin);  // 수분 수위 감지 센서에서 값을 읽어옴
  water = map(water, 0, 700, 5, 0);
  twinkl0B(1 << water);
  delay(5);
  if (water == 0) {
    ++mission;
    clear = true;
  }
}

void soundChecker() {
  bool buttonState = (digitalRead(sw) != HIGH);
  int soundValue = analogRead(Sound);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("volume : ");
  lcd.print(soundValue);
  if (buttonState == 1 && soundValue > 500 && bigsound_number < 5) {
    lcd.clear();
    lcd.print("stage ");
    bigsound_number++;
    lcd.print(bigsound_number);
    delay(1000);
  }
  if (bigsound_number == 2) {
    lcd.clear();
    lcd.print("mission clear!");
    delay(1000);
    bigsound_number = 0;
    mission++;
    clear = true;
    lcd.clear();
  }
  delay(500);
}


void tiltCount() {
  lcd.setCursor(0,0);
  lcd.print("tilt game start");
  if (loopCount < 5) {
    int a = digitalRead(tilt);
    if (a == HIGH) {
      lcd.setCursor(0, 1);
      lcd.print("tilt number : ");
      loopCount++;
      lcd.print(loopCount);
      delay(1000);
    }
  } else if (loopCount == 5) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("mission clear!");
    delay(1000);
    loopCount = 0;
    mission++;
    clear = true;
  }
  delay(1);
}

void buzzerStart() {
  
}






void timer() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(rtc.getDOWStr());
  lcd.setCursor(3, 1);
  lcd.print(rtc.getDateStr());
  lcd.setCursor(8, 0);
  lcd.print(rtc.getTimeStr());
  delay(1000);
  timernumber++;
  if (timernumber == 10) {
    mission++;
  }
}

void loop() {
  buzzerStart();
  if (clear) {
    twinkle();
    clear = false;
  }
  if (mission == 0) timer();
  else if (mission == 1) 
  {
    digitalWrite(piezo, HIGH); 
    soundChecker(); 
  }
  else if (mission == 2) VR();
  else if (mission == 3) water();
  else if (mission == 4) tiltCount();
  else if (mission == 5) {
    multiplyGame();
  }
}