 const int G = 13;
 const int F = 12;
 const int A = 11;
 const int B = 10;
 const int E = 9;
 const int D = 8;
 const int C = 7;
 const int H = 6;

 const int LEFT_PIN = A4;
 const int RIGHT_PIN = A5;
 const int MOTOR_CONTROL_PIN = 5;

 const int LEFT_BUTTON_PIN = A3;
 const int RIGHT_BUTTON_PIN = A2;

 const int MOTOR_STEPS = 10;
 int LEFT_STEP_CONTROLLER = 0;
 int RIGHT_STEP_CONTROLLER = 0;

 int display_step = 0;
 void setup() {

   pinMode(A, OUTPUT);
   pinMode(B, OUTPUT);
   pinMode(C, OUTPUT);
   pinMode(D, OUTPUT);
   pinMode(E, OUTPUT);
   pinMode(F, OUTPUT);
   pinMode(G, OUTPUT);
   pinMode(H, OUTPUT);

   pinMode(RIGHT_PIN, OUTPUT);
   pinMode(LEFT_PIN, OUTPUT);
   pinMode(MOTOR_CONTROL_PIN, OUTPUT);

   pinMode(LEFT_BUTTON_PIN, INPUT);
   pinMode(RIGHT_BUTTON_PIN, INPUT);
 }

 void loop() {
   int left_button_value = digitalRead(LEFT_BUTTON_PIN);
   int right_button_value = digitalRead(RIGHT_BUTTON_PIN);
   if (left_button_value != 0) {
     delay(200);
     if (RIGHT_STEP_CONTROLLER != 0) {
       turn_right(-1);
     } else if (LEFT_STEP_CONTROLLER < MOTOR_STEPS) {
       turn_left(1);
     }
   }
   if (right_button_value != 0) {
     delay(200);

     if (LEFT_STEP_CONTROLLER != 0) {
       turn_left(-1);
     } else if (RIGHT_STEP_CONTROLLER < MOTOR_STEPS) {
       turn_right(1);
     }

   }

 }

 void turn_right(int number) {
   RIGHT_STEP_CONTROLLER = RIGHT_STEP_CONTROLLER + number;
   int speed = 255 / MOTOR_STEPS * RIGHT_STEP_CONTROLLER;
   analogWrite(MOTOR_CONTROL_PIN, speed);
   digitalWrite(LEFT_PIN, LOW);
   digitalWrite(RIGHT_PIN, HIGH);
   display_segment(RIGHT_STEP_CONTROLLER);
 }
 void turn_left(int number) {
   LEFT_STEP_CONTROLLER = LEFT_STEP_CONTROLLER + number;
   int speed = 255 / MOTOR_STEPS * LEFT_STEP_CONTROLLER;
   analogWrite(MOTOR_CONTROL_PIN, speed);
   digitalWrite(LEFT_PIN, HIGH);
   digitalWrite(RIGHT_PIN, LOW);
   display_segment(LEFT_STEP_CONTROLLER);
 }

 void display_segment(int display_step) {

   switch (display_step) {

   case 10:
     ten();
     break;

   case 9:
     nine();
     break;

   case 8:
     eight();
     break;

   case 7:
     seven();
     break;

   case 6:
     six();
     break;

   case 5:
     five();
     break;

   case 4:
     four();
     break;

   case 3:
     three();
     break;

   case 2:
     two();
     break;

   case 1:
     one();
     break;

   case 0:
     zero();
     break;
   default:
     break;

   }

 }

 void zero(void) {
   digitalWrite(A, HIGH);
   digitalWrite(B, HIGH);
   digitalWrite(C, HIGH);
   digitalWrite(D, HIGH);
   digitalWrite(E, HIGH);
   digitalWrite(F, HIGH);
   digitalWrite(G, LOW);
   digitalWrite(H, LOW);
 }

 void one(void) {
   digitalWrite(A, LOW);
   digitalWrite(B, HIGH);
   digitalWrite(C, HIGH);
   digitalWrite(D, LOW);
   digitalWrite(E, LOW);
   digitalWrite(F, LOW);
   digitalWrite(G, LOW);
   digitalWrite(H, LOW);
 }

 void two(void) {
   digitalWrite(A, HIGH);
   digitalWrite(B, HIGH);
   digitalWrite(C, LOW);
   digitalWrite(D, HIGH);
   digitalWrite(E, HIGH);
   digitalWrite(F, LOW);
   digitalWrite(G, HIGH);
   digitalWrite(H, LOW);
 }

 void three(void) {
   digitalWrite(A, HIGH);
   digitalWrite(B, HIGH);
   digitalWrite(C, HIGH);
   digitalWrite(D, HIGH);
   digitalWrite(E, LOW);
   digitalWrite(F, LOW);
   digitalWrite(G, HIGH);
   digitalWrite(H, LOW);
 }

 void four(void) {
   digitalWrite(A, LOW);
   digitalWrite(B, HIGH);
   digitalWrite(C, HIGH);
   digitalWrite(D, LOW);
   digitalWrite(E, LOW);
   digitalWrite(F, HIGH);
   digitalWrite(G, HIGH);
   digitalWrite(H, LOW);
 }

 void five(void) {
   digitalWrite(A, HIGH);
   digitalWrite(B, LOW);
   digitalWrite(C, HIGH);
   digitalWrite(D, HIGH);
   digitalWrite(E, LOW);
   digitalWrite(F, HIGH);
   digitalWrite(G, HIGH);
   digitalWrite(H, LOW);
 }

 void six(void) {
   digitalWrite(A, HIGH);
   digitalWrite(B, LOW);
   digitalWrite(C, HIGH);
   digitalWrite(D, HIGH);
   digitalWrite(E, HIGH);
   digitalWrite(F, HIGH);
   digitalWrite(G, HIGH);
   digitalWrite(H, LOW);
 }

 void seven(void) {
   digitalWrite(A, HIGH);
   digitalWrite(B, HIGH);
   digitalWrite(C, HIGH);
   digitalWrite(D, LOW);
   digitalWrite(E, LOW);
   digitalWrite(F, LOW);
   digitalWrite(G, LOW);
   digitalWrite(H, LOW);
 }

 void eight(void) {
   digitalWrite(A, HIGH);
   digitalWrite(B, HIGH);
   digitalWrite(C, HIGH);
   digitalWrite(D, HIGH);
   digitalWrite(E, HIGH);
   digitalWrite(F, HIGH);
   digitalWrite(G, HIGH);
   digitalWrite(H, LOW);
 }

 void nine(void) {
   digitalWrite(A, HIGH);
   digitalWrite(B, HIGH);
   digitalWrite(C, HIGH);
   digitalWrite(D, HIGH);
   digitalWrite(E, LOW);
   digitalWrite(F, HIGH);
   digitalWrite(G, HIGH);
   digitalWrite(H, LOW);
 }

 void ten(void) {
   digitalWrite(A, HIGH);
   digitalWrite(B, HIGH);
   digitalWrite(C, HIGH);
   digitalWrite(D, LOW);
   digitalWrite(E, HIGH);
   digitalWrite(F, HIGH);
   digitalWrite(G, HIGH);
   digitalWrite(H, LOW);
 }