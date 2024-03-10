#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

Adafruit_BNO055 bno = Adafruit_BNO055();

void setup() {
  Serial.begin(9600);

  if (!bno.begin())
  {
    Serial.println("Could not find a valid BNO055 sensor, check wiring!");
    while (1);
  }

  delay(1000);
}

void loop() {
  readIMUOutputs();
  delay(1000); // Adjust the delay as needed
}

void readIMUOutputs() {
  sensors_event_t event;
  bno.getEvent(&event);

  Serial.print("Orientation: ");
  Serial.print("Heading: "); Serial.print(event.orientation.x, 2);
  Serial.print(" | Pitch: "); Serial.print(event.orientation.y, 2);
  Serial.print(" | Roll: "); Serial.println(event.orientation.z, 2);

  uint8_t sys, gyro, accel, mag;
  bno.getCalibration(&sys, &gyro, &accel, &mag);
  Serial.print("Calibration: ");
  Serial.print("Sys: "); Serial.print(sys);
  Serial.print(" | Gyro: "); Serial.print(gyro);
  Serial.print(" | Acc: "); Serial.println(accel);

  imu::Vector<3> accelVector = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
  Serial.print("Acceleration: ");
  Serial.print("X: "); Serial.print(accelVector.x());
  Serial.print(" | Y: "); Serial.print(accelVector.y());
  Serial.print(" | Z: "); Serial.println(accelVector.z());

  imu::Vector<3> gyroVector = bno.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);
  Serial.print("Gyroscope: ");
  Serial.print("X: "); Serial.print(gyroVector.x());
  Serial.print(" | Y: "); Serial.print(gyroVector.y());
  Serial.print(" | Z: "); Serial.println(gyroVector.z());

  imu::Vector<3> magVector = bno.getVector(Adafruit_BNO055::VECTOR_MAGNETOMETER);
  Serial.print("Magnetometer: ");
  Serial.print("X: "); Serial.print(magVector.x());
  Serial.print(" | Y: "); Serial.print(magVector.y());
  Serial.print(" | Z: "); Serial.println(magVector.z());

  Serial.println();
}