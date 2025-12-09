#include <msp430g2553.h>
int a=0;
int g = 0x67;

int main(void)
{

    WDTCTL = WDTPW + WDTHOLD;// Stop watchdog timer

    P1DIR |= BIT6;  // Set P1.6 to output direction

     // RXD
    P1SEL |= BIT1;
    P1SEL2 |= BIT1;

    // TXD
    P1SEL |= BIT2;
    P1SEL2 |= BIT2;
    //
    BCSCTL1 = CALBC1_1MHZ;
    DCOCTL = CALDCO_1MHZ;


    TACCTL0 = CCIE; // TACCR0 interrupt enabled
    TACCR0 = 65000;
    TACTL = TASSEL_2 + MC_1 ; // SMCLK, up mode

    UCA0CTL1 |= UCSWRST + UCSSEL_2;

    UCA0BR0 = 52;
    UCA0BR1 = 0;
    UCA0MCTL = UCBRS_0;


    UCA0CTL1 &= ~UCSWRST;

    IE2 |= UCA0RXIE;

    __bis_SR_register(LPM0_bits | GIE);

}
// Timer A0 interrupt service routine
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{
    if(UCA0TXIFG){
    UCA0TXBUF = g;
    }

}
#pragma vector=USCIAB0RX_VECTOR
__interrupt void ISR(void){
  if (UCA0RXBUF == 0x72){
    P1OUT ^= BIT6;
  }

}
/*
#include <msp430g2553.h>
int a = 0;


void main(void) {
WDTCTL = WDTPW + WDTHOLD;

P1DIR |= 0x06; // P1.0 output

P1SEL |= 0x06;
P1SEL2 |= 0x06;

TACCTL0 = CCIE; // TACCR0 interrupt enabled
TACCR0 = 50000;
TACTL = TASSEL_2 + MC_1 + ID_3; // SMCLK, up mode


}
// Timer A0 interrupt service routine
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{
  
if (a == 50){
    P1OUT ^= 0x01; 
    a = 0;
    }
else{
    a++;
    }
}
*/