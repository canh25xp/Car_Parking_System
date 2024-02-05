#include <Servo.h>  //includes the servo library
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
const int LCD_COLUMNS = 16;
const int LCD_ROWS = 2;

LiquidCrystal_I2C lcd(0x27, LCD_COLUMNS, LCD_ROWS);

Servo myservo;

#define ir_enter 2
#define servo_pin 3
#define ir_back 4

#define trig_1 8
#define echo_1 9
#define trig_2 10
#define echo_2 11
#define trig_3 12
#define echo_3 13

#define MAX_SLOT 3
#define distanceThreshold 10


int S1 = 0, S2 = 0, S3 = 0;
int flag1 = 0, flag2 = 0;
int slot = 3;

void setup() {
  Serial.begin(9600);

  pinMode(trig_1, OUTPUT);
  pinMode(echo_1, INPUT);
  pinMode(trig_2, OUTPUT);
  pinMode(echo_2, INPUT);
  pinMode(trig_3, OUTPUT);
  pinMode(echo_3, INPUT);

  lcd.begin(LCD_COLUMNS, LCD_ROWS);
  lcd.backlight();

  myservo.attach(servo_pin);
  TestServo(myservo);
  Close(myservo);

  lcd.setCursor(0, 0);
  lcd.print("Car Parking     ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  delay(2000);
  lcd.clear();

  Read_Sensor();

  int total = S1 + S2 + S3;
  slot = MAX_SLOT - total;
}

void loop() {

  Read_Sensor();

  int total = S1 + S2 + S3;
  slot = MAX_SLOT - total;

  lcd.setCursor(0, 0);
  lcd.print("Empty Slot: ");
  lcd.print(slot);
  lcd.print("  ");

  lcd.setCursor(0, 1);
  if (S1 == 1) {
    lcd.print("S1=1");
  } else {
    lcd.print("S1=0");
  }

  lcd.setCursor(5, 1);
  if (S2 == 1) {
    lcd.print("S2=1");
  } else {
    lcd.print("S2=0");
  }

  lcd.setCursor(10, 1);
  if (S3 == 1) {
    lcd.print("S3=1");
  } else {
    lcd.print("S3=0");
  }

  // if (digitalRead(ir_enter) == 0 && flag1 == 0) {
  //   if (slot > 0) {
  //     flag1 = 1;
  //     if (flag2 == 0) {
  //       myservo.write(180);
  //       slot = slot - 1;
  //     }
  //   }
  //   else {
  //     lcd.setCursor(0, 0);
  //     lcd.print("  Parking Full  ");
  //     delay(1500);
  //   }
  // }
  //
  // if (digitalRead(ir_back) == 0 && flag2 == 0) {
  //   flag2 = 1;
  //   if (flag1 == 0) {
  //     myservo.write(180);
  //     slot++;
  //   }
  // }

  // if (flag1 == 1 && flag2 == 1) {
  //   delay(1000);
  //   myservo.write(90);
  //   flag1 = 0, flag2 = 0;
  // }

  if(digitalRead(ir_back) == 0 || digitalRead(ir_enter) == 0)
    Open(myservo);
  else
    Close(myservo);

  delay(100);
}
////////////////USER DEFINE FUNCTION///////////////

void Read_Sensor() {
  S1 = 0, S2 = 0, S3 = 0;

  if (Check(trig_1,echo_1) == 1) { S1 = 1; }
  if (Check(trig_2,echo_2) == 1) { S2 = 1; }
  if (Check(trig_3,echo_3) == 1) { S3 = 1; }
}

int Measure(uint8_t trig, uint8_t echo) {
  unsigned long duration;
  int distance;

  digitalWrite(trig, 0);
  delayMicroseconds(2);
  digitalWrite(trig, 1);
  delayMicroseconds(5);
  digitalWrite(trig, 0);

  duration = pulseIn(echo, HIGH);

  distance = int(duration / 2 / 29.412);
  return distance;
}

bool Check(uint8_t trig, uint8_t echo) {
  return (Measure(trig, echo) < distanceThreshold) ? 1 : 0;
}

void TestServo(Servo _servo){
  for(int i=0 ; i<= 180 ; i++){
    _servo.write(i);
    delay(10);
  }
}

void Close(Servo _servo){
  _servo.write(0);
}

void Open(Servo _servo){
  _servo.write(90);
}




