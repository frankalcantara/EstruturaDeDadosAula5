#include <stdio.h>
#include <stdlib.h>

int main() {
	int x, y, teste, aux;
	//apenas para testar as variáveis
	x = 5;
	y = 7;												    
	teste = 21;
	aux = 17;
	//usaremos para imprimir o endereço de uma variável a opção %p do printf
	//e o typecast (void*) para passar este endereço para a tela.
	printf("O valor de x: %d, o endereço de x: %p \n", x, (void*)&x);
	printf("O valor de y: %d, o endereço de y: %p \n", x, (void*)&y);
	printf("O valor de teste: %d, o endereço de teste: %p \n", teste, (void*)&teste);
	printf("O valor de aux: %d, o endereço de aux: %p \n", x, (void*)&aux);

	system("Pause");
	return 0;
}

