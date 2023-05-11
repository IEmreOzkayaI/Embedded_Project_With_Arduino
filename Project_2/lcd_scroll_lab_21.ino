#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(34, 16, 2);


bool SCROLL_FLAG = true;

int SCROLL_WAIT = 100;

char SCROLL_DIRECTION = 'L';

char LCD_ROW_1 [] = "This text is for row 0 and longer than 16 characters.";
char LCD_ROW_2 [] = "ABCD EFGH";

int head=0;
int tail=0;
int tail2=0;

int head_t=0;
int tail_t=16;

int head_t_2=0;
int tail_t_2=16;

char *result_left;
char *result_right;

char *LCD_ROW_2_TEMP = (char*)malloc(16 * sizeof(char));
char *LCD_ROW_1_TEMP = (char*)malloc(16 * sizeof(char));

char *text_1;
char *text_2;

int head_right = 0;
int head_right_t =0 ; //but it will update

int tail_right=0; // it will update
int tail_right_t=0; // it will pdate;

int head_right_2 = 0;
int head_right_2_t =0 ; //but it will update

int tail_right_2=0; // it will update
int tail_right_2_t=0; // it will pdate;

char * Scroll_LCD_Left(char LCD_ROW []);
char * Scroll_LCD_Left_2(char LCD_ROW []);

char * Scroll_LCD_Right(char LCD_ROW []);
char * Scroll_LCD_Right_2(char LCD_ROW []);

void setup()
{
  if(SCROLL_FLAG){
  lcd.init();
  lcd.backlight();

  tail = sizeof(LCD_ROW_1);
  tail_right = sizeof(LCD_ROW_1);
  tail_right_t = sizeof(LCD_ROW_1);
  head_right_t = sizeof(LCD_ROW_1) - 17;
  if(tail<16){
    tail = 16;
   
    
    // take string and control size 
    // detect variables
   for(int i =0; i < 16; i++){
      if(i < sizeof(LCD_ROW_1)-1){
      LCD_ROW_1_TEMP[i]=LCD_ROW_1[i];
      }
      else{
      LCD_ROW_1_TEMP[i]=' ';
      }
    }
  
  }else{
 
    
   LCD_ROW_1_TEMP =(char*) realloc(LCD_ROW_1_TEMP,tail* sizeof(char));
   for(int i =0; i < tail; i++){
      LCD_ROW_1_TEMP[i]=LCD_ROW_1[i];

    }
  }
  
  tail2 = sizeof(LCD_ROW_2);
  
 
  tail_right_2 = sizeof(LCD_ROW_2);
  tail_right_2_t = sizeof(LCD_ROW_2);
  head_right_2_t = sizeof(LCD_ROW_2) - 17;
  if(tail2<16){
    tail2 = 16;
     
  tail_right_2 = 17;
  tail_right_2_t = 17;
  head_right_2_t = 0;
   for(int i =0; i < 16; i++){
      if(i < sizeof(LCD_ROW_2)-1){
      LCD_ROW_2_TEMP[i]=LCD_ROW_2[i];
      }
      else{
      LCD_ROW_2_TEMP[i]=' ';
      }
    }
  
  }else{
  
   
   LCD_ROW_2_TEMP =(char*) realloc(LCD_ROW_2_TEMP,tail2* sizeof(char));
   for(int i =0; i < tail2; i++){
      LCD_ROW_2_TEMP[i]=LCD_ROW_2[i];

    }
  }}
  
 
  
}

void loop()
{
  
  if(SCROLL_DIRECTION == 'L'&& SCROLL_FLAG){
  
       // for length< 16
    text_1 = Scroll_LCD_Left(LCD_ROW_1_TEMP);
    lcd.setCursor(0, 0);
    for(int i = 0; i < 16; i++){
    
      if(text_1[i]== byte(0)){
                lcd.print(byte(0));

      }else{
                lcd.print(text_1[i]);

      }
    
    }
      
      
      
    free(result_left);
    
    text_2 = Scroll_LCD_Left_2(LCD_ROW_2_TEMP);
    lcd.setCursor(0, 1);
    for(int i = 0; i < 16; i++) lcd.print(text_2[i]); 
   	free(result_left);
    delay(SCROLL_WAIT);


    lcd.clear();
  
  }
  
  
  

if(SCROLL_DIRECTION == 'R' && SCROLL_FLAG){
    
     // for length< 16

    text_2 = Scroll_LCD_Right(LCD_ROW_1_TEMP);
    lcd.setCursor(0, 0);
    for(int i = 0; i < 16; i++) lcd.print(text_2[i]); 
    free(result_right);
    
  
  
    text_2 = Scroll_LCD_Right_2(LCD_ROW_2_TEMP);
    lcd.setCursor(0, 1);
    for(int i = 0; i < 16; i++) lcd.print(text_2[i]); 
    free(result_right);
  
  	delay(SCROLL_WAIT);

      
    lcd.clear();

   }
 	
}




//----------------------------------
char * Scroll_LCD_Left(char LCD_ROW []){
 
  result_left = (char*)malloc(16 * sizeof(char));
  int index=-1;

  if(head_t == tail){
     head_t=0;
     tail_t=16;  
  }
  
  if(tail_t == tail && tail <= 16){
 

  	  for(int i = head_t ; i < tail_t ; i++){
       index++;
       result_left[index] = LCD_ROW[i];
   	  }
    
    int rem =  (15 - index);
    for(int i = head ; i < head + rem ; i++){
        index++;
        result_left[index] = LCD_ROW[i];
   	  }
    head_t++;
  }
  else if(tail_t == tail-1 && tail > 16){
 

  	  for(int i = head_t ; i < tail_t ; i++){
       index++;
       result_left[index] = LCD_ROW[i];
   	  }
    
    int rem =  (15 - index);
    for(int i = head ; i < head + rem ; i++){
        index++;
        result_left[index] = LCD_ROW[i];
   	  }
    head_t++;
  }
  else{
 
      for(int i = head_t ; i < tail_t ; i++){
       index++;
       result_left[index] = LCD_ROW[i];
   	  }
        head_t++;
        tail_t++;
  }
  return result_left;
}


char * Scroll_LCD_Left_2(char LCD_ROW []){
 
 result_left = (char*)malloc(16 * sizeof(char));
  int index=-1;

  if(head_t_2 == tail2){
     head_t_2=0;
     tail_t_2=16;  
  }
  
  
  if(tail_t_2 == tail2 && tail2 <= 16){
  	  for(int i = head_t_2 ; i < tail_t_2 ; i++){
       index++;
       result_left[index] = LCD_ROW[i];
   	  }
    
    int rem =  (15 - index);
    for(int i = head ; i < head + rem ; i++){
        index++;
        result_left[index] = LCD_ROW[i];
   	  }
    head_t_2++;
  }
  else if(tail_t_2 == tail2 && tail2 > 16){
  	  for(int i = head_t_2 ; i < tail_t_2 ; i++){
       index++;
       result_left[index] = LCD_ROW[i];
   	  }
    
    int rem =  (15 - index);
    for(int i = head ; i < head + rem ; i++){
        index++;
        result_left[index] = LCD_ROW[i];
   	  }
    head_t_2++;
  }
  else{

      for(int i = head_t_2 ; i < tail_t_2 ; i++){
       index++;
       result_left[index] = LCD_ROW[i];
   	  }
        head_t_2++;
        tail_t_2++;
  }
  return result_left;
}



char * Scroll_LCD_Right(char LCD_ROW []){
 
 result_right = (char*)malloc(16 * sizeof(char));
  int index = -1;
  if(head_right_t != head){
   
      for(int i = head_right_t ; i < tail_right_t ; i++){
       index++;
       result_right[index] = LCD_ROW[i];
   	  }
    head_right_t--;
    tail_right_t--;
  }
  else if(head_right_t == head){
    
      for(int i = head_right_t ; i < tail_right_t ; i++){
       index++;
       result_right[index] = LCD_ROW[i];
   	  }
    int rem = 16-index;
   
      for(int i = index ; i > -1 ; i--){
        result_right[i+rem] = result_right[i];
   	  }
        index=-1;
      for(int i = tail_right-rem-1 ; i < tail_right-1 ; i++){
        index++;
       result_right[index] = LCD_ROW[i];
   	  }

    tail_right_t--;
  }
   
  if(tail_right_t == head+1){
    if(tail_right <= 17){
         tail_right_t = 17;
   head_right_t = 0;
    }else{
       tail_right_t = sizeof(LCD_ROW_1);
   head_right_t = sizeof(LCD_ROW_1) - 17;
    }

  }
  
    
  
  
   
  return result_right;

}


char * Scroll_LCD_Right_2(char LCD_ROW []){
 
 result_right = (char*)malloc(16 * sizeof(char));
  int index = -1;
  if(head_right_2_t != head){
   
      for(int i = head_right_2_t ; i < tail_right_2_t ; i++){
       index++;
       result_right[index] = LCD_ROW[i];
   	  }
    head_right_2_t--;
    tail_right_2_t--;
  }
  else if(head_right_2_t == head){
    
      for(int i = head_right_2_t ; i < tail_right_2_t ; i++){
       index++;
       result_right[index] = LCD_ROW[i];
   	  }
    int rem = 16-index;
   
      for(int i = index ; i > -1 ; i--){
        result_right[i+rem] = result_right[i];
   	  }
        index=-1;
      for(int i = tail_right_2-rem-1 ; i < tail_right_2-1 ; i++){
        index++;
       result_right[index] = LCD_ROW[i];
   	  }

    tail_right_2_t--;
  }
  
  if(tail_right_2_t == head+1){
    if(tail_right_2 <= 17){
         tail_right_2_t = 17;
   head_right_2_t = 0;
    }else{
       tail_right_2_t = sizeof(LCD_ROW_2);
   head_right_2_t = sizeof(LCD_ROW_2) - 17;
    }

  }
  
  return result_right;

}