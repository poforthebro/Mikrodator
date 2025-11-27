#include <msp430g2553.h>

void main(void) {
  WDTCTL = WDTPW + WDTHOLD; // Stop WDT

  ADC10CTL0 = SREF_1 + ADC10SHT_2 + REFON + ADC10ON + REF2_5V; // Internal reference 1, Sample and hold time = 16 cycles, Internal reference v on, Turns on the ADC
  ADC10CTL1 = INCH_1;     // input A1, pin P1.1
  ADC10AE0 |= BIT1;       // Select ADC input pin P1.1 
  P1DIR |= BIT0; // Set P1.0 to output direction 
  
  ADC10CTL0 |= ENC + ADC10SC; // Run a first sample and conversion

  __bis_SR_register(LPM0_bits + GIE);
  
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {

    while (ADC10CTL1 & ADC10BUSY) {
    } // wait until the conversion is ready
    // Testing ADC10BUSY bit in ADC10CTL1
        if (ADC10MEM < 0x266)    // ADC10MEM = A1 > V?
        P1OUT &= ~0x01;         // Clear P1.0 LED off
         else P1OUT |= 0x01;         // Set P1.0 LED on
  }

}