/*
* Criar um programa que realize o enfileiramento e desenfileiramento de números inteiros positivos em uma Fila. 
* Para este exercício utilizar um vetor de 10 posições para simular o conceito de Fila. 
* Os números deverão ser colocados e retirados da Fila um a um.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHODAFILA 10

//protótipos
int menu();
void desenfileirar(int [], int *);
void enfileirar(int[], int *);
void listarfila(int[]); //apenas para debug

int main(){
	int x = TAMANHODAFILA - 1, op = 0;
	int vet[TAMANHODAFILA] = {0}; //incializar com zero para respresentar espaço vazio na fila
	
	while (op != 3)	{
		op = menu();
		switch (op){
		case 1:		
			enfileirar(vet, &x);		
			break;
		case 2: 		
			desenfileirar(vet, &x);		
			break;
		case 3:
			listarfila(vet);
			system("Pause");
			break;
		}
	}
}

int menu() {
	int op = 0, c = 0;
	system("cls");//apenas para limpar a tela a cada chamada do menu;
	printf("Informe 1 para enfileirar:\n");
	printf("Informe 2 para desenfileirar:\n");
	printf("Informe 3 para listar a fila:\n");
	printf("Informe 4 para sair:\n");

	scanf("%d", &op);
	//sempre limpe o buffer do teclado.
	while ((c = getchar()) != '\n' && c != EOF) {}

	return(op);
}

void desenfileirar(int vet[], int *x){
	int y = TAMANHODAFILA -1 ;

	if (*x < TAMANHODAFILA){
		printf("Valor: %d \n", vet[9]);
		system("Pause");
		while (*x <= y){
			vet[y] = vet[y - 1];
			y--;
		}
		(*x)++;
	}
	else
		printf("Fila Vazia.");
}

void enfileirar(int vet[], int *x) {
	int c = 0;
	if (*x <= 0) {
		puts("Não há mais espaço na Fila.");
	}
	else {
		puts("Informar Numero: ");
		scanf_s("%d", &vet[*x]);
		//sempre limpe o buffer do teclado.
		while ((c = getchar()) != '\n' && c != EOF) {}
		(*x)--;
	}
}
//para listar a fila do ultimo para o primeiro
void listarfila(int vet[]){
	for ( int i = TAMANHODAFILA-1; i >= 0; i-- ){
		printf("%d\t", vet[i]);
 	}
	printf("\n");
}