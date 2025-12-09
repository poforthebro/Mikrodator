#include <msp430g2553.h>

int sendData = 0x01;
int receiveData = 0x10;


int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
    P1DIR |= BIT0;                           // Set P1.0 to output direction

  // Configure UART ports
  // RXD
  P1SEl |= BI1;
  P1SEl2 |= BI1;

  // TXD
  P1SEl |= BI2;
  P1SEl2 |= BI2;


  BCSCTL1 = CALBC1_1MHZ;
  DCOCTL = CALDCO_1MHZ;

  TACCTL0 = CCIE; // TACCR0 interrupt enabled
  TACCR0 = 50000;
  TACTL = TASSEL_2 + MC_1; // SMCLK, up mode

  // Setup transmission
  UCSWRST = 0;




  __bis_SR_register(LPM0_bits + GIE);
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void) {

  UCA0TXBUF = sendData; //Send data
  
  TACCR0 += 50000; // Update value in timer

}

#pragma vector=USCIAB0RX_VECTOR
__interrupt void RX (void) {

  
}