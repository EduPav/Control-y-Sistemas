// Version: 002
// Date:    2022/04/05
// Author:  Rodrigo Gonzalez <rodralez@frm.utn.edu.ar>

// Compile usando el siguiente comando
// compile: gcc -Wall -std=c99 ex_01.c -o ex_01

#include <stdio.h>
#include <float.h>
#include <math.h>
#include <fenv.h>

typedef long int int64_t;

int main(void)
{	
	float a, b, c, f1, f2;  //32 bits
	double d1;				//64 bits

	a = 1000000000.0;	// mil millones 1e9
	b =   20000000.0;	// 20 millones 2e7
	c =   20000000.0;
	
	f1 = (a * b) * c;
	f2 = a * (b * c);

	d1 = (double) (a) * (double) (b) * (double) (c);

	printf("f1 = %lf \n", f1 );
	printf("f2 = %lf \n", f2 );
	printf("d1 = %lf \n", d1 );
	
	printf("Error en f1 = %10e \n", f1 - 400000000000000000000000.0 );
	printf("Error en f2 = %10e \n", f2 - 400000000000000000000000.0 );
	printf("Error en d1 = %20e \n", d1 - 400000000000000000000000.0 );
	
	double acum_1, acum_2;
	
	acum_1 = 0.0;
	for (int64_t i = 0; i < 10000000; i++){ acum_1 += 0.01; } 

	acum_2 = 0.0;
	b = 0.333;
	for (int64_t i = 0; i < 10000000; i++){ acum_2 += b / b; }
	
	printf("acum_1 = %f \n", acum_1 );
	printf("acum_2 = %f \n", acum_2 );
	
	printf("Error en acum_1 = %10e \n", acum_1 - (100000.0));
	printf("Error en acum_2 = %10e \n", acum_2 - (10000000.0));
	
	return 0;
}


//1_El objetivo del programa es contrastar la precisión de trabajar en double(64 bits) contra la de float(32bits).

//2_En primera instancia vemos que la representación de 4e23 de f1,f2(float) es menos precisa a la de d1(double)
//Al observar los errores notamos que la mejor representación que logra el compilador es double, ya que indica 
//un error de cero, aunque en la realidad esto no es así.

//Vemos que el proceso de acum_2 es más preciso que el acum_1. Esto es porque sumar 1 en el caso del acum_2 
//tiene representación exacta en double, pero sumar 0,01 en el acum_1 no es exacto y acumula error al final.

//3_Lo óptimo en caso de trabajar con números que exijan gran precisión es utilizar double, pero aun  así se 
//estará cometiendo un error por ser esta una representación finita.