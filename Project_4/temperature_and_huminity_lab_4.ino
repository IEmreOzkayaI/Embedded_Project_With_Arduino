#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(34, 16, 2);
void state();

const int button = A2;
const int potantio_meter = A1;
const int temperature_meter = A0;
const int button_value = 0;

int previousButtonState = 0;
int currentButtonState = 1;
char LCD_LANGUAGE = 'E';

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(temperature_meter, INPUT);
  pinMode(potantio_meter, INPUT);
  pinMode(button, INPUT);
}

void loop() {
  state();
  int RawValue = analogRead(temperature_meter);
  double voltage = (RawValue / 1023.0) * 5000; // 5000 to get millivots.
  double temperature_C = (voltage - 500) * 0.1; // 500 is the offset
  double temperature_F = (temperature_C * 1.8) + 32; // convert to F  
  double humidity_sensor_output = analogRead(potantio_meter);
  humidity_sensor_output = map(humidity_sensor_output, 0, 1023, 0, 100) * 1.0;
  if (LCD_LANGUAGE == 'E') {
    lcd.setCursor(0, 0);
    lcd.print("TEM(F):");
    if (!((int) temperature_F > 100 || (int) temperature_F < -10)) {
      lcd.print(' ');
    }
    lcd.print(temperature_F);
    if (temperature_F < 10.0 && temperature_F > 0.0) {
      lcd.print("EN");
    } else {
      lcd.print(" EN");
    }
    lcd.setCursor(0, 1);
    lcd.print("HUM(%): ");
    lcd.print(humidity_sensor_output);
  }
  state(); // break controll	
  if (LCD_LANGUAGE == 'T') {
    lcd.setCursor(0, 0);
    lcd.print("SIC(C):");
    if (!((int) temperature_C > 100 || (int) temperature_C < -10)) {
      lcd.print(' ');
    }
    lcd.print(temperature_C);

    if (temperature_C < 10.0 && temperature_C > 0.0) {
      lcd.print("  TR");

    } else {
      lcd.print(" TR");

    }
    lcd.setCursor(0, 1);
    lcd.print("NEM(%): "); 
    lcd.print(humidity_sensor_output);
  }

}

void state() {
  currentButtonState = digitalRead(button);
  if (currentButtonState == 1 && previousButtonState == 0) {
    LCD_LANGUAGE = 'T';
    previousButtonState = currentButtonState;
    lcd.clear();
  } else if (currentButtonState == 1 && previousButtonState == 1) {
    LCD_LANGUAGE = 'E';
    previousButtonState = 0;
    lcd.clear();
  }

}