
#include <msp430g2553.h>

void main(void)
{

    // Change WDTCTL = WDTIS1 + WDTIS0 to set different frequencies
    WDTCTL = WDTPW + WDTTMSEL + WDTCNTCL;                 // Start watchdog in timer mode 


    IE1 |= WDTIE;   // Enable Watchdog interrupt

    P1DIR |= 0x01; // P1.0 output

    __bis_SR_register(LPM0_bits + GIE);
}

// Timer A0 interrupt service routine
#pragma vector=WDT_VECTOR
__interrupt void WDTinterrupt(void)
{

    P1OUT ^= 0x01;

}
