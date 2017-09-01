#include <stdio.h>
#include <unistd.h>
#include <time.h> //for sleep() function

#define clear() printf("\033[0d\033[2J");

int main()

{

    printf("\033[?12l");

    int hour, minute, second;
    hour=minute=second=0;
    
while(1)
   
    {         
       
    printf("%02d : %02d : %02d\n ",hour,minute,second);
    fflush(stdin);     
    clear();
    second++;
 
if
            (second == 60)
 
       {
        
            minute += 1;
            second = 0;
        
        }

if
        
            (minute == 60)
       
        {
        
            hour += 1;
            minute = 0;
          
        }
       
if
 
            (hour == 24)
        
        {
        
            hour = 0;
            minute = 0;
            second = 0;
        
        }
         
            sleep(1);   //wait till 1 second
                
    }
 
    return 0;
}

