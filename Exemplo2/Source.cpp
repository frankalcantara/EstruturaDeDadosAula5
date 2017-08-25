#include <stdlib.h>
#include <stdio.h>
	   
int main() {
	//inicializando as v�ri�veis
	int x = 5, y = 7, teste = 21, aux = 17;
	//criando vari�veis do tipo ponteiro,
	//armazenam endere�os
	int *px, *py;
	// a vari�vel px recebe o endere�o da vari�vel x
	px = &x;
	// a vari�vel py recebe o endere�o da vari�vel y
	py = &y;

	//imprimimos a diferen�a entre os endere�os em py e px
	printf("py � px = %u\n", py - px);
	//imprimimos o endere�o armazenado em px, o valor apontado por este endere�o e o endere�o de px
	// novamente o endere�o de px
	printf("px = %u, *px = %d, &px = %p \n", px, *px, (void*)&px);
	//o mesmo para py
	printf("py = %u, *py = %d, &py = %p \n", py, *py, (void*)&py);

	//vamos incrementar px, como ele armazena um endere�o vamos 
	//incrementar este endere�o. 
	px++;

	//imprimimos o endere�o armazenado em px, o valor apontado por este endere�o e o endere�o de px
	printf("px = %u, *px = %d, &px = %p \n", px, *px, (void*)&px);
	//observe que o endere�o armazenado em px foi incrementado de 4
	//bytes j� que neste ambiente um int ocupa 4 bytes de mem�ria

	//vamos atribuir a py o resultado do endere�o armazenado em px + 3 
	py = px + 3;

	//imprimimos o endere�o armazenado em py, o valor apontado por este endere�o e o endere�o de py
	printf("py = %u, *py = %d, &py = %p \n", py, *py, (void*)&py);
	//subtra��o entre dois endere�os.
	printf("py � px = %p\n", (void*)(py - px));

	system("Pause");
	return 0;
}
