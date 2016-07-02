int colorChange = 0; // 0-r 1-g 2-b
int colorPin = 12;
int numColors;

int potPin = A0;

int colorIntensity = 15;
const int colorDim = 3;
int colors[][colorDim] = {{0, 0, 0},
                          {1, 0, 0},
                          {1, 1, 0},
                          {0, 1, 0},
                          {0, 1, 1},
                          {0, 0, 1},
                          {1, 0, 1},
                          {1, 1, 1}};

int up, down, left, right;
int upPin = 50, downPin = 53, leftPin = 52, rightPin = 51;

struct led {
  int red, green, blue;

  int pinRed, pinBlue, pinGreen;

  led(int r, int g, int b, int pr, int pg, int pb) {
    red = r;
    green = g;
    blue = b;
    pinRed = pr;
    pinGreen = pg;
    pinBlue = pb;
  }

  led(int p) {
    red = 100;
    green = 100;
    blue = 200;
    pinRed = p;
    pinGreen = p + 1;
    pinBlue = p + 2;
  }
};

led leds[] = {led(2), led(5)};


void setup() {
  Serial.begin(9600);
  pinMode(colorPin, INPUT);
  pinMode(upPin, INPUT);
  pinMode(downPin, INPUT);
  pinMode(leftPin, INPUT);
  pinMode(rightPin, INPUT);
  numColors = (sizeof(colors)/sizeof(int[colorDim]));
}

void loop() {
  
  up = digitalRead(upPin);
  down = digitalRead(downPin);
  left = digitalRead(leftPin);
  right = digitalRead(rightPin);

  Serial.print(up);
  Serial.print("\t");
  Serial.print(down);
  Serial.print("\t");
  Serial.print(left);
  Serial.print("\t");
  Serial.println(right);
  
  
  //getting colors
  for (int i = 0; i < (sizeof(leds) / sizeof(led)); ++i) {
    leds[i].red = colors[colorChange][0];
    leds[i].green = colors[colorChange][1];
    leds[i].blue = colors[colorChange][2];
  }
  
  //display
  for (int i = 0; i < (sizeof(leds) / sizeof(led)); ++i) {
    analogWrite(leds[i].pinRed, leds[i].red * colorIntensity);
    analogWrite(leds[i].pinGreen, leds[i].green * colorIntensity);
    analogWrite(leds[i].pinBlue, leds[i].blue * colorIntensity);

    //debugInfo(rgb1[i]);
  }
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

