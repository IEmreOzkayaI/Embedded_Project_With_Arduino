int buttonValue = 0;

int buzzer = 8;
int button = A0;

int no_tone = 0; // 0
int do_high = 523;//1
int re = 291; // 2
int mi = 330; // 3
int fa = 349; // 4
int sol = 392; // 5
int la = 440; // 6
int si = 494; // 7
int do_low = 262; //8


int SOUND_DURATION = 500;
int SILENCE_DURATION = 50;

//Twinkle Twinkle Little Star music notes
int MELODY [] = {1,1,5,5,6,6,5,0,4,4,3,3,2,2,1};

// Postman coming music notes
//int MELODY[] = {5,4,5,6,5,4,3,2,4,3,2,3,5,4,5,6,5,4,3,2,4,3,2,1}; 


int MELODY_NOTES [] = { no_tone, do_low , re , mi , fa , sol, la, si, do_high};


void setup()
{
  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);

}

void loop()
{
  buttonValue = digitalRead(button);
  size_t size = sizeof(MELODY)/sizeof(MELODY[0]);
  
  if(buttonValue != 0){
    for(int i=0;i<size;i++){
    tone(buzzer, MELODY_NOTES[MELODY[i]], SOUND_DURATION);
    delay(SOUND_DURATION + SILENCE_DURATION);
    }
  }
  else{
    digitalWrite(buzzer, LOW);
  }
}