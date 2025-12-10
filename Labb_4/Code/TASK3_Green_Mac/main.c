

#include <msp430g2553.h>

int sendData = 0x72; // "r"
int receiveData = 0x67; // "g"


int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer

  // Setup systemclock with calibration:
  BCSCTL1 = CALBC1_1MHZ;
  DCOCTL = CALDCO_1MHZ;


  P1DIR |= BIT0;                           // Set P1.0 to output direction

  // Configure UART ports
  // RXD
  P1SEL |= BIT1;
  P1SEL2 |= BIT1;

  // TXD
  P1SEL |= BIT2;
  P1SEL2 |= BIT2;

  TACCTL0 = CCIE; // TACCR0 interrupt enabled
  TACCR0 = 32500;
  TACTL = TASSEL_2 + MC_1; // SMCLK, up mode

  // Setup transmission
  UCA0CTL1 |= UCSSEL_2; // Use system clock
  UCA0BR0 = 52;                             // 1MHz 19200
  UCA0BR1 = 0;                              // 1MHz 19200
  UCA0MCTL = UCBRS0;                        // Modulation UCBRSx = 1
  
  UCA0CTL1 &= ~UCSWRST; // Inititate UART Statemachine

  IE2 |= UCA0RXIE; // Enable RX Interrupt

  __bis_SR_register(LPM0_bits + GIE);
}


#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void) {

  UCA0TXBUF = sendData; //Send data


}

#pragma vector=USCIAB0RX_VECTOR
__interrupt void RX (void) {

  if(UCA0RXBUF == receiveData) {
    P1OUT ^= BIT0;
  }

}