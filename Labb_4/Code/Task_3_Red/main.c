#include <msp430g2553.h>
int main(void)
{
    volatile unsigned int i;
    WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
    P1DIR |= 0x01;                            // Set P1.0 to output direction
    WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
    P1DIR |= BIT6;  // Set P1.6 to output direction
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;
    P1SEL |= 0x06;// Selection for transmission and recieve;
    P1SEL2 |= 0x06;

    TACTL = TASSEL_2 + ID_3 + MC_1; //

    while(1)
    {
        P1OUT ^= 0x01;                        // Toggle P1.0 using exclusive-OR

        P1SEL
        for (i=10000; i>0; i--);
  }
}