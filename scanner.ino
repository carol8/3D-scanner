#include <Servo.h>
#include <VL53L0X.h>

VL53L0X sensor;

Servo yaw;
Servo pitch;

const int YAW_PIN = 9;
const int PITCH_PIN = 10;

int steps_yaw = 10;
int steps_pitch = 10;

int start_yaw = 30;
int start_pitch = 60;

int end_yaw = 150;
int end_pitch = 90;

int delay_yaw = 200;
int delay_pitch = 100;
int delay_initialisation = 1000;

int current_yaw;
int current_pitch;
int cstep_yaw;
int cstep_pitch;

bool yawDir = false;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  yaw.attach(YAW_PIN);
  pitch.attach(PITCH_PIN);

  Serial.print("$steps ");
  Serial.print(steps_pitch);
  Serial.print(" ");
  Serial.println(steps_yaw);

  Serial.print("Initialising servos... ");
  pitch.write(start_pitch);
  yaw.write(start_yaw);
  delay(delay_initialisation);
  Serial.println("done!");

  Serial.print("Initialising sensor... ");
  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("failed!");
    while (1) {}
  }
  sensor.startContinuous();
  Serial.println("done!");
}

void loop() {
  pitch_yaw_iterate();
}

void pitch_yaw_iterate() {
  for (cstep_pitch = 0; cstep_pitch <= steps_pitch; cstep_pitch++) {
    current_pitch = start_pitch + ((end_pitch - start_pitch) * cstep_pitch) / steps_pitch;
    pitch.write(current_pitch);
    delay(delay_pitch);
    yaw_iterate();
  }
  for (cstep_pitch = steps_pitch; cstep_pitch >= 0; cstep_pitch--) {
    current_pitch = start_pitch + ((end_pitch - start_pitch) * cstep_pitch) / steps_pitch;
    pitch.write(current_pitch);
    delay(delay_pitch);
    yaw_iterate();
  }
}

void yaw_iterate() {
  if (!yawDir) {
    for (cstep_yaw = 0; cstep_yaw <= steps_yaw; cstep_yaw++) {
      current_yaw = start_yaw + ((end_yaw - start_yaw) * cstep_yaw) / steps_yaw;
      yaw.write(current_yaw);
      delay(delay_yaw);
      print_sensor_readout();
    }
  } else {
    for (cstep_yaw = steps_yaw; cstep_yaw >= 0; cstep_yaw--) {
      current_yaw = start_yaw + ((end_yaw - start_yaw) * cstep_yaw) / steps_yaw;
      yaw.write(current_yaw);
      delay(delay_yaw);
      print_sensor_readout();
    }
  }
  yawDir = !yawDir;
}

void print_sensor_readout() {
  Serial.print("$distance ");
  Serial.print(cstep_pitch);
  Serial.print(" ");
  Serial.print(cstep_yaw);
  Serial.print(" ");
  Serial.println(sensor.readRangeContinuousMillimeters());
}
