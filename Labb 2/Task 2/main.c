#include <msp430g2553.h>

void main(void)
{
 WDTCTL = WDTPW + WDTHOLD; // Stop WDT
 P1DIR |= 0x01; // P1.0 output
 TACTL = TASSEL_2 + MC_2 + TAIE + ID0+ ID1; // SMCLK,continuous mode, interrupt, divided by 8
 TACCR1 = 32768;

 _BIS_SR(LPM0_bits + GIE); // Enter LPM0 w/ interrupt
}

// Timer_A Interrupt Vector (TAIV) handler
#pragma vector=TIMER0_A1_VECTOR
__interrupt void Timer_A(void)
{
switch( TAIV )
{
 case 2: { P1OUT ^= 0x01; // Switch LED
 TACCR1 = TACCR1 + 65535; // Add offset to TACCR1
 break;} // TACCR1 not used
 case 4: {break;} // TACCR2 not used
 case 10: {P1OUT ^= 0x01; // Timer overflow
 break;}
}
}