#include <stdio.h>
#include <stdint.h>


void main(void){
    signed char a,b,s1,s2;
    unsigned char c; //MODIFIED
    int16_t d;       //MODIFIED

    

    a=127;
    b=127;
    
    c=a+b;
    d=a*b;

    s1=(-8)>>2;
    s2=(-1)>>5;

    printf("c=%d\n",c);
    printf("d=%d\n",d);
    printf("s1=%d\n",s1);
    printf("s2=%d\n",s2);
}
/* Respuestas
1_They aren't correct. There was an overflow in both cases.
2_ As we only need one more bit to represent c, it was declared as an unsigned char.
In the case of d, we need 14 bits to represent it, so we declare it as an int16_t data type.
3_s1 is correct, but s2 isn't. The reason is that the aritmetic shift can't get you a decimal representation.
*/