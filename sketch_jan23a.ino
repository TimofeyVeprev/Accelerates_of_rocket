#include <GyverBME280.h>
#include <MPU9250_asukiaaa.h>

MPU9250_asukiaaa mySensor; // создание экзепляра класса MPU9250_asukiaa
GyverBME280 bme; // создание экезпляра класса GyverBME280
float aX, aY, aZ, aSqrt;
const int buttonPin = 2;
float nullAccel = 0.0;
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  mySensor.beginAccel();
  if (!bme.begin(0x76))
    Serial.println("Error!");

  pinMode(buttonPin, INPUT);
}

void loop() {
  // Колибровка в ноль
  buttonState = digitalRead(buttonPin);

  if (buttonState == 1) {
    nullAccel = mySensor.accelSqrt();
  }
  if (mySensor.accelUpdate() == 0){
    aSqrt = mySensor.accelSqrt() - nullAccel;
    }
  Serial.print(aSqrt);
  
  if (abs(aSqrt) < 0.1) {
    Serial.print("\tЗавис!");
  }
  else {
    Serial.print("\tДвигаюсь!");
  }
  Serial.println("");
}
