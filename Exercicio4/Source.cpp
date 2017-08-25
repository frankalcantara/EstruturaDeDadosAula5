/*
* Criar um programa que realize o empilhamento e desempilhamento de números inteiros positivos em uma Pilha.
* Para este exercício utilizar um vetor de 10 posições para simular o conceito de Pilha.
* Neste caso, uma posição de pilha não utilizada deverá conter o valor -1
*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHODAPILHA 10

//prototipos
int menu();
void listar(int[], int *);
void empilhar(int[], int *);
int retirar(int[], int *);


int main(){
	int x = 0; //ponteiro da pilha 
	int c = 0, op = 1;
	int vet[TAMANHODAPILHA];

	while ( op != 3 ){
		op = menu();
		switch ( op ){
			case 1:
				empilhar(vet, &x);
				break;
			case 2:
				printf("foi retirado o numero %d", retirar(vet, &x));
				system("Pause");
				break;
			case 3:
				listar(vet, &x);
				break;
		}
	}
}

int menu(){
	int op = 0, c = 0;
	system("cls");
	printf("Digite 1 para 1mpilhar:\n");
	printf("Digite 2 para retirar:\n");
	printf("Digite 3 para listar:\n");
	printf("Digite 4 para sair:\n");

	scanf("%d", &op);
	//sempre limpe o buffer do teclado.
	while ( (c = getchar()) != '\n' && c != EOF ){}

	return(op);
}
//Esta função irá listar todos os valores da pilha
//serve apenas para testar o tamanho da pilha, 
//considerando o valor apontado.
void listar(int vet[], int *x){
	if ( *x < TAMANHODAPILHA ){
		while ( *x >  0 ){
			printf("Valor: %d \n", vet[*x]);
			(*x)--;
		}
	} else{
		printf("Alguma coisa deu errado!!!\n");
	}
 	system("Pause");
}

void empilhar(int vet[], int *x){
	int c = 0;
	if ( *x >= (TAMANHODAPILHA - 1) ){
		puts("Nao ha mais espaço na Pilha.\n");
	} else{
		puts("Informar Número: ");
		(*x)++;
		scanf("%d", &vet[*x]);
		//sempre limpe o buffer do teclado.
		while ( (c = getchar()) != '\n' && c != EOF ){}

	}
}

//vai retirar um valor da pilha
int retirar(int vet[], int *x){
	int retirado = 0;
	if ( *x >0 && *x < TAMANHODAPILHA ){
				retirado = vet[*x];
				(*x)--;
	}
	return retirado;
}