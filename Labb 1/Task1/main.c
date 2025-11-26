#include <stdio.h>
#include <stdlib.h>

int a[10] = {0,1,2,3,4,5,6,7,8,9};
int d = 0;
int pointersize = 0;

int ArraySize = 0;

void main(void)
{
 d = a[5];
 ArraySize = sizeof(a); //20 number of bytes, not the number of element
 pointersize = sizeof(&a[0]); // 2, number of bytes for the pointer after run
}