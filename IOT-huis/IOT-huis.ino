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
}
