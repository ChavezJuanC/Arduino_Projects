#include <Servo.h>

// Ultra Sonic Sensor
int TrigPin = 7;
int EchoPin = 8;
float duration, distance;

// Servo
bool motor_ready;
Servo ServoMotor;
int MotorPin = 10;
int offTime = 3000;

void setup() {
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  Serial.begin(9600);
  ServoMotor.attach(MotorPin);
  motor_ready = true;
  ServoMotor.write(0); //closed
}

void scan_area() {
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
}

float calculate_distance() {
  duration = pulseIn(EchoPin, HIGH, 25000); // timeout 25ms
  distance = (duration * 0.0343) / 2.0;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
}

void trigger_servo() {
  motor_ready = false;
  Serial.println("Opening...");
  ServoMotor.write(90);
  delay(offTime);
  Serial.println("Closing...");
  ServoMotor.write(0);
  delay(offTime);
  motor_ready = true;
  Serial.println("Lid reset");
}

void loop() {
  if (motor_ready) {
    scan_area();
    delayMicroseconds(100);
    float current_distance = calculate_distance();
    if (current_distance > 0 && current_distance <= 150) {
      trigger_servo();
    }
  }
  delay(200);
}
