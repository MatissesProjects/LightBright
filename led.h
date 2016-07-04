
struct led {
  int red, green, blue;
  int pinRed, pinBlue, pinGreen;

  int indexOfColor;
  int colorIntensity = 128;

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

  void paintRGBLed() {
    analogWrite(pinRed, constrain(red * colorIntensity, 0, 255));
    analogWrite(pinGreen, constrain(green * colorIntensity, 0, 255));
    analogWrite(pinBlue, constrain(blue * colorIntensity, 0, 255));
  }

  void blinkRGBLed(int timeToBlink) {
    if (indexOfColor == 0) {
      analogWrite(pinRed, colorIntensity);
      analogWrite(pinGreen, colorIntensity);
      analogWrite(pinBlue, colorIntensity);
    } else {
      analogWrite(pinRed, 0);
      analogWrite(pinGreen, 0);
      analogWrite(pinBlue, 0);
    }
    delay(timeToBlink);
    paintRGBLed();
  }

  void debugInfo() {
    Serial.print(red);
    Serial.print("\t");
    Serial.print(green);
    Serial.print("\t");
    Serial.print(blue);
    Serial.println();
  }
};
