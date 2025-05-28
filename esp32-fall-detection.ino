#include <Adafruit_MPU6050.h>

#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

// Fall detection thresholds
const float FREE_FALL_THRESHOLD = 2.0; // in m/s^2
const float IMPACT_THRESHOLD = 20.0; // in m/s^2

bool inFreeFall = false;
unsigned long fallStartTime = 0;

void setup() {
Serial.begin(115200);
Wire.begin(); // SDA = GPIO21, SCL = GPIO22

if (!mpu.begin()) {
Serial.println("Failed to find MPU6050 sensor!");
while (1);
}

mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
mpu.setGyroRange(MPU6050_RANGE_500_DEG);
mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

Serial.println("MPU6050 ready. Monitoring for falls...");
}

void loop() {
sensors_event_t accel, gyro, temp;
mpu.getEvent(&accel, &gyro, &temp);

float ax = accel.acceleration.x;
float ay = accel.acceleration.y;
float az = accel.acceleration.z;

float totalAcc = sqrt(ax * ax + ay * ay + az * az);

if (!inFreeFall && totalAcc < FREE_FALL_THRESHOLD) {
inFreeFall = true;
fallStartTime = millis();
Serial.println("[INFO] Free fall detected...");
}

if (inFreeFall && totalAcc > IMPACT_THRESHOLD && millis() - fallStartTime < 2000) {
Serial.println("[ALERT] Fall Detected!");
inFreeFall = false;
}

if (inFreeFall && millis() - fallStartTime > 2000) {
Serial.println("[INFO] False alarm, no impact detected.");
inFreeFall = false;
}

delay(200); // You can reduce this to improve response time
}
