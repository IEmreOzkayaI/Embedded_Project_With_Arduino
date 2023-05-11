 const int G = 13;
 const int F = 12;
 const int A = 11;
 const int B = 10;
 const int E = 9;
 const int D = 8;
 const int C = 7;
 const int H = 6;

 const int MOTION_PIN = 5;
 const int LED_PIN = A0;

 const int TIMER_START = 30;
 const int TIMER_SPEED = 500;
 const int ANIMATION_SPEED = 200;


 void setup(void) {
   pinMode(A, OUTPUT);
   pinMode(B, OUTPUT);
   pinMode(C, OUTPUT);
   pinMode(D, OUTPUT);
   pinMode(E, OUTPUT);
   pinMode(F, OUTPUT);
   pinMode(G, OUTPUT);
   pinMode(H, OUTPUT);
   pinMode(LED_PIN, OUTPUT);
 }

 // Start
 void loop(void) {

   int time = 15;
   int MOTION_VALUE = digitalRead(MOTION_PIN);
   if (MOTION_VALUE == HIGH) {
     digitalWrite(LED_PIN, HIGH);
     if (TIMER_START > 15) {
       animation();
       reset();
     }
     while (time > -1) {
       switch (time) {
       case 15:
         fifteen();
         break;

       case 14:
         fourteen();
         break;

       case 13:
         thirteen();
         break;

       case 12:
         twelve();
         break;

       case 11:
         eleven();
         break;

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
       delay(TIMER_SPEED);
       time--;
     }
     time = 15;
     reset();
     digitalWrite(LED_PIN, LOW);

   }
 }

 //My Functions

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
   digitalWrite(D, HIGH);
   digitalWrite(E, HIGH);
   digitalWrite(F, LOW);
   digitalWrite(G, HIGH);
   digitalWrite(H, LOW);
 }

 void eleven(void) {
   digitalWrite(A, LOW);
   digitalWrite(B, LOW);
   digitalWrite(C, HIGH);
   digitalWrite(D, HIGH);
   digitalWrite(E, HIGH);
   digitalWrite(F, HIGH);
   digitalWrite(G, HIGH);
   digitalWrite(H, LOW);
 }
 void twelve(void) {
   digitalWrite(A, HIGH);
   digitalWrite(B, LOW);
   digitalWrite(C, LOW);
   digitalWrite(D, HIGH);
   digitalWrite(E, HIGH);
   digitalWrite(F, HIGH);
   digitalWrite(G, LOW);
   digitalWrite(H, LOW);
 }
 void thirteen(void) {
   digitalWrite(A, LOW);
   digitalWrite(B, HIGH);
   digitalWrite(C, HIGH);
   digitalWrite(D, HIGH);
   digitalWrite(E, HIGH);
   digitalWrite(F, LOW);
   digitalWrite(G, HIGH);
   digitalWrite(H, LOW);
 }
 void fourteen(void) {
   digitalWrite(A, HIGH);
   digitalWrite(B, LOW);
   digitalWrite(C, LOW);
   digitalWrite(D, HIGH);
   digitalWrite(E, HIGH);
   digitalWrite(F, HIGH);
   digitalWrite(G, HIGH);
   digitalWrite(H, LOW);
 }
 void fifteen(void) {
   digitalWrite(A, HIGH);
   digitalWrite(B, LOW);
   digitalWrite(C, LOW);
   digitalWrite(D, LOW);
   digitalWrite(E, HIGH);
   digitalWrite(F, HIGH);
   digitalWrite(G, HIGH);
   digitalWrite(H, LOW);
 }
 void reset(void) {
   digitalWrite(A, LOW);
   digitalWrite(B, LOW);
   digitalWrite(C, LOW);
   digitalWrite(D, LOW);
   digitalWrite(E, LOW);
   digitalWrite(F, LOW);
   digitalWrite(G, LOW);
   digitalWrite(H, LOW);
 }

 void animation(void) {
   int animation_pin[] = {
     A,
     B,
     C,
     D,
     E,
     F
   };
   int ANIMATION_DURATION = TIMER_START - 15;
   int i = 0;
   int time_total = 0;
   while (ANIMATION_DURATION > 0) {
     if (i == 6) {
       i = 0;
     }
     if (time_total >= TIMER_SPEED) {
       ANIMATION_DURATION--;
       time_total -= TIMER_SPEED;
     }
     reset();
     digitalWrite(animation_pin[i], HIGH);
     delay(ANIMATION_SPEED);
     time_total += ANIMATION_SPEED;
     i++;
   }
 }