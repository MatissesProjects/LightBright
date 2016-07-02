int colorChange = 0; // 0-r 1-g 2-b
int colorPin = 12;
int numColors;

int potPin = A0;

int colorIntensity = 15;
int colors[][3] = {{0, 0, 0},
                   {1, 0, 0},
                   {1, 1, 0},
                   {0, 1, 0},
                   {0, 1, 1},
                   {0, 0, 1},
                   {1, 0, 1},
                   {1, 1, 1}};

int up, down, left, right;

struct rgb {
  int red, green, blue;

  int pinRed, pinBlue, pinGreen;

  rgb(int r, int g, int b, int pr, int pg, int pb) {
    red = r;
    green = g;
    blue = b;
    pinRed = pr;
    pinGreen = pg;
    pinBlue = pb;
  }

  rgb(int p) {
    red = 100;
    green = 100;
    blue = 200;
    pinRed = p;
    pinGreen = p + 1;
    pinBlue = p + 2;
  }
};

rgb rgb1[] = {rgb(2), rgb(5)};


void setup() {
  Serial.begin(9600);
  pinMode(colorPin, INPUT);
  numColors = 8;//(sizeof(colors)/sizeof(int));
}

void loop() {
  
  up = digitalRead(50);
  down = digitalRead(53);
  left = digitalRead(52);
  right = digitalRead(51);

  Serial.print(up);
  Serial.print("\t");
  Serial.print(down);
  Serial.print("\t");
  Serial.print(left);
  Serial.print("\t");
  Serial.println(right);
  
  
  //getting colors
  for (int i = 0; i < (sizeof(rgb1) / sizeof(rgb)); ++i) {
    rgb1[i].red = colors[colorChange][0];
    rgb1[i].green = colors[colorChange][1];
    rgb1[i].blue = colors[colorChange][2];
  }
  
  //display
  for (int i = 0; i < (sizeof(rgb1) / sizeof(rgb)); ++i) {
    analogWrite(rgb1[i].pinRed, rgb1[i].red * colorIntensity);
    analogWrite(rgb1[i].pinGreen, rgb1[i].green * colorIntensity);
    analogWrite(rgb1[i].pinBlue, rgb1[i].blue * colorIntensity);

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

void debugInfo(rgb curColor) {
  Serial.print(colorChange);
    Serial.print("\t");
    /*
    Serial.print(curColor.red);
    Serial.print("\t");
    Serial.print(curColor.green);
    Serial.print("\t");
    Serial.print(curColor.blue);*/
    Serial.print(analogRead(A15));
    Serial.println("\n\n");
}

