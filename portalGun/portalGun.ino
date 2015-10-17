// Code to control a Rick and Morty Portal Gun

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include <ClickEncoder.h>
#include <TimerOne.h>

// Set up our LED display
Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();
char displayBuffer[4];
uint8_t dimensionLetter='A';

// Set up the click encoder
ClickEncoder *encoder;
int16_t last, value;

// Comment this line to make the encoder increment in the opposite direction
#define reverseEncoderWheel



void timerIsr() {
  encoder->service();
}

void setup() {
  encoderSetup();
  alpha4.begin(0x70);  // pass in the address for the LED display
  
  //uncomment this to make the display run through a test at startup
  //displayTest();

}

void encoderSetup(){
  
  // set up encoder
  // unfortunately these Pins are hard coded.
    encoder = new ClickEncoder(A1, A0, A2, 4);
    //encoder = new ClickEncoder(encoderPinA, encoderPinB, encoderButtonPin, stepsPerNotch);
    encoder->setAccelerationEnabled(true);
  
    Timer1.initialize(1000);
    Timer1.attachInterrupt(timerIsr); 
    last = -1;
    value = 137;
  
}


void updateDimension(){
  #ifdef reverseEncoderWheel
  value -= encoder->getValue();
  #endif
  
  #ifndef reverseEncoderWheel
  value += encoder->getValue();
  #endif
  
  if (value != last) {
    if (value > 999){
      value = 0;
      if (dimensionLetter == 'Z') {
        dimensionLetter = 'A';
      } else {
        dimensionLetter ++;
      }
    } else if ( value < 0 ) {
      value = 999;
      if (dimensionLetter == 'A') {
        dimensionLetter = 'Z';
      } else {
        dimensionLetter --;
      }
    }
    last = value;
  }
  
  sprintf(displayBuffer, "%03i", value);
  alpha4.clear();
  alpha4.writeDigitAscii(0, dimensionLetter);
  alpha4.writeDigitAscii(1, displayBuffer[0]);
  alpha4.writeDigitAscii(2, displayBuffer[1]);
  alpha4.writeDigitAscii(3, displayBuffer[2]);
  alpha4.writeDisplay();
}

void loop() {
  ClickEncoder::Button b = encoder->getButton();
  switch (b) {
    case ClickEncoder::Held:
      alpha4.clear();
      alpha4.writeDigitAscii(0, 'H');
      alpha4.writeDigitAscii(1, 'E');
      alpha4.writeDigitAscii(2, 'L');
      alpha4.writeDigitAscii(3, 'D');
      alpha4.writeDisplay();
    break;
    case ClickEncoder::DoubleClicked:
      dimensionLetter = 'C';
      value = 137;
    break;
    case ClickEncoder::Open:
      updateDimension();
    break;
  }
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
