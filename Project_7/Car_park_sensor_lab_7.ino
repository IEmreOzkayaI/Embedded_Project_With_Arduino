#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// C++ code
//

LiquidCrystal_I2C LCD(34, 16, 2);

int BUZZER_LED_FREQ_MAX = 1000;
int BUZZER_LED_FREQ_MIN = 10;

int DIST_MAX = 100;
int DIST_MIN = 10;

int CURRENT_DIST = 0;
int CURRENT_FREQ = 0;
int TEMP_CURRENT_FREQ =0;
int UPDATE_FREQ_BUZZER = 200;
int UPDATE_FREQ_LCD = 200;

int LCD_SDA_PIN = A4;
int LCD_SCL_PIN = A5;

int TRIGGER_PIN = A2;
int BUZZER_PIN = A0;
int ECHO_PIN = A1;
int LED_PIN = A3;

unsigned long dynamic_delay_for_led_buzzer = 0;
unsigned long dynamic_delay_for_lcd = 0;


unsigned long buzzerStartTime = 0;
bool buzzerOn = false;
bool first_control = false;


void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  LCD.init();
  LCD.backlight();
  Serial.begin(9600);
  dynamic_delay_for_led_buzzer = millis();
  dynamic_delay_for_lcd = millis();
}

void loop()
{
  if(millis() - dynamic_delay_for_led_buzzer >= UPDATE_FREQ_BUZZER){
     current_frequency_calculator();
     dynamic_delay_for_led_buzzer = millis();
     first_control=true;
  }
  if(first_control){
     buzzer_alert();
  }
 if(millis() - dynamic_delay_for_lcd >= UPDATE_FREQ_LCD){
    lcd_display();
    dynamic_delay_for_lcd = millis();
 }
}


void current_frequency_calculator(){
  
    current_distance_calculator();
    CURRENT_FREQ = ((((float)CURRENT_DIST -(float) DIST_MIN)/ ((float)DIST_MAX -(float) DIST_MIN)) * ((float) BUZZER_LED_FREQ_MAX - (float)BUZZER_LED_FREQ_MIN))  +(float) BUZZER_LED_FREQ_MIN;
    if(CURRENT_FREQ<DIST_MIN){
      CURRENT_FREQ=0;
    }
}

void lcd_display(){

    LCD.setCursor(0,0);
   	LCD.print("DISTANCE :");
 	LCD.print(CURRENT_DIST);
    LCD.print("cm  ");
    LCD.setCursor(0,1);
    LCD.print("FREQUENCY:");
    LCD.print(CURRENT_FREQ);
    LCD.print("ms  ");
  
  
}

void current_distance_calculator(){

  int DURATION;
  
  digitalWrite(TRIGGER_PIN,LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN,HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN,LOW);
	
  DURATION = pulseIn(ECHO_PIN,HIGH);
  CURRENT_DIST = DURATION / 58.2 ;

}


void buzzer_alert(){
  if(CURRENT_FREQ != TEMP_CURRENT_FREQ){
    TEMP_CURRENT_FREQ = CURRENT_FREQ;
  }
  
  if(TEMP_CURRENT_FREQ > BUZZER_LED_FREQ_MAX){
	    noTone(BUZZER_PIN);
        digitalWrite(LED_PIN,LOW);
  }else if (TEMP_CURRENT_FREQ < BUZZER_LED_FREQ_MIN){
       digitalWrite(LED_PIN,HIGH);
       tone(BUZZER_PIN,440);
       buzzerOn = true;
       buzzerStartTime = millis();
  }else{
       if (!buzzerOn && (millis() - buzzerStartTime >= TEMP_CURRENT_FREQ) ) {
           digitalWrite(LED_PIN,HIGH);
           tone(BUZZER_PIN,440);
           buzzerOn = true;
           buzzerStartTime = millis();
       }
       else if (millis() - buzzerStartTime >= TEMP_CURRENT_FREQ) {
           noTone(BUZZER_PIN);
           digitalWrite(LED_PIN,LOW);
           buzzerOn = false;
           buzzerStartTime = millis();
       }
  }
}
