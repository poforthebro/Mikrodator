#include <msp430g2553.h>

void main(void) {
  WDTCTL = WDTPW + WDTHOLD; // Stop WDT

  //====================================================================
  // Configure Timer_A for PWM
  //====================================================================
  TACCR0 = 2048-1; // PWM Period
  TACCTL1 = OUTMOD_3; // Output Mode 3: set/reset
  TACCR1 = 1024-1; // TACCR1 PWM Duty Cycle
  TACTL = TASSEL_2 + MC_1; // SMCLK, up mode

  //====================================================================
  // VR+ = VREF+ which becomes 2.5V
  // VR- = VSS which becomes 0V
  // SHT_2 = 16 ADC10 clocks to sample and hold
  // ADC10ON = just turns on the ADC
  // REF2_5V = Set reference for SREF_1 to 2.5V
  // ADC10IE = When ADC is done converting, make an interrupt
  
  // INCH_1 = INput channel A1 (P1.1) (Up to 7 Pins)
  // CONSEQ_2 =  Single channel repeat mode
  // ADC10SSEL_3 = Use SMCLK
  // SHS_1 = Use Timer_A.OUT1 using this as conversion 
  //====================================================================

  ADC10CTL0 = SREF_1 + ADC10SHT_2 + REFON + ADC10ON + REF2_5V + ADC10IE + MSC;
  ADC10CTL1 = INCH_1 + CONSEQ_2 + ADC10SSEL_3 + SHS_1;     // input A1, pin P1.1

  //====================================================================
  // IO Management with adc enable
  //====================================================================
  ADC10AE0 |= 0x02;       // Select ADC function for pin P1.1 
  P1DIR |= 0x01; // Set P1.0 to output direction 
  ADC10CTL0 |= ENC;
  // lower power mode with interrupts enabled
  __bis_SR_register(LPM0_bits + GIE);

}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void) {

    int data = ADC10MEM;
    // Testing ADC10BUSY bit in ADC10CTL1
        if (data < 0x266) 
        { P1OUT &= ~0x01;   }   // ADC10MEM = A1 > V?   // Clear P1.0 LED off
        else 
        { P1OUT |= 0x01; }         // Set P1.0 LED on
  __bic_SR_register_on_exit(LPM0_bits);
  
}