/* In my code i need to turn 3 pins on and off with respect to pwm. 
 * I need to decide to use timer interupts and vary the time for transition on all three phases or
 * run a loop of pwm functions
 //-------www<electronics-project-hub>com--------//
#include <math.h>
int Output1 = 11;
int Output2 = 10;
int Output3 = 9;
int potVal = 0;
float A = 0;
float B = 0.104;
int Freq_IN = A0;
int var1 = 0;
int var2 = 0;
int var3 = 0;
int var4 = 0;
int var5 = 0;
int var6 = 0;
float Phase1 = 2 * PI / 3;
float Phase2 = 4 * PI / 3;
float Phase3 = 2 * PI;
boolean toggle = true; // true = Enabling Serial Plotter Output
void setup()
{
  Serial.begin(9600);
  pinMode(Output1, OUTPUT);
  pinMode(Output2, OUTPUT);
  pinMode(Output3, OUTPUT);
  pinMode(Freq_IN, INPUT);
}
void loop()
{
  A += B;
  analogWrite(Output1, var1);
  analogWrite(Output2, var2);
  analogWrite(Output3, var3);
  if (toggle == true)
  {
    Serial.print(var1);
    Serial.print(" ");
    Serial.print(var2);
    Serial.print(" ");
    Serial.println(var3);
  }
  var4 = 126 * sin(A + Phase1);
  var1 = var4 + 128;
  var5 = 126 * sin(A + Phase2);
  var2 = var5 + 128;
  var6 = 126 * sin(A + Phase3);
  var3 = var6 + 128;
  if (A >= 2 * PI)
  {
    A = 0;
  }
  potVal = analogRead(Freq_IN);
  delay(potVal);
}
//-------www<electronics-project-hub>com--------//
 */

#include "mbed.h"
#include "platform/mbed_thread.h"

//First have 3 (16 position) arrays with the required values
// This will give us a crude look at if this will work
 
// Blinking rate in milliseconds
#define BLINKING_RATE_MS                                                    500


int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);

    while (true) {
        led = !led;
        thread_sleep_for(BLINKING_RATE_MS);
    }
}
