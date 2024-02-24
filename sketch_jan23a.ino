#include <GyverBME280.h>
#include <MPU9250_asukiaaa.h>
MPU9250_asukiaaa mySensor; // создание экзепляра класса MPU9250_asukiaa
GyverBME280 bme; // создание экезпляра класса GyverBME280
float aSqrt;
const int buttonPin = 13;
const float value = 0.1;
float nullAccel = 0.0;
int buttonState = 0;
int digits = 1000;
int sum = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  mySensor.beginAccel();
  if (!bme.begin(0x76))
    Serial.println("Error!");

  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == 1) {
    nullAccel = mySensor.accelSqrt();
  }

  // Колибровка в ноль
  if (mySensor.accelUpdate() == 0) {
    aSqrt = mySensor.accelSqrt() - nullAccel;
  }

  if (nullAccel != 0) {
    Serial.print(mediumArray());
  }
  else {
    Serial.print(aSqrt);
  }

  if (abs(aSqrt) < value) {
    Serial.print("\tЗавис!");
  }
  else {
    Serial.print("\tДвигаюсь!");
  }
  Serial.println("");
}

int mediumArray() {
  for (int count = 0; count < digits; count++) {
    sum += aSqrt;
  }
  int result = sum / digits;
  
  return result;
}
