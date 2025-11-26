#include <msp430g2553.h>
#include <string.h>

char* ToUpper(char* Str);


void main(void)
{
    char a[] = "abcdefgh";

    char* Capital = ToUpper(a);
    
}

char* ToUpper(char* Str) {
    /* 
    Stora A = 0x41
    Lilla a = 0x61
    Funktionen blir då c - 0x20;
    */
    int length = strlen(Str);
    int i;
    
for(i = 0; i < length; i++) {
    
    if(Str[i] >= 0x61 && Str[i] <= 0x7A) {
    Str[i] = Str[i] - 0x20;
    }
}
    return Str;

}