// C++ code
//
int LED_ACTIVATION_VALUE = 500;
int SERIAL_OUTPUT_FREQUENCY = 500;
int LED_PIN = A1;
int LIGHT_PIN = A0;
int total_time = 0;
void setup()
{
  pinMode(LIGHT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  total_time += 5;
  delay(5);
  // ORTAM KARANLIKSA LEDİ YAK , AYDINLIKSA KAPAT
  int value= analogRead(LIGHT_PIN);
  if(value <= LED_ACTIVATION_VALUE){
    if(total_time == SERIAL_OUTPUT_FREQUENCY){
       Serial.print("LIGHT SENSOR :");
       Serial.println(value);
       Serial.println("LED   STATUS : OFF \n" );
       total_time=0;

    }
        digitalWrite(LED_PIN,LOW);

  }else{
     if(total_time == SERIAL_OUTPUT_FREQUENCY){
           Serial.print("LIGHT SENSOR :");
           Serial.println(value);
           Serial.println("LED   STATUS : ON\n" );
      	   total_time=0;

     }
    digitalWrite(LED_PIN,HIGH);

  }
    
}