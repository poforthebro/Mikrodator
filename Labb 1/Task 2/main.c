
#include <msp430g2553.h>

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;
volatile unsigned char a = 0xAB;
volatile unsigned char b = 0xFE;

volatile unsigned char sum;
volatile unsigned char not;
volatile unsigned char xor;
volatile unsigned char rightshift;
volatile unsigned char leftshift;

sum = a + b;
not = ~a;
xor = a^b;
rightshift = a >> 4;
leftshift = b << 2;

a ^= BIT3;
b ^= BIT7;



}
