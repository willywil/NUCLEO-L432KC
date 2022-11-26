#include "mbed.h"

AnalogIn in(A2);

#if !DEVICE_ANALOGOUT
#error You cannot use this example as the AnalogOut is not supported on this device.
#else
AnalogOut out(PA_4);
#endif

DigitalOut led(LED1);
unsigned int failTick = 0;
unsigned int cyclesComplete = 0;
float failPercent = 0.0f;
float totDiff = 0.0f;
float avgDiff = 0.0f;
unsigned int i = 0;
//ATE-> Absolute True Error
//MTPRE->Magnitude True Percent Relitive Error
//
int main()
{
    printf("\ntits n' ass\n");
    printf("*** Connect A2 and PA_4 pins together ***\n");
    while(1) {
        
        for (float out_value = 0.1f; out_value < 1.0f; out_value += 0.01f) {
            // Output value using DAC
            out.write(out_value);
            wait(0.1);
            // Read ADC input
            float in_value = in.read();
            // Display difference between two values
            float ATE = fabs(out_value - in_value);
            float MTPRE = (ATE/out_value)*100;
            //printf("(out:%.4f) - (in:%.4f) = (%.4f) ", out_value, in_value, MTPRE);
            if (MTPRE > .25f) {
                //printf("FAIL\n");
                failTick++;
            } else {
                //printf("OK\n");
                //printf("\033[1A"); // Moves cursor up of 1 line
            }
            //led = !led;
            totDiff += ATE;
            cyclesComplete++;
            //printf("%d \n",cyclesComplete);
            if (cyclesComplete == 100){
                failPercent = 100 * (float(failTick) / float(cyclesComplete));
                avgDiff = totDiff / cyclesComplete;
            led = !led;
            printf("\nNew loop, Number of fails: %d, cycles Completed: %d, Fail Percent: %.4f, Avearge Absolute Error %.10f\n ", failTick, cyclesComplete, failPercent, avgDiff);
            cyclesComplete = 0;
            failPercent = 0.0f;
            failTick = 0;
            totDiff = 0.0f;
            avgDiff = 0.0f;
            }
        }
        //failPercent = 100 * (float(failTick) / float(cyclesComplete));
        //failPercent = float(cyclesComplete);
        //if (cyclesComplete > 10){
           // led = !led;
           // printf("\nNew loop, Number of fails: %d, cycles Completed: %d, Fail Percent: %.10f\n", failTick, cyclesComplete, failPercent);
           // cyclesComplete = 0;
           // failPercent = 0.0f;
            //failTick = 0;
           // }
    }
}

