#include <stdio.h>
#include <string.h>

char* ToUpper(char* Str);


void main(void)
{
    char a[] = "1a2b3c#&/%)/&/€#369+'-k";

    char* Capital = ToUpper(a);
    printf("%s \n", Capital);
    
}

char* ToUpper(char* Str) {
    /* 
    Stora A = 0x41
    Lilla a = 0x61
    Funktionen blir då c + 0x20;
    */
    int length = strlen(Str);
    printf("%d \n", length);
    int i;
    
for(i = 0; i < length; i++) {
    
    if(Str[i] >= 0x61 && Str[i] <= 0x7A) {
    Str[i] = Str[i] - 0x20;
    }
}
    return Str;
}