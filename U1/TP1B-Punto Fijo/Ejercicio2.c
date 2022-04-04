#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define n 8  //Qm.n

double fx2fp(int x){
    return (double)x/(1<<n);
}

int32_t fp2fx(double x){
    return round(x*(1<<n));
}

void main(){

    double b,e; 
    int32_t a;
    a=fp2fx(2.4515);
    b=fx2fp(a);  //fx2fp(fp2fx(2.4515))
    printf("%d\n",a);
    printf("%0.8f\n",b);
    e=fabs(b-2.4515)/2.4515*100;
    printf("Error=%f%c",e,'%');
}
//10.01110100       n=8
//10.0111001110     n=10

/*
4_  Q23.8--->2.453125--->error=0.066%
    Q21.10-->2.451172--->error=0.013%
*/