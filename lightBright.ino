#define colorred     {1, 0, 0}
#define colorgreen   {0, 1, 0}
#define colorblue    {0, 0, 1}
#define colorcyan    {0, 1, 1}
#define coloryellow  {1, 1, 0}
#define colorpurple  {1, 0, 1}
#define colorwhite   {1, 1, 1}
#define coloroff     {0, 0, 0}

int colors[8][3] = {
  coloroff, colorred, coloryellow, colorgreen,
  colorcyan, colorblue, colorpurple, colorwhite
};

int colorChange = 0; // 0-r 1-g 2-b
int colorPin = 122;
int numColors;

int prevColor;
int colorIntensity = 128;
const int colorDim = 3;

int ledToEditX = 0, ledToEditY = 1;

int up, down, left, right;
int upPin = 150, downPin = 153, leftPin = 152, rightPin = 151;

int blinkTimeMS = 500;

struct led {
  int red, green, blue;
  int pinRed, pinBlue, pinGreen;

  int indexOfColor;

  led(int pr, int pg, int pb, int r, int g, int b) {
    init(r, g, b, pr, pg, pb, 0);
  }

  led(int p, int * c) {
    init(c[0], c[1], c[2], p, p + 1, p + 2, 0);
  }

  //debug
  led(int p) {
    init(0, 1, 0, p, p + 1, p + 2, 0);
  }

  void init(int r, int g, int b, int pr, int pg, int pb, int iofColor) {
    red = r;
    green = g;
    blue = b;
    pinRed = pr;
    pinGreen = pg;
    pinBlue = pb;

    //todo fix
    indexOfColor = iofColor;

    pinMode(pinRed, OUTPUT);
    pinMode(pinBlue, OUTPUT);
    pinMode(pinGreen, OUTPUT);
  }

  void setColor(int * color) {
    red = color[0];
    green = color[1];
    blue = color[2];
  }
};

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
  delay(50);
  blinkRGBLed(leds[ledToEditX][ledToEditY], blinkTimeMS);
}

void loop() {
  //select the led to change
  if (moveCursor()) {
    colorChange = leds[ledToEditX][ledToEditY].indexOfColor;
    blinkRGBLed(leds[ledToEditX][ledToEditY], blinkTimeMS);
  }

  //debugPrintLed();

  //getting color to set it to
  leds[ledToEditX][ledToEditY].setColor(colors[colorChange]);
  leds[ledToEditX][ledToEditY].indexOfColor = colorChange;

  //display the led's
  for (int x = 0; x < matrixWidth; ++x) {
    for (int y = 0; y < matrixHeight; ++y) {
      prevColor = leds[x][y].indexOfColor;//colorChange;
      colorChange++;
      //get the button input for changing to the next color on the current pin
      colorChange = (colorChange + digitalRead(colorPin)) % numColors;

      leds[x][y].setColor(colors[colorChange]);

      paintRGBLed(leds[x][y]);
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
  delay(250);
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

void paintRGBLed(led l) {
  analogWrite(l.pinRed, l.red * colorIntensity);
  analogWrite(l.pinGreen, l.green * colorIntensity);
  analogWrite(l.pinBlue, l.blue * colorIntensity);
}

void blinkRGBLed(led l, int timeToBlink) {
  if (l.indexOfColor == 0) {
    analogWrite(l.pinRed, colorIntensity);
    analogWrite(l.pinGreen, colorIntensity);
    analogWrite(l.pinBlue, colorIntensity);
  } else {
    analogWrite(l.pinRed, 0);
    analogWrite(l.pinGreen, 0);
    analogWrite(l.pinBlue, 0);
  }
  delay(timeToBlink);
  paintRGBLed(l);
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

void debugInfo(led curColor) {
  Serial.print(curColor.red);
  Serial.print("\t");
  Serial.print(curColor.green);
  Serial.print("\t");
  Serial.print(curColor.blue);
  Serial.println();
}

