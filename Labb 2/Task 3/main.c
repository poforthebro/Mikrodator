#include <msp430g2553.h>


void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop WDT
P1DIR |= 0x01; // P1.0 output
TACCTL1 = CCIE; // TACCR1 interrupt enabled
TACCR1 = 25000; //TACCR1 initial value
TACCR2 = 50000; // TACCR0 initial value
TACTL = TASSEL_2 + MC_2; // SMCLK, Continuous mode
_BIS_SR(LPM0_bits + GIE); // Enter LPM0 w/ interrupt
}

// Timer_A3 Interrupt Vector (TAIV) handler
#pragma vector=TIMER0_A1_VECTOR
__interrupt void Timer_A(void)
{
switch( TAIV )
{
case 2: // TACCR1 interrupt
{
P1OUT ^= 0x01; // Toggle P1.0
TACCR1 += 50000; // Add Offset to TACCR1
TACCTL2 = CCIE; // TACCR2 interrupt enabled
}
break;
case 4: {
P1OUT ^= 0x01; // Toggle P1.0
TACCR2 += 50000; // Add Offset to TACCR2
TACCTL1 = CCIE; // TACCR1 interrupt enabled
}
break;
case 10: break;
}
}
