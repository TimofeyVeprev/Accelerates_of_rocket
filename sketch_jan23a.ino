#include <GyverBME280.h>
#include <MPU9250_asukiaaa.h>

MPU9250_asukiaaa mySensor; // создание экзепляра класса MPU9250_asukiaa
GyverBME280 bme; // создание экезпляра класса GyverBME280
float aX, aY, aZ, aSqrt, gX, gY, gZ;

void setup() {
  
  Serial.begin(115200);
  while (!Serial);
  
  mySensor.beginAccel();
  mySensor.beginGyro();
  if (!bme.begin(0x76))
    Serial.println("Error!");
  // You can set your own offset for mag values
  // mySensor.magXOffset = -50;
  // mySensor.magYOffset = -55;
  // mySensor.magZOffset = -10;
}

void loop() {
  // Акселерометр
  if (mySensor.accelUpdate() == 0) {
    aX = mySensor.accelX();
    aY = mySensor.accelY();
    aZ = mySensor.accelZ();
    aSqrt = mySensor.accelSqrt();
    Serial.print("accelX: " + String(aX));
    Serial.print("\taccelY: " + String(aY));
    Serial.print("\taccelZ: " + String(aZ)); 
    Serial.print("\taccelSqrt: " + String(aSqrt));
  }
  
   //гироскоп
  if (mySensor.gyroUpdate() == 0) {
    gX = mySensor.gyroX();
    gY = mySensor.gyroY();
    gZ = mySensor.gyroZ();
    Serial.print("\tgyroX: " + String(gX));
    Serial.print("\tgyroY: " + String(gY));
    Serial.print("\tgyroZ: " + String(gZ));
  }
  
  
  Serial.println("");
}

void SearchAccel(){
  
}
