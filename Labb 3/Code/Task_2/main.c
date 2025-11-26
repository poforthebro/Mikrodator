
//====================================================================
TACCR0 = 2048-1; // PWM Period
TACCTL1 = OUTMOD_3; // Output Mode 3:
set/reset
TACCR1 = 1024-1; // TACCR1 PWM Duty
Cycle
TACTL = TASSEL_2 + MC_1; // SMCLK, up mode
//====================================================================

void main(void) {
  WDTCTL = WDTPW + WDTHOLD; // Stop WDT



  ADC10CTL0 = SREF_1 + ADC10SHT_2 + REFON + ADC10ON;
  ADC10CTL1 = INCH_1;     // input A1, pin P1.1
  ADC10AE0 |= 0x02;       // Select ADC function for
  pin P1.1 P1DIR |= 0x01; // Set P1.0 to output direction 
  for (;;) {
    ADC10CTL0 |= ENC + ADC10SC; // Sampling and conversion start
    
    while (ADC10CTL1 & ADC10BUSY) {
    } // wait until the conversion is ready
    // Testing ADC10BUSY bit in ADC10CTL1
        if (ADC10MEM < 0x88)    // ADC10MEM = A1 > V?
        P1OUT &= ~0x01;         // Clear P1.0 LED off
         else P1OUT |= 0x01;         // Set P1.0 LED on
  }
}