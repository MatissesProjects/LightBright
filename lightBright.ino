#include "animations.h"
#include "led.h"

int colorChange = 0; // 0-r 1-g 2-b
int colorPin = 122;
int numColors;

const int colorDim = 3;

int ledToEditX = 0, ledToEditY = 1;

int up, down, left, right;
int upPin = 150, downPin = 153, leftPin = 152, rightPin = 151;

int blinkTimeInitial = 50, ledBlinkSpeed = 500;

// keep these synced with the led matrix below.
const int matrixHeight = 3, matrixWidth = 3;
led leds[][matrixHeight] = {
  {led(22), led(25), led(28)},
  {led(31), led(34), led(37)},
  {led(40), led(43), led(46)}
};

void setup() {
  Serial.begin(9600);
  pinMode(colorPin, INPUT);
  pinMode(upPin, INPUT);
  pinMode(downPin, INPUT);
  pinMode(leftPin, INPUT);
  pinMode(rightPin, INPUT);
  numColors = (sizeof(colors) / sizeof(int[colorDim]));
  delay(blinkTimeInitial);
  leds[ledToEditX][ledToEditY].blinkRGBLed(blinkTimeInitial);
}

void loop() {
  //select the led to change
  //if (moveCursor()) {
  //colorChange = leds[ledToEditX][ledToEditY].indexOfColor;
  //  leds[ledToEditX][ledToEditY].blinkRGBLed(blinkTimeMS);
  //}

  //debugPrintLed();

  //getting color to set it to
  //leds[ledToEditX][ledToEditY].setColor(colors[colorChange]);
  //leds[ledToEditX][ledToEditY].indexOfColor = colorChange;

  //display the led's
  for (int x = 0; x < matrixWidth; ++x) {
    for (int y = 0; y < matrixHeight; ++y) {

      //colorChange++;
      //get the button input for changing to the next color on the current pin
      //colorChange = (colorChange + digitalRead(colorPin)) % numColors;

      leds[x][y].setColor(animation[frame][x * matrixWidth + y]);

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
  delay(ledBlinkSpeed);

  //setup for next frame
  frame++;
  frame %= sizeof(animation) / sizeof(int[9][3]);
}

//move the currently selected led for the light bright
bool moveCursor() {
  up = digitalRead(upPin);
  down = digitalRead(downPin);
  left = digitalRead(leftPin);
  right = digitalRead(rightPin);

  //debugDirection();

  int prevLedX = ledToEditX;
  int prevLedY = ledToEditY;
  ledToEditY = constrain(ledToEditY + down - up, 0, matrixHeight - 1);
  ledToEditX = constrain(ledToEditX + right - left, 0, matrixWidth - 1);

  return prevLedX != ledToEditX || prevLedY != ledToEditY;
}

void debugPrintLed() {
  Serial.print("(");
  Serial.print(ledToEditX);
  Serial.print(", ");
  Serial.print(ledToEditY);
  Serial.print(")\t");
  Serial.print(leds[ledToEditX][ledToEditY].indexOfColor);
  Serial.println();

}

void debugDirection() {
  Serial.print(up);
  Serial.print("\t");
  Serial.print(down);
  Serial.print("\t");
  Serial.print(left);
  Serial.print("\t");
  Serial.print(right);
}
