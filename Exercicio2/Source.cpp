/*
* Construa um programa que administre as filas de reservas de um determinado filme de uma v�deo locadora, 
* sendo que existem sete filas, uma para cada dia da semana. Observe que ser�o armazenados o nome do filme com 30
* caracteres e o nome do locador com 50 caracteres.
* O sistema deve permitir que o usu�rio determine qual o dia da semana prefere locar o filme. 
* Remover o usu�rio da lista apenas nos respectivos dias.
*/

#include <stdio.h>
#include <stdlib.h>

#define FILME 30
#define LOCADOR 50
#define NUMEROFILAS 7

//Definindo o elemento b�sico da fila
struct Dados {
	char filme[FILME], nome[LOCADOR];
	struct Dados *anterior;
};

//inst�ncias globais do elemento b�sico da fila
//e para o array que conter� as 7 filas
struct Dados *prim[NUMEROFILAS], *ulti[NUMEROFILAS], *ptr;

//prot�tipos
int menu();
void retirar();
void armazenar();


int main() {
	int op = 1, x;
	//garante que todos os ponteiros dos arrays de struturas estar�o limpos
	for (int i = 0; i < NUMEROFILAS; i++){
		prim[i] = NULL;
		ulti[i] = NULL;
	}
	//mant�m o la�o at� que o usu�rio queira sair
	while (op != 3){
		op = menu();
		switch (op){
		case 1:		
			armazenar();	
			break;
		case 2:
			retirar();		
			break;
		}
	}

	system("Pause");
	return 0;
}

int menu() {
	int op = 0, c = 0;
	printf("Digite 1 para incluir da Fila: \n");
	printf("Digite 2 para retirar da Fila: \n");
	printf("Digite 3 para sair : \n ");
	scanf("%d", &op);
	//sempre limpe o buffer do teclado.
	while ((c = getchar()) != '\n' && c != EOF) {}
	return(op);
}

void retirar() {
	int dia = 0, c = 0;

	puts("Informe o dia da semana: ");
	scanf("%d", &dia);
	//sempre limpe o buffer do teclado.
	while ((c = getchar()) != '\n' && c != EOF) {}

	if (prim[dia] == NULL)
		printf("Nao existem reservas para este dia.\n");
	else {
		puts("Listas das reservas do dia:\n");
		while (prim[dia] != NULL){
			printf("Filme %s, cliente %s\n", prim[dia]->filme, prim[dia]->nome);
			ptr = prim[dia];
			prim[dia] = prim[dia]->anterior;
			//libera a mem�ria alocada para a fila 
			free(ptr);
		}
	}
}

void armazenar()
{
	int dia = 0, c = 0;
	//alocando mem�ria para criar um novo elemento na fila
	ptr = (struct Dados *) malloc(sizeof(struct Dados));

	puts("Informe o filme : ");
	gets_s(ptr->filme);
	puts("Informe o cliente : ");
	gets_s(ptr->nome);
	puts("Informe \n0 para segunda, \n1 para ter�a, \n2 para quarta, \n3 para quinta, \n4 para sexta, \n5 para s�bado, \n6 para domingo.\n");
	
	scanf_s("%d", &dia);
	//sempre limpe o buffer do teclado.
	while ((c = getchar()) != '\n' && c != EOF) {}

	//para fazer a inclus�o na fila correspondente ao dia escolhido
	ptr->anterior = NULL;
	if (prim[dia] == NULL){
		ulti[dia] = prim[dia] = ptr;
	} else {
		ulti[dia]->anterior = ptr;
		ulti[dia] = ptr;
	}
}
