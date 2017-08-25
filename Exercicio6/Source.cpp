/*
* Criar um programa, com alocação dinâmica de memória, que receba nomes e números vindos via teclado
* e armazene em uma “Fila” até o limite de 10 dados armazenados.
* Quando chegar ao limite, automaticamente o programa deverá retirar todos os elementos possíveis da “Fila”
* e transferir para uma “Pilha”.
* Quando o usuário desejar a retirar dos dados, retirar primeiro o que tem na “Pilha” e em seguida da “Fila”.
* Os dados de saída deverão ser apresentados na tela.
*/

#include <stdio.h>									  
#include <stdlib.h>

#define TAMANHONOME 30
#define TAMANHOPILHA 10

//a estrutura para armazenar os dados
struct Dados{
	char nome[TAMANHONOME];
	int codigo;
	struct Dados *ante;
};
struct Dados *prim_fila, *ulti_fila, *ulti_pilha, *ptr;

//protótipos
int menu();
void retirar();
void transferir();
void incluir(int *);


int main(){
	int op = 1, qtd = 0;

	prim_fila = NULL;
	ulti_fila = NULL;
	ulti_pilha = NULL;

	while ( op != 3 ){
		op = menu();
		switch ( op ){
			case 1:		
				incluir(&qtd);
				break;
			case 2:
				retirar();
				qtd = 0;		
				break;
		}
	}
	system("Pause");
	return 0;
}

int menu(){
	int op;
	printf("Digite 1 para incluir:\n");
	printf("Digite 2 para retirar:\n");
	printf("Digite 3 para sair:\n");
	scanf("%d", &op);
	return(op);
}

void retirar(){
	while ( ulti_pilha != NULL ){
		printf("Nome: %s, Código : %d\n", ulti_pilha->nome, ulti_pilha > codigo);
		ptr = ulti_pilha->ante;
		ulti_pilha = ulti_pilha->ante;
		free(ptr);
	}
	while ( prim_fila != NULL ){	
		printf("Nome: %s, Código : %d\n", prim_fila->nome, prim_fila > codigo);
		ptr = prim_fila->ante;
		prim_fila = prim_fila->ante;
		free(ptr);
	}
	ulti_fila = NULL;
}

void incluir(int *qtd){
	if ( *qtd >= 10 ){
		transferir();
		qtd = 0;
		ulti_fila = NULL;
	} else{
		ptr = (struct Dados *) malloc(sizeof(struct Dados));
		puts("Informar Nome:");
		gets_s(ptr->nome);
		puts("Informe Código:");
		scanf("%d", ptr->codigo);

		ptr->ante = NULL;

		*qtd++;
		if ( prim_fila == NULL ){
			prim_fila = ptr;
			ulti_fila = ptr;
		} else{
			ulti_fila->ante = ptr;
			ulti_fila = ptr;
		}
	}
}



void transferir(){
	while ( prim_fila != NULL ){
		ulti_pilha->ante = prim_fila;
		ulti_pilha = prim_fila;
		prim_fila = prim_fila->ante;
		ulti_pilha->ante = NULL;
	}
}

