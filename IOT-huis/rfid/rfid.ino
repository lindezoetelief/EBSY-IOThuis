#include <SPI.h>
#include <RFID.h>
#include "Wire.h" 
#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display



RFID rfid(48,49);   //D48--RFID module SDA pinã€D49 RFID module RST pin
void setup()
{
  Serial.begin(9600);
  SPI.begin();
  rfid.init();

  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Make sure backlight is on
}

void loop()
{
 //search card
  if (rfid.isCard()) {
    Serial.println("Find the card!");
   //read serial number
    if (rfid.readCardSerial()) 
    {
      lcd.setCursor(0,0);
      lcd.print("Card number:");
      lcd.setCursor(0,1);
      lcd.print(rfid.serNum[0]);
      lcd.print(".");
      lcd.print(rfid.serNum[1]);
      lcd.print(".");
      lcd.print(rfid.serNum[2]);
      lcd.print("."); 
      lcd.print(rfid.serNum[3]);
      lcd.print(".");
      lcd.print(rfid.serNum[4]);
      
      Serial.print("The card's number is  : ");
      Serial.print(rfid.serNum[0]);
         Serial.print(",");
      Serial.print(rfid.serNum[1]);
         Serial.print(",");
      Serial.print(rfid.serNum[2]);
          Serial.print(",");
      Serial.print(rfid.serNum[3]);
          Serial.print(",");
      Serial.print(rfid.serNum[4]);
      Serial.println(" ");
    }
 
    rfid.selectTag(rfid.serNum);
  }
  
  rfid.halt();
}
