#include <msp430g2553.h>
  void main(void)
  {
    // not needed to care about 
  WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer

  // Change the pin values 
  P1DIR |= 0x01 + 0x04 + 0x40; // Set P1.0, P1.1 and P1.6 to output direction

  // p1.4 --> p1.5
  P1IE |= 0x20; // P1.4 interrupt enabled
  P1IES |= 0x20; // P1.4 rising edge
  P1IFG &= ~0x20; // P1.4 IFG cleared interrupt flag cleared

  //P1OUT &= 0xFD; //1111 1101 //pull low 


  _BIS_SR(GIE); // Global Interrupt Enabled

  // useless loop to make delay
  while(1)
  {
  int a = 0;
  int b = 0;
  for(; a< 20000; a++)
  {
  for(;b < 20000; b++)
  {
  _NOP();
  }
  }

  P1OUT ^= 0x04; //00000010
  P1OUT ^= 0x40;//0100 0000
  }
  }
  // Port 1 interrupt service routine
  #pragma vector=PORT1_VECTOR
  __interrupt void Port_1(void)
  {
  P1OUT ^= 0x01; // P1.0 = toggle
  // change to 1.5
  P1IFG &= ~0x20; // P1.4 IFG cleared
  }

