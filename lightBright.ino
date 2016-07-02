int colorChange = 0; // 0-r 1-g 2-b
int colorPin = 22;
int numColors;

int prevColor;
int colorIntensity = 15;
const int colorDim = 3;
int colors[][colorDim] = {
  {0, 0, 0},
  {1, 0, 0},
  {1, 1, 0},
  {0, 1, 0},
  {0, 1, 1},
  {0, 0, 1},
  {1, 0, 1},
  {1, 1, 1}
};

int up, down, left, right;
int upPin = 50, downPin = 53, leftPin = 52, rightPin = 51;

int blinkTimeMS = 500;

struct led {
  int red, green, blue;
  int pinRed, pinBlue, pinGreen;

  int indexOfColor;

  led(int r, int g, int b, int pr, int pg, int pb) {
    red = r;
    green = g;
    blue = b;
    pinRed = pr;
    pinGreen = pg;
    pinBlue = pb;

    //todo fix
    indexOfColor = 0;
  }

  led(int p) {
    red = 0;
    green = 0;
    blue = 0;
    indexOfColor = 0;
    pinRed = p;
    pinGreen = p + 1;
    pinBlue = p + 2;
  }
};

// keep these synced with the led matrix below.
const int matrixHeight = 2, matrixWidth = 2;
led leds[][matrixHeight] = {
  {led(2), led(5)},
  {led(8), led(11)}
};// matrix is transposed on board 
  // 2 8
  // 5 11

int ledToEditX = 0, ledToEditY = 0;

void setup() {
  Serial.begin(9600);
  pinMode(colorPin, INPUT);
  pinMode(upPin, INPUT);
  pinMode(downPin, INPUT);
  pinMode(leftPin, INPUT);
  pinMode(rightPin, INPUT);
  numColors = (sizeof(colors) / sizeof(int[colorDim]));
  delay(50);
  blinkRGBLed(leds[0][0], blinkTimeMS);
}

void loop() {
  //select the led to change
  bool didMove = moveCursor();
  if(didMove) {
    colorChange = leds[ledToEditX][ledToEditY].indexOfColor;
    blinkRGBLed(leds[ledToEditX][ledToEditY], blinkTimeMS);
  }
    
  Serial.print("\t");
  Serial.print(ledToEditX);
  Serial.print("\t");
  Serial.print(ledToEditY);
  Serial.print("\t\t");
  Serial.println(didMove);
  
  //getting color to set it to
  leds[ledToEditX][ledToEditY].red = colors[colorChange][0];
  leds[ledToEditX][ledToEditY].green = colors[colorChange][1];
  leds[ledToEditX][ledToEditY].blue = colors[colorChange][2];
  
  leds[ledToEditX][ledToEditY].indexOfColor = colorChange;

  //display the led's
  for (int x = 0; x < matrixWidth; ++x) {
    for (int y = 0; y < matrixHeight; ++y)
    paintRGBLed(leds[x][y]);
    //debugInfo(rgb1[x][y]);
  }

  prevColor = colorChange;
  //get the button input for changing to the next color on the current pin
  colorChange = (colorChange + digitalRead(colorPin)) % numColors;

  //Serial.println(colorChange);

  //we should use LCM of the tasks that we have, so we currently have
  //display and input
  //for timer in 0 to 250
  //  if timer % 50 = 0
  //    trigger display
  //   trigger input
  //delay(10)
  delay(250);
}

//move the currently selected led for the light bright
bool moveCursor() {
  up = digitalRead(upPin);
  down = digitalRead(downPin);
  left = digitalRead(leftPin);
  right = digitalRead(rightPin);

  /*Serial.print(up);
  Serial.print("\t");
  Serial.print(down);
  Serial.print("\t");
  Serial.print(left);
  Serial.print("\t");
  Serial.print(right);
*/
  int prevLedX = ledToEditX;
  int prevLedY = ledToEditY;
  ledToEditY = constrain(ledToEditY + down - up, 0, 1);
  ledToEditX = constrain(ledToEditX + right - left, 0, 1);

  return prevLedX != ledToEditX || prevLedY != ledToEditY;
}

void debugInfo(led curColor) {
  Serial.print(colorChange);
  Serial.print("\t");
  /*
    Serial.print(curColor.red);
    Serial.print("\t");
    Serial.print(curColor.green);
    Serial.print("\t");
    Serial.print(curColor.blue);*/
  Serial.println("\n\n");
}

void paintRGBLed(led l) {
    analogWrite(l.pinRed, l.red * colorIntensity);
    analogWrite(l.pinGreen, l.green * colorIntensity);
    analogWrite(l.pinBlue, l.blue * colorIntensity);
}

void blinkRGBLed(led l, int timeToBlink) {
    if(l.indexOfColor == 0) {
      analogWrite(l.pinRed, 1);
      analogWrite(l.pinGreen, 1);
      analogWrite(l.pinBlue, 1);
    } else {
      analogWrite(l.pinRed, 0);
      analogWrite(l.pinGreen, 0);
      analogWrite(l.pinBlue, 0);
    }
    delay(timeToBlink);
    paintRGBLed(l);
}

