/*
*1.Write to DAC
*2.Read from ADC
*3.Assign DAC value to array
*4.Assign ADC value to array
*5.Increase tick value
*6.End loop after 1000 times
*7.Find AAE, MTPRE, differences, SD
*8.Increase Pass/Fail ticks
*9.End Calc array loop and return to main loop for another sample set
*
*Second goal, add option to change DAC value through USART
*/

#include "mbed.h"
#include <stdio.h>

Serial pc(SERIAL_TX, SERIAL_RX);
DigitalOut myled(LED1);
Timer t;
void foo(int a)
{
    printf("Value of a is %d\n", a);
    
}
    
int main() {
    
    int a = 11;
    int *p1;
    int **p2;
    p1 = &a;
    p2 = &p1;    
    while(1) {
       char c = pc.getc();
        if(c == '1'){
            myled = 1; // LED is ON
        }
            
        printf("address of a = %u\n", &a);
        printf("address of p1 = %u\n", &p1);
        printf("address of p2 = %u\n", &p2);
        printf("value at the address by p2 = %u\n", *p2);
        printf("value at the address by p1 = %d\n\n", *p1);
        printf("value at the address by **p2 = %d\n", **p2);
        
        printf("hello2\n");
        if(c == '0'){
            myled = 0; // LED is OFF
        }
        foo(10); 
    
   
    t.start();
    printf("hello");
    printf("tits and ass\n");
    wait(.1);
    if (t.read() >= 1){
    printf("The time taken was %f seconds\n", t.read());
    t.stop();
    t.reset();
    }
    wait(.1);
    
    
    }
    
}
