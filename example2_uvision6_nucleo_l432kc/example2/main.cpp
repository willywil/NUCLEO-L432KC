#include "mbed.h"
#include <stdio.h>

/* 1. declare a variable
        2. create a small forloop 
        3. 
*/

Serial pc(SERIAL_TX, SERIAL_RX);
char c = 0;
int getInput();
int main()
{
    printf("hello");
    while(1){
     char d = 0;
     c = 0;
     d = getInput();
     printf("you entered: %d\n",d);
     wait(1);
     c = c - 48;
     printf("you entered: %d\n",d);
     //printf("you entered: %c\n",c);
     //printf("you entered: %o\n",c);
     //printf("you entered: %H\n",c);
     int n=0;
     int i=0;
     n = 1;
     //i=c-1;
     
     for (i=2; i<=c; i++){
        n=n*i;
        printf("for loop i: %d \n",i);
        printf("for loop n: %d \n",n);
     }
     printf("The output of %d \n",n);
     i = 0;
     wait(1);
    }
    
}

int getInput(){
    //Possibly create a timer to take a value for a short point of time. only run the loop if a value has been entered!!!!
    c = 0;
    if( c == 0){
        printf("please enter a value: ");
    c = pc.getc();
    }
    return c;
}