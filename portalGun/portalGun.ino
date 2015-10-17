// Code to control a Rick and Morty Portal Gun

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include <ClickEncoder.h>
#include <TimerOne.h>

// Set up our LED display
Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();

// Set up the click encoder
ClickEncoder *encoder;
int16_t last, value;
// Define pins
#define encoderPinA = A1
#define encoderPinB = A0
#define encoderButtonPin = 4

void timerIsr() {
  encoder->service();
}

void setup() {
  //Serial.begin(9600);
  encoder = new ClickEncoder(A1, A0, A2);
  //encoder = new ClickEncoder(encoderPinA, encoderPinB, encoderButtonPin);
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr); 
  last = -1;
  
  alpha4.begin(0x70);  // pass in the address
  
  
  //displayTest();

}

void encoderSetup(){
  
  // set up encoder
  
  
}

void displayTest() {
  
  alpha4.writeDigitRaw(3, 0x0);
  alpha4.writeDigitRaw(0, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);
  alpha4.writeDigitRaw(0, 0x0);
  alpha4.writeDigitRaw(1, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);
  alpha4.writeDigitRaw(1, 0x0);
  alpha4.writeDigitRaw(2, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);
  alpha4.writeDigitRaw(2, 0x0);
  alpha4.writeDigitRaw(3, 0xFFFF);
  alpha4.writeDisplay();
  delay(200);
  
  alpha4.clear();
  alpha4.writeDisplay();

  // display every character, 
  for (uint8_t i='!'; i<='z'; i++) {
    alpha4.writeDigitAscii(0, i);
    alpha4.writeDigitAscii(1, i+1);
    alpha4.writeDigitAscii(2, i+2);
    alpha4.writeDigitAscii(3, i+3);
    alpha4.writeDisplay();
    delay(300);
  }
}

void loop() {
  
  value += encoder->getValue();
  
  if (value != last) {
    last = value;
    //Serial.print("Encoder Value: ");
   // Serial.println(value);
  }
  
  ClickEncoder::Button b = encoder->getButton();
  //if (b != ClickEncoder::Open) {
   // Serial.print("Button: ");
    //#define VERBOSECASE(label) case label: Serial.println(#label); break;
    switch (b) {
     //VERBOSECASE(ClickEncoder::Pressed);
      //VERBOSECASE(ClickEncoder::Held)
      //VERBOSECASE(ClickEncoder::Released)
      //VERBOSECASE(ClickEncoder::Clicked)
      case ClickEncoder::Open:
          alpha4.writeDigitAscii(0, 'O');
          alpha4.writeDigitAscii(1, 'P');
          alpha4.writeDigitAscii(2, 'E');
          alpha4.writeDigitAscii(3, 'N');
          alpha4.writeDisplay();
      break;
      case ClickEncoder::Held:
          alpha4.writeDigitAscii(0, 'H');
          alpha4.writeDigitAscii(1, 'E');
          alpha4.writeDigitAscii(2, 'L');
          alpha4.writeDigitAscii(3, 'D');
          alpha4.writeDisplay();
      break;
      case ClickEncoder::DoubleClicked:
          alpha4.writeDigitAscii(0, 'c');
          alpha4.writeDigitAscii(1, 'c');
          alpha4.writeDigitAscii(2, 'c');
          alpha4.writeDigitAscii(3, 'c');
          alpha4.writeDisplay();
          //Serial.println("ClickEncoder::DoubleClicked");
          encoder->setAccelerationEnabled(!encoder->getAccelerationEnabled());
         // Serial.print("  Acceleration is ");
          //Serial.println((encoder->getAccelerationEnabled()) ? "enabled" : "disabled");
        break;
    }
  //}    
}
