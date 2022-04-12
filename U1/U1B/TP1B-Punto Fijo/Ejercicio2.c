#include <stdio.h>
#include <stdint.h>
#include <math.h>


double fx2fp(int32_t x, int8_t n){
    return (double)x/(1<<n);
}

int32_t fp2fx(double x, int8_t n){
    return round(x*(1<<n));
}

void main(){

    double b,e; 
    int32_t a;
    a=fp2fx(2.4515,8); //Qm.n with n=8
    b=fx2fp(a,8);  //fx2fp(fp2fx(2.4515))
    printf("Q23.8->%d\n",a);
    printf("Flotante=%0.8f\n",b);
    e=fabs(b-2.4515)/2.4515*100;
    printf("Error=%f%c",e,'%');

    a=fp2fx(2.4515,10); //Qm.n with n=10
    b=fx2fp(a,10);  //fx2fp(fp2fx(2.4515))
    printf("\n\nQ21.10->%d\n",a);
    printf("Flotante=%0.8f\n",b);
    e=fabs(b-2.4515)/2.4515*100;
    printf("Error=%f%c",e,'%');
}
//10.01110100       n=8
//10.0111001110     n=10

/*
4_  Printed results
*/