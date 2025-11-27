
#include <msp430g2553.h>

//====================================================================
//====================================================================

void main(void) {
  WDTCTL = WDTPW + WDTHOLD; // Stop WDT

  TACCR0 = 2048-1; // PWM Period
  TACCTL1 = OUTMOD_3; // Output Mode 3: set/reset
  TACCR1 = 1024-1; // TACCR1 PWM Duty Cycle
  TACTL = TASSEL_2 + MC_1; // SMCLK, up mode

  ADC10CTL0 = SREF_1 + ADC10SHT_2 + REFON + ADC10ON + REF2_5V + ADC10IE;
  ADC10CTL1 = INCH_1 + CONSEQ_2 + ADC10SSEL_3 + SHS_1;     // input A1, pin P1.1
  ADC10AE0 |= 0x02;       // Select ADC function for pin P1.1 
  P1DIR |= 0x01; // Set P1.0 to output direction 

  ADC10CTL0 |= ENC;
__bis_SR_register(LPM0_bits + GIE);
  #pragma vector=ADC10_VECTOR
__interrupt void interruptFunction(void) {

    int data = ADC10MEM;
    // Testing ADC10BUSY bit in ADC10CTL1
        if (data < 0x266) {P1OUT &= ~0x01;   }   // ADC10MEM = A1 > V?   // Clear P1.0 LED off
            
         else { P1OUT |= 0x01; }         // Set P1.0 LED on
  
  ADC10CTL0 |= ADC10SC; // Sampling and conversion for next time
}
__bic_SR_register_on_exit(LPM0_bits);
}
