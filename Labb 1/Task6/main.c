#include<msp430g2553.h>

void main(void) {
  WDTCTL = WDTPW + WDTHOLD;

  // GPIO konfig
  P1DIR |= BIT0; // LED1
  P1DIR |= BIT6; // LED 6
  P1DIR &= ~BIT3; //Input = 0

// Initialstate LEDs
  P1OUT |= BIT0; // Red LED on
  P1OUT &= ~BIT6; // Green LED off

// Pullup resistor
  P1REN |= BIT3; // Enable resistor
  P1OUT |= BIT3; // Enable pullup

// Interrupts
  P1IE |= BIT3; // Enable interrupt
  P1IES |= BIT3; // Fallingedge interrupt

  P1IFG &= ~BIT3; // Clear the flags

  while(1) {
     __bis_SR_register(GIE + LPM4_bits);
  }

}

#pragma vector = PORT1_VECTOR
__interrupt void btn(void) {
 
  if(P1IES & BIT3) { // Check which edge triggered
    P1OUT |= BIT6; // Green LED on
    P1OUT &= ~BIT0; // Red LED off

    P1IES &= ~BIT3; // Risingedge interrupt

  } else {
    P1OUT |= BIT0; // Red LED on
    P1OUT &= ~BIT6; // Green LED off

    P1IES |= BIT3; // Fallingedge interrupt
  }

  P1IFG &= ~BIT3;

}
