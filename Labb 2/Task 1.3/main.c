#include <msp430.h>


// void main(void)
// {
//  WDTCTL = WDTPW + WDTHOLD; // Stop WDT
//  P1DIR |= 0x01; // P1.0 output
//  TACCTL0 = CCIE; // TA0 CCR0 control: TACCR0 interrupt enabled
//  TACCR0 = 50000; // Task 1.1 10 Hz

//  TACTL = TASSEL_2 + MC_1; // SMCLK, up mode
//  _BIS_SR(LPM0_bits + GIE); // Enter LPM0 w/ interrupt
// }


 int n = 0;
 
// Divide clock by 8 to get slower frequency. Change to Overflow toggling. 65535 * 1/(8*1M) ????
void main(void)
{

 WDTCTL = WDTPW + WDTHOLD; // Stop WDT
 P1DIR |= 0x01; // P1.0 output
 TACTL = TASSEL_2 + MC_2 + TAIE + ID_3; // SMCLK, continuous mode, interrupt, divided by 8

 _BIS_SR(LPM0_bits + GIE); // Enter LPM0 w/ interrupt
}

// // Timer A0 interrupt service routine
 #pragma vector=TIMER0_A1_VECTOR
 __interrupt void Timer_A (void)
 {
  switch( TAIV ) {
    case 2: {break;}
    case 4: {break;}
    case 10: {
      n = n +1;

      if(n == 10) {
       n = 0;
       P1OUT ^= 0x01; // Toggle P1.0
       }
      break;
    }

  }
  
 }
