
#include <msp430g2553.h>
#include<intrinsics.h>

void main(void)
{
    
    WDTCTL = WDTPW + WDTTMSEL + WDTCNTCL + WDTIS0;                 // Start watchdog in timer mode
    IE1 |= WDTIE;
    
    P1DIR |= BIT0; // P1.0 output

    __bis_SR_register(LPM0 + GIE);
}

// Timer A0 interrupt service routine
#pragma vector=WDT_VECTOR
__interrupt void WDTinterrupt (void)
{

P1OUT ^= BIT0;

}
