//Libraries
#include <dht.h>
#include "Wire.h" 
#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

dht DHT;

#define DHT11_PIN 2

//Leds
int led1Pin = 10;
int led2Pin = 9;

//buttons
int switch1Pin = 8;
int switch2Pin = 7;

//For button 1
int val;
int val2;

//For button 2
int val3;
int val4;

int buttonState;
int button2State;
int lightMode = 0;

void setup() {
  //
  pinMode(switch1Pin, INPUT);
  pinMode(switch2Pin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  buttonState = digitalRead(switch1Pin);
  button2State = digitalRead(switch2Pin);
  Serial.begin(9600);
  
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
}

void loop() { 
  //Red button turns on green Led
  val = digitalRead(switch1Pin);
  val2 = digitalRead(switch1Pin);

  if(val != buttonState)
  {
    val = digitalRead(switch1Pin);
    delay(10);
    val2 = digitalRead(switch1Pin);
    if(val == val2)
    {
      if(val == LOW)
      {
        if(lightMode == 0)
        {
          lightMode = 1;
          digitalWrite(led1Pin, HIGH);
          //Print temperture and humidity to serial monitor and lcd 
          int chk = DHT.read11(DHT11_PIN);
          Serial.print("Temperature = ");
          Serial.println(DHT.temperature);
          Serial.print("Humidity = ");
          Serial.println(DHT.humidity);
          lcd.setCursor(0,0); 
          lcd.print("Temp: ");
          lcd.print(DHT.temperature);
          lcd.print((char)223);
          lcd.print("C");
          lcd.setCursor(0,1);
          lcd.print("Humidity: ");
          lcd.print(DHT.humidity);
          lcd.print("%");
        }
        else
        {
          lightMode = 0;
          digitalWrite(led1Pin, LOW);
          lcd.clear();
        }
      }
    }
  }
  buttonState = val;
  
  //Blue button turns on yellow Led
  val3 = digitalRead(switch2Pin);
  val4 = digitalRead(switch2Pin);

  if(val3 != button2State)
  {
    val3 = digitalRead(switch2Pin);
    delay(10);
    val4 = digitalRead(switch2Pin);
    if(val3 == val4)
    {
      if(val3 == LOW)
      {
        if(lightMode == 0)
        {
          lightMode = 1;
          digitalWrite(led2Pin, HIGH);
          //Print temperture and humidity to serial monitor and lcd 
          int chk = DHT.read11(DHT11_PIN);
          Serial.print("Temperature = ");
          Serial.println(DHT.temperature);
          Serial.print("Humidity = ");
          Serial.println(DHT.humidity);
          lcd.setCursor(0,0); 
          lcd.print("Temp: ");
          lcd.print(DHT.temperature);
          lcd.print((char)223);
          lcd.print("C");
          lcd.setCursor(0,1);
          lcd.print("Humidity: ");
          lcd.print(DHT.humidity);
          lcd.print("%");
          }
        else
        {
          lightMode = 0;  
          digitalWrite(led2Pin, LOW);
          lcd.clear();
        }
      }
    }
  }
  button2State = val3;
}
