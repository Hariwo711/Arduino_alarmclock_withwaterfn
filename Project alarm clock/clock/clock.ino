/*  DHT11/ DHT22 Sensor Temperature and Humidity Tutorial
 *  Program made by Dejan Nedelkovski,
 *  www.HowToMechatronics.com 
 */
/*
 * You can find the DHT Library from Arduino official website
 * https://playground.arduino.cc/Main/DHTLib
 */

#include <Wire.h>               //forliquid display wire
#include <LiquidCrystal_I2C.h>  // includes the LiquidCrystal Library
LiquidCrystal_I2C lcd(0x27, 20, 4);
#include <dht.h>  //temp and humitity sensor
#include <Servo.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>
#include "pitches.h"

byte clockChar[] = {B00000, B01110, B10101, B10101, B10111, B10001, B01110, B00000};
byte alarmChar[] = {B00100, B01110, B01110, B01110, B11111, B00000, B00100, B00000};
byte dateChar[] = {B11111, B00000, B01100, B01010, B01010, B01100, B00000, B11111};
byte alarmoffChar[] = {B11111, B11011, B10001, B10001, B10001, B00000, B11011, B11111};
byte specialChar[] = {
  B00000,
  B00000,
  B00100,
  B00100,
  B00100,
  B00100,
  B11111,
  B11011
};


#define BUZZER_PIN 4


ThreeWire myWire(8, 7, 9);  // DAT, CLK, RST

RtcDS1302<ThreeWire> Rtc(myWire);

dht DHT;  //setting up humittity sensor
#define dataPin 6 //tempandhumit sensor

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
const int ledPin = 13;
const int buttonPin1 = 10;
const int buttonPin2 = 11;
const int buttonPin3 = 12;
const int buzzer = 4;

int buttonState = 0;
int mode = 0;
int relaymode = 0;
int setalarmmode = 0;
int alarmonoroff = 0;
int bigmode = 0;

int selectedsong = 0;
//alarm intergers
int alarmhour = 14;
int alarmminute = 05;

int easteregg = 0;

int timehour = 0;
int timeminute = 0;
int timesecond = 0;
int turnoffalarm = 0;

Servo myservo;

void setup() {
  Serial.begin(9600);
  lcd.init();  // initialize the lcd
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();  // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  // initialize the LED pin as an output:

  lcd.createChar(0, clockChar);
  lcd.createChar(1, alarmChar);
  lcd.createChar(2, dateChar);
  lcd.createChar(3, alarmoffChar);
  lcd.createChar(4, specialChar);

  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);

  pinMode(buzzer, OUTPUT);

  myservo.attach(5);
  myservo.write(180);
}


void loop() {    
    button();
 if (alarmonoroff == 0){
    digitalWrite(buzzer, LOW);
  }

  // digitalWrite(buzzer , LOW);
  // Serial.print("Set alarm is:");
  // Serial.print(alarmhour);
  // Serial.print(":");
  // Serial.println(alarmminute);  
  
  // String p1 = " : ";
  // Serial.println(timehour + p1 + timeminute); //testing if correct time is get
  // Serial.println(timesecond);
//  Serial.println(alarmonoroff);

  if (setalarmmode == 0){
  timeget();

  if (mode == 0){
    defaultalarm_screen();
    } 
  if (mode == 1) {
    humitity();
   }
  if (mode == 2) {
    temp();
    }

  }  
  if (easteregg == 1){
    test();
  } 

  if (setalarmmode == 1) {
    setalarm();
    // test();
  }
  if (setalarmmode == 2){
    songsselect();
  }

  if (alarmonoroff == 1 && setalarmmode == 0){//setting up buzzer and water
    if (timeminute == alarmminute && timehour == alarmhour){
      // alarm();
      if(selectedsong==0){
        alarm();
      }
      if(selectedsong==1){
        songplayer_nokia();
      }
      if(selectedsong==2){
        songplayer_pacman();
      }
        
      
      
          if (timesecond >= 30){
              if ((timesecond% 2) == 0){
                  myservo.write(180);
                }
              else{
                  waterspray();
                  } 
    }
  }
  if (alarmonoroff == 0){
    digitalWrite(buzzer, LOW);
  }
  // if (timeminute == alarmminute+1 && timehour == alarmhour){
  //     if ((timesecond% 2) == 0){
  //         myservo.write(180);
  //         digitalWrite(buzzer , LOW);
  //     }
  //     else{
  //       waterspray();
  //     }     
  // }
  // turnoffalarm = 0;
  // Serial.println(turnoffalarm);
  // Serial.print("Button Mode is");
  // Serial.println(mode);
  // change_alarm();
}
}

void timeget() {
  RtcDateTime now = Rtc.GetDateTime();
  // lcd.setCursor(0, 0);
  // lcd.print("Press Button");

  lcd.setCursor(0, 1);
  printDateTime(now);
}

void humitity() {
  int readData = DHT.read11(dataPin);
  float h = DHT.humidity;
  lcd.setCursor(0, 0);
  lcd.print("Humi.: ");
  lcd.print(h);
  lcd.print(" %     ");
  // delay(2000);
}
void temp() {
  int readData = DHT.read11(dataPin);
  float t = DHT.temperature;
  lcd.setCursor(0, 0);   // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Temp.: ");  // Prints string "Temp." on the LCD
  lcd.print(t);          // Prints the temperature value from the sensor
  lcd.print(" C      ");
}

void test() { 
  lcd.setCursor(0, 0);
  lcd.print("EASTER EGG");
  lcd.setCursor(0, 1);
  lcd.write(0);lcd.write(1);lcd.write(2);lcd.write(3);lcd.write(4);lcd.write(4);lcd.write(4);
}

void defaultalarm_screen(){
  lcd.setCursor(0,0);
  lcd.print("alarm is: ");
  if (alarmonoroff == 1){
    lcd.print("ON  ");
    lcd.write(1);
  }
  if (alarmonoroff == 0){
    lcd.print("OFF ");
    lcd.write(1);
  }
}

void setalarm(){
  lcd.setCursor(0,0);
  lcd.print("Please set alarm");
  lcd.setCursor(0,1);
  lcd.print(">> ");
  if (alarmhour < 10){
  lcd.print("0");
  }
  lcd.print(alarmhour);
  lcd.print(" : ");
  if (alarmminute < 10){
  lcd.print("0");    
  }
  lcd.print(alarmminute);

}


void alarm() {
  
  if ((timesecond% 2) == 0){
    digitalWrite(buzzer , HIGH);
  }
  else{
    digitalWrite(buzzer , LOW);
  }

}

void waterspray(){
  myservo.write(90);
  delay(1000); 
}
void button() {
  if (setalarmmode==0){
      // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (digitalRead(buttonPin2) == HIGH) {
      mode = mode + 1;
      delay(200);
      Serial.print("Mode is");
      Serial.println(mode);
    }
    if (mode == 3){
      mode = 0;
      lcd.clear();  
    }






    if (relaymode == 2){
      relaymode =0 ;
      Serial.print("RelayMode is");
      Serial.println(relaymode);
    }


    if (digitalRead(buttonPin3)== HIGH){
      alarmonoroff++;
      delay(200);
   }
    if (alarmonoroff == 2){
      alarmonoroff =0 ;
    } 
  }
    if (digitalRead(buttonPin1)== HIGH){
      setalarmmode++;
      delay(200);
      lcd.clear();
    }

    if (setalarmmode == 3){
      setalarmmode = 0;
    }
  if (setalarmmode == 1){
    if (digitalRead(buttonPin3)== HIGH){
    alarmhour++;
    delay(200);
  }
    if (alarmhour == 24){
    alarmhour = 0;
  }
  
    if (digitalRead(buttonPin2)== HIGH){
      alarmminute++;
      delay(200);
  }
    if (alarmminute == 60){
      lcd.clear();
      alarmminute = 0;
  }

  }

  // if(digitalRead(buttonPin2)== HIGH){
  //   easteregg = 1;
  // }

  if(setalarmmode == 2){
    if(selectedsong == 3){
      selectedsong = 0;
      lcd.clear();
    }
    if(digitalRead(buttonPin2)==HIGH){
      selectedsong++;
      delay(200);
      Serial.println(selectedsong);
    }
  }

}



#define countof(a) (sizeof(a) / sizeof(a[0]))

void printDateTime(const RtcDateTime& dt) {
  char datestring[20];

  snprintf_P(datestring,
             countof(datestring),
             PSTR("%02u/%02u %02u:%02u:%02u    "),
             dt.Day(),
             dt.Month(),
             dt.Hour(),
             dt.Minute(),
             dt.Second());
  timehour = dt.Hour();
  timeminute = dt.Minute();
  timesecond = dt.Second(); //if needed
  lcd.print(datestring);
}


