#include <stdio.h>
#include <stdlib.h>

void hacerCosas(int* a){
	int i = 0;
	int valor = 50;
	while(a[i] != 
		a[i] = valor;
		valor-=1;
		i+=1;
	}
}


int main(){

	int elefante = 1;

	printf("elefante antes:   %d\n", elefante);

	hacerCosas(&elefante);

	printf("elefante despues: %d\n", elefante);

	return 0;
}