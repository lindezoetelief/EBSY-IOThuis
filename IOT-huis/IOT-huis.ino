#include <dht.h>
#include <LiquidCrystal.h>
dht DHT;

#define DHT11_PIN 2

LiquidCrystal lcd(I2C_1);
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
  lcd.begin(16, 2);
  lcd.print("hello, world!");
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
        }
        else
        {
          lightMode = 0;
          digitalWrite(led1Pin, LOW);
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
        }
        else
        {
          lightMode = 0;  
          digitalWrite(led2Pin, LOW);
        }
      }
    }
  }
  button2State = val3;

  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);

  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  delay(1000);
}
