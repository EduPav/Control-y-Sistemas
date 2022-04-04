#include <stdio.h>
#include <stdint.h>
#include <math.h>


#define n 10 //Q21.10

//Rounding in terms of bits, not decimal digits.
int32_t truncation(int64_t x){
    return (int32_t)(x>>n);
}//We are losing big integers due to overflow. Don't we?

int32_t rounding(int64_t x){
    return truncation(x+(1<<(n-1)));
}//Again possible overflow

double fx2fp(int x){
    return (double)x/(1<<n);
}



void main(){
    int64_t result;
    int32_t a,b;
    double d_a,d_b,d_result,e1,e2;
    a=12223;//Q21.10
    b=541;//Q21.10
    d_a=fx2fp(a);
    d_b=fx2fp(b);
    printf("a=%llf\n",d_a); //floating
    printf("b=%llf\n\n",d_b); //floating

    result=(int64_t)a*b; //Q21.10
    d_result=d_a*d_b;
    e1=fabs(fx2fp(truncation(result))-d_result)/d_result*100;
    e2=fabs(fx2fp(rounding(result))-d_result)/d_result*100;

    printf("Double operations:%llf\n",d_result);
    printf("Truncated:%llf,   Error=%f%c\n",fx2fp(truncation(result)),e1,'%');
    printf("Rounded:%llf, Error=%f%c\n",fx2fp(rounding(result)),e2,'%');
    



}
