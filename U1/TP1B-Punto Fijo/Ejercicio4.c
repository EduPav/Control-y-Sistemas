#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int32_t saturation(int32_t a, int32_t b){
    if(a>0){
        if(INT_MAX-a<b){
            return INT_MAX;
        } 
    }
    else if(b<INT_MIN-a){
        return INT_MIN;
    }
    return a+b;
}

void main(){

    int32_t a,b;
    a=2000000000;
    b=1000000000;

    printf("%d",saturation(a,b));

}