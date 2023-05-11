// C++ code
//
#include <time.h>

const int LED_PIN = A1;
const int LIGHT_PIN = A0;
const int LEFT_PIN = A4;
const int RIGHT_PIN = A5;
const int MOTOR_CONTROL_PIN = 5;

int LED_WAIT_DURATION_MIN = 2000;
int LED_WAIT_DURATION_MAX = 6000;

int LED_ON_DURATION_MIN = 2000;
int LED_ON_DURATION_MAX = 6000;

int LIGHT_SENSOR_OUTPUT_INTERVAL = 1000;

int light_sensor_timer = 0;
int wait_duration = 0;
int on_duration = 0;
int last_write_time = 0;
int start_on = 0;
int stop_time = 0;


void setup() {
  pinMode(LIGHT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
  Serial.begin(9600);
  srand(time(0));
  waitDuration();
  
  digitalWrite(LEFT_PIN, HIGH);
  digitalWrite(RIGHT_PIN, LOW);
}

void loop() {

  int light_value = analogRead(LIGHT_PIN);

  if (wait_duration != 0) {

    if (stop_time <= (millis() - start_on) + start_on) {

      wait_duration = 0;
      onDuration();
    } else {
      if (light_sensor_timer - last_write_time >= LIGHT_SENSOR_OUTPUT_INTERVAL) {
        Serial.print("Light sensor output is ");
        Serial.print(light_value);
        Serial.print("\n");
        last_write_time = light_sensor_timer;
      } else {
        light_sensor_timer = millis();
      }

    }

  }

  if (on_duration != 0) {

    if (stop_time <= (millis() - start_on) + start_on) {

      on_duration = 0;
      waitDuration();
    } else {
      if (light_sensor_timer - last_write_time >= LIGHT_SENSOR_OUTPUT_INTERVAL) {
        Serial.print("Light sensor output is ");
        Serial.print(light_value);
        Serial.print("\n");
        last_write_time = light_sensor_timer;
      } else {
        light_sensor_timer = millis();
      }

    }

  }

}

void waitDuration() {

  wait_duration = (rand() % (LED_WAIT_DURATION_MAX - LED_WAIT_DURATION_MIN + 1)) + LED_WAIT_DURATION_MIN;
  digitalWrite(LED_PIN, LOW);
  analogWrite(MOTOR_CONTROL_PIN, 152);

  Serial.print("\nLED is turned OFF for ");
  Serial.print(wait_duration);
  Serial.print(" milliseconds.\n\n");

  start_on = millis();
  stop_time = wait_duration + start_on;

}

void onDuration() {

  on_duration = (rand() % (LED_ON_DURATION_MAX - LED_ON_DURATION_MIN + 1)) + LED_ON_DURATION_MIN;
  digitalWrite(LED_PIN, HIGH);
  Serial.print("\nLED is turned ON for ");
  Serial.print(on_duration);
  Serial.print(" milliseconds.\n\n");
  analogWrite(MOTOR_CONTROL_PIN, 0);

  start_on = millis();
  stop_time = on_duration + start_on;

}