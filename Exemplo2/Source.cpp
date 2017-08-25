#include <stdlib.h>
#include <stdio.h>
	   
int main() {
	//inicializando as váriáveis
	int x = 5, y = 7, teste = 21, aux = 17;
	//criando variáveis do tipo ponteiro,
	//armazenam endereços
	int *px, *py;
	// a variável px recebe o endereço da variável x
	px = &x;
	// a variável py recebe o endereço da variável y
	py = &y;

	//imprimimos a diferença entre os endereços em py e px
	printf("py – px = %u\n", py - px);
	//imprimimos o endereço armazenado em px, o valor apontado por este endereço e o endereço de px
	// novamente o endereço de px
	printf("px = %u, *px = %d, &px = %p \n", px, *px, (void*)&px);
	//o mesmo para py
	printf("py = %u, *py = %d, &py = %p \n", py, *py, (void*)&py);

	//vamos incrementar px, como ele armazena um endereço vamos 
	//incrementar este endereço. 
	px++;

	//imprimimos o endereço armazenado em px, o valor apontado por este endereço e o endereço de px
	printf("px = %u, *px = %d, &px = %p \n", px, *px, (void*)&px);
	//observe que o endereço armazenado em px foi incrementado de 4
	//bytes já que neste ambiente um int ocupa 4 bytes de memória

	//vamos atribuir a py o resultado do endereço armazenado em px + 3 
	py = px + 3;

	//imprimimos o endereço armazenado em py, o valor apontado por este endereço e o endereço de py
	printf("py = %u, *py = %d, &py = %p \n", py, *py, (void*)&py);
	//subtração entre dois endereços.
	printf("py – px = %p\n", (void*)(py - px));

	system("Pause");
	return 0;
}
