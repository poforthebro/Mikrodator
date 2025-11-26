#include <msp430g2553.h>


int average(int input[]);
volatile unsigned int avg = 0;


int main(void)
{
    volatile unsigned int i;
    WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
    P1DIR |= 0x01;                            // Set P1.0 to output direction

  ADC10CTL0 = SREF_1 + ADC10SHT_2 + REFON + ADC10ON + REF2_5V + ADC10IE + MSC; 
  // Internal reference 1, Sample and hold time = 16 cycles, Internal reference v on, Turns on the ADC

    ADC10CTL1 = INCH_1 + CONSEQ_2; // input A1, pin P1.1, repeat single channel mdoe
    
    int a[0x10] = {0}; // Define the array to use as DTC buffer
    ADC10DTC1 = 0x10;
    ADC10SA = (int)a;

  __bis_SR_register(LPM0_bits + GIE);

}


#pragma vector=ADC10_VECTOR
__interrupt void IErruptFuck(void) {

  int a[0x10] = {0};
  ADC10DTC1 = 0x10;

  avg = average(a);
}


int average(int input[]) {
  int length = sizeof(input);
  int j;
  int sum = 0;
  for(j = 0; j < length; j++) {
    sum = sum + input[j];
  }
  int average = sum / length;
  return average;

}