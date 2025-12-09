
#include <msp430g2553.h>

int n = 0;

void main(void)
{
    
    
    
    P1DIR |= BIT0; // P1.0 output
    P1OUT |= BIT0;

    WDTCTL = WDTPW + WDTTMSEL + WDTCNTCL + WDTIS1;                 // Start watchdog in timer mode
    IE1 |= WDTIE;

    __bis_SR_register(LPM0 + GIE);
}

// Timer A0 interrupt service routine
#pragma vector=WDT_VECTOR
__interrupt void WDTinterrupt(void)
{
++n;
if(n == 1000) {
P1OUT ^= BIT0;
n = 0;
}

}
