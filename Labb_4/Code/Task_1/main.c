#include <msp430g2553.h>
int a = 0;
void main(void)
{
WDTCTL = WDTPW + WDTHOLD; // Stop WDT
P1DIR |= 0x01; // P1.0 output
TACCTL0 = CCIE; // TACCR0 interrupt enabled
TACCR0 = 50000;
TACTL = TASSEL_2 + MC_1; // SMCLK, up mode
for(;;){_BIS_SR(GIE);}
}
// Timer A0 interrupt service routine
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{
if (a == 10)
{P1OUT ^= 0x01; a = 0;}
else{a++;}
}