#include <Wire.h>
#include <MPU6050.h>
#include <Servo.h>

Servo servox;
Servo servoy;

const int servox_pin = 3;
const int servoy_pin = 4;


MPU6050 sensor;


void setup() {
  servox.attach(servox_pin);
  servoy.attach(servoy_pin);

  
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Initializing the sensor");
  
  sensor.initialize();
  Serial.println(sensor.testConnection() ? "Successfully Connected" : "Connection failed");

  delay(1000);
  Serial.println("Taking Values from the sensor");
  delay(1000);
}

void loop() {
  sensor.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  int servox_thesi = map(gx, 20000, -20000, 0, 180);
  int servoy_thesi = map(gy, 20000, -20000, 0, 180);

  Serial.print("Gyro X: ");
  Serial.println(gx);
  Serial.print("Gyro Y: ");
  Serial.println(gy);

  servox.write(servox_thesi);
  servoy.write(servoy_thesi);

  delay(100);
}