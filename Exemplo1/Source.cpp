#include <stdio.h>
#include <stdlib.h>

int main() {
	int x, y, teste, aux;
	//apenas para testar as vari�veis
	x = 5;
	y = 7;												    
	teste = 21;
	aux = 17;
	//usaremos para imprimir o endere�o de uma vari�vel a op��o %p do printf
	//e o typecast (void*) para passar este endere�o para a tela.
	printf("O valor de x: %d, o endere�o de x: %p \n", x, (void*)&x);
	printf("O valor de y: %d, o endere�o de y: %p \n", x, (void*)&y);
	printf("O valor de teste: %d, o endere�o de teste: %p \n", teste, (void*)&teste);
	printf("O valor de aux: %d, o endere�o de aux: %p \n", x, (void*)&aux);

	system("Pause");
	return 0;
}

