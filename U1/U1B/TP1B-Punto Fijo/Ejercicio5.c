#include <stdio.h>
#include <stdint.h>
#include <math.h>

void fp2fxvec(float *x,int32_t *q,int8_t n){
    for(int i=0;i<5;i++){
        q[i]=(int32_t)round(x[i]*(1<<n)); 
    }
}

int32_t fp2fx(float x,int8_t n){
    return round(x*(1<<n));
}

int32_t truncation(int64_t x,int8_t n){
    return (int32_t)(x>>n);
}

void main(){
    float x[5]={1.1,2.2,3.3,4.4,5.5};
    float y[5]={6.6,7.7,8.8,9.9,10.10};
    int64_t acum_64=0;
    int32_t xq[5],yq[5],acum_32a=0,acum_32b=0;
    //2_Convert vectors to Q21.10
    fp2fxvec(x,xq,10);
    fp2fxvec(y,yq,10);

    //3_2 Approachs for MAC 
    for(int i=0;i<5;i++){
        acum_32a+=(int32_t)(truncation((int64_t)(xq[i]*yq[i]),10));
        acum_64+=(int64_t)((int64_t)(xq[i]*yq[i]));
    } 
    acum_32b=(int32_t) truncation(acum_64,10);

    //4_double MAC implementation
    double x_db[5]={1.1,2.2,3.3,4.4,5.5};
    double y_db[5]={6.6,7.7,8.8,9.9,10.10};
    double acum_db=0;
    for(int i=0;i<5;i++){
        acum_db+=x_db[i]*y_db[i];
    }
    printf("%d\n",xq[0]);

    printf("%d\n",acum_32a); //Q21.10 value
    printf("%d\n",acum_32b);
    printf("%d\n",fp2fx(acum_db,10));
    //5_When we truncate before summing up the multiplications we lose precision
    
}