#include <msp430g2553.h>


void main(void)
{

// IO setup
WDTCTL = WDTPW + WDTHOLD; // Stop WDT
P1DIR |= 0x01; // P1.0 output
// P1SEL |= BIT1 + BIT2;
// P1SEL2 = 0x0000;

// Timer config
TACTL = TASSEL_2 + MC_2 + TAIE + ID_3; // SMCLK, Continuous mode

TACCTL2 = OUTMOD_4; // TACCR1 interrupt enabled
TACCTL1 = CCIE + OUTMOD_4; // TACCR1 interrupt enabled
TACCR2 = 2000; //TACCR0 initial value
TACCR1 = 400; // TACCR1 initial value

_BIS_SR(LPM0_bits + GIE); // Enter LPM0 w/ interrupt
}


 #pragma vector=TIMER0_A1_VECTOR
 __interrupt void Timer_A (void)
 {
  switch( TAIV ) {
    case 2: {break;}
    case 4: {break;}
    case 10: {

      P1OUT ^= 0x01; // Toggle P1.0
      break;

    }
  
  }
 }