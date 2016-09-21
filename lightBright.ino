#include "animations.h"
#include "led.h"

boolean transmitDataComplete = false;
int irInput = 0;

int colorChange = 0; // 0-r 1-g 2-b
int numColors;

const int colorDim = 3;

// keep these synced with the led matrix below.
const int matrixHeight = 2, matrixWidth = 2;
led leds[][matrixHeight] = {
  {led(11),led(8)},
  {led(5),led(2)}
};


void setup() {
  Serial.begin(9600);
  numColors = (sizeof(colors) / sizeof(int[colorDim]));
}

void loop() {
  if (transmitDataComplete) {
    transmitDataComplete = false;
    Serial.println(irInput);
    int xInput, yInput;
    switch(irInput) {
      case 1:
        xInput = 0;
        yInput = 0;
        break;
      case 2:
        xInput = 1;
        yInput = 0;
        break;
      case 4:
        xInput = 0;
        yInput = 1;
        break;
      case 5:
        xInput = 1;
        yInput = 1;
        break;
    }
  
  leds[xInput][yInput].setColor(colors[leds[xInput][yInput].indexOfColor++]);
  leds[xInput][yInput].indexOfColor %= 8;
  }
  
  //display the led's
  for (int x = 0; x < matrixWidth; ++x) {
    for (int y = 0; y < matrixHeight; ++y) {
      //colorChange++;
      //get the button input for changing to the next color on the current pin
      //colorChange = (colorChange + digitalRead(colorPin)) % numColors;

      
      leds[x][y].paintRGBLed();
    }
  }
  //Serial.println(colorChange);

  //we should use LCM of the tasks that we have, so we currently have
  //display and input
  //for timer in 0 to 250
  //  if timer % 50 = 0
  //    trigger display
  //   trigger input
  //delay(10)
}

void serialEvent() {
  int internalInput = -1;
  while (Serial.available()) {
    // get the new byte:
    internalInput = Serial.parseInt();
    if( internalInput > 0 ) {
      irInput = internalInput - 1;
      transmitDataComplete = true;
    }
  }
}


