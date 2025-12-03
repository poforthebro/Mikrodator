#include <msp430g2553.h>


int average(int input[]);
volatile unsigned int avg;
int numberOfDTC = 1000;
int n = 0;

int a[0x10] = {0}; // Define the array to use as DTC buffer

int main(void)
{
    volatile unsigned int i;
    WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
    P1DIR |= BIT0;                            // Set P1.0 to output direction
    avg = 0;
    ADC10CTL0 = SREF_1 + ADC10SHT_2 + REFON + ADC10ON + REF2_5V + ADC10IE + MSC; 
  // Internal reference 1, Sample and hold time = 16 cycles, Internal reference v on, Turns on the ADC

    ADC10CTL1 = INCH_1 + CONSEQ_2; // input A1, pin P1.1, repeat single channel mdoe
    
    ADC10DTC1 = 0x10; // Set numbers of transfers per block

    ADC10SA = (unsigned int)a;
    ADC10CTL0 |= ENC + ADC10SC;

  __bis_SR_register(LPM0_bits + GIE);

}


#pragma vector=ADC10_VECTOR
__interrupt void IntErruptFuncktion(void) {

  avg = average(a);
  ADC10SA = (unsigned int)a; // Restart DTC

  if(n == numberOfDTC) {
    n = 0;
    P1OUT ^= BIT0;
  }

  ++n;

}

// Function to calculate average value
int average(int input[]) {
  int length = 0x10;
  int j;
  int sum = 0;
  avg = 0;

  for(j = 0; j < length; j++) {
    sum = sum + input[j];
  }
  int average = sum / length;
  return average;

}