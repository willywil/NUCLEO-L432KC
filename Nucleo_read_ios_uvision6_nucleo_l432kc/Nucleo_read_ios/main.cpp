#include "mbed.h"

#define IOS (0xA0) // PA_5 + PA_7
 
PortIn myIOs(PortA, IOS);
 
DigitalOut myled(LED1);
 
int main() {
    while(1) {
        if (myIOs.read() != IOS) { // Any of the 2 IOs is low
            myled = !myled; // Toggle LED state
            wait(0.2);
        }
    }
}
 