int INCREMENT_VALUE = 1;
int WAIT_TIME = 500;
int *intToBinary(int REFERENCE_NUMBER);

void setup()
{    	

  for(int i = 0 ; i < 5 ; i++){
    pinMode(i, OUTPUT);
  }
   
  //Control of 1-31
  
  if(INCREMENT_VALUE < 0){
    while(INCREMENT_VALUE < 0){
    	INCREMENT_VALUE +=32;
    }    
  }
   else if(INCREMENT_VALUE > 31){
      while(INCREMENT_VALUE > 31){
    	INCREMENT_VALUE = INCREMENT_VALUE % 32;
    }
  }
 
    
}

void loop()
{
  
  int *BINARY_CLONE_A ;
  int A = 0;
  int CLONE_A;
  
  // positive wait time control
  if(WAIT_TIME > -1){
  
  do{
    
    // close the leds.
 	for (int i = 0; i < 5; i++) {   	
     	 digitalWrite(i,LOW);
  	}
    
    // take modulus if it's big
    if(A >= 32){
      
      CLONE_A = A % 32;
      A = CLONE_A;
      BINARY_CLONE_A = intToBinary(CLONE_A);
      
    }
    
    // go if it's 1-31
    else{
      BINARY_CLONE_A = intToBinary(A);
    }
  
    // display leds
  	for (int i = 0; i < 5; i++) {   	
    	if(BINARY_CLONE_A[i]==1){
     	 digitalWrite(i,HIGH);
   	 	}
  	}
    
    // transition between leds
  	delay(WAIT_TIME);

    //increment the number
  	A = INCREMENT_VALUE + A ;

  }
  // stop when program reach 0
  while(A != 0);
  
  }
}


int *intToBinary(int REFERENCE_NUMBER) {
  static int INDEX[5];
  int id = 0;
  char binaryKey[5];
  
  // clear static array
  for (int i = 0; i < 5; i++) {  
     INDEX[i]=0;
  }
  
  // convert binary
  while (REFERENCE_NUMBER > 0) {
    INDEX[id] = REFERENCE_NUMBER % 2;
    id++;
    REFERENCE_NUMBER = REFERENCE_NUMBER / 2;
  }

  return INDEX;
}