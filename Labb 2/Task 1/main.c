#include <msp430g2553.h>


void main(void)
{
 WDTCTL = WDTPW + WDTHOLD; // Stop WDT
 P1DIR |= 0x01; // P1.0 output
 TACCTL0 = CCIE; // TA0 CCR0 control: TACCR0 interrupt enabled
 TACCR0 = 50000; //TA0 capture/compare register
 TACTL = TASSEL_2 + MC_1; // SMCLK, up mode
 _BIS_SR(LPM0_bits + GIE); // Enter LPM0 w/ interrupt
}


// Timer A0 interrupt service routine
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{
 P1OUT ^= 0x01; // Toggle P1.0
}