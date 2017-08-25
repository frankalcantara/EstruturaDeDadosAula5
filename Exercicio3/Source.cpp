/*
* Para que os produtos alimentícios de uma determinada distribuidora não fiquem acumulados por muito tempo no estoque,
* o gerente deseja um programa que gerencia a entrada e saída dos alimentos.
* Deste modo, crie um programa que utilize o conceito de Fila para gerenciar a entrada e a saída dos produtos do estoque.
* os produtos serão cadastrados por código, com 30 caracteres e data com 10 caracteres.
* Esta distribuidora possui somente 7 produtos (Feijão, Arroz, Milho, Farinha, Fubá, Azeite, Macarrão).
*	O sistema deverá permitir:
*			a.	Incluir os produtos em suas respectivas filas;
*			b.	Retirar os produtos das filas de acordo com a necessidade e quantidade.
*	Considere que os produtos serão mantidos em duas filas, uma de entrada e outra de saída. 
* Neste programa, a retirada de um produto significa que ele sais da fila de entrada e vai para a fila de saída.
* Considere também que o usuário pode resolver tirar diversos itens de uma mesma fila.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHOCODIGO 30
#define TAMANHODATA 10
#define TAMANHOFILA 7
//vamos criar uma struct para armazenar os dados
struct Dados{
	char codigo[TAMANHOCODIGO], data[TAMANHODATA];
	struct Dados *anterior;
};
//criandos os arrays e uma struct temporária
struct Dados *prim[TAMANHOFILA], *ulti[TAMANHOFILA], *ptr;

//protótipos
int menu();
int Submenu();
void retirar();
void armazenar();

int main(){
	int op = 1;
	//preenchendo as duas filas com ponteiros nulos.
	for ( int i = 0; i < TAMANHOFILA; i++ ){
		prim[i] = NULL;
		ulti[i] = NULL;
	}

	while ( op != 3 ){
		op = menu();
		switch ( op ){
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
}	//fim do main

int menu(){
	int op, c;
	//para limpar a tela a cada chamada do menu
	system("cls");
	printf("Digite 1 para incluir da Fila:\n");
	printf("Digite 2 para retirar da Fila:\n");
	printf("Digite 3 para sair:\n ");

	scanf("%d", &op);
	//sempre limpe o buffer do teclado.
	while ( (c = getchar()) != '\n' && c != EOF ){}

	return op;
}

int Submenu(){
	int op , c;
	
	printf("Digite 1 para Feijao:\n");
	printf("Digite 2 para Arroz:\n");
	printf("Digite 3 para Milho:\n");
	printf("Digite 4 para Farinha:\n");
	printf("Digite 5 para Fuba:\n");
	printf("Digite 6 para Azeite:\n");
	printf("Digite 7 para Macarrao:\n");
	printf("Digite 8 para sair:\n");

	scanf("%d", &op);
	//sempre limpe o buffer do teclado.
	while ( (c = getchar()) != '\n' && c != EOF ){}

	return op;
}

void retirar(){
	int prod, qtd, c;

	puts("Para excluir digitar o produto desejado:\n");
	prod = Submenu();
	//para limpar a tela a cada chamada do menu
	system("cls");

	puts("Digite quantos itens deseja excluir: ");
	scanf("%d", &qtd);
	//sempre limpe o buffer do teclado.
	while ( (c = getchar()) != '\n' && c != EOF ){}

	if ( prim[prod] == NULL )
		printf("Este produto nao esta disponivel.\n");
	else
		while ( (qtd > 0) && (prim[prod] != NULL) ){
			printf("Codigo %s, validade %s\n", prim[prod]->codigo, prim[prod]->data);
			ptr = prim[prod];
			prim[prod] = prim[prod]->anterior;
			free(ptr);
			qtd--;
		}
}

void armazenar(){
	int prod;
	//reservando o espaço de memória necessário. 
	//malloc devolve um tipo void que não pode ser passado para um ponteiro
	//então vamos fazer um typecasting e converter o voide para o tipo ponteiro para Dados
	//e podemos criar o ponteiro temporário ptr
	ptr = (struct Dados *) malloc(sizeof(struct Dados));

	puts("Escolha o produto:\n");
	prod = Submenu();
	//para limpar a tela a cada chamada do menu
	system("cls");

	//colocando os dados na struct temporária criada
	puts("Digite Codigo do Produto:");
	gets_s(ptr->codigo);
	puts("Digite a Data de Validade:");
	gets_s(ptr->data);

	ptr->anterior = NULL;
	
	if ( prim[prod] == NULL ){
		//não temos nenhum produto neste array
		//então incluimos nos dois arrays a struct temporária
		ulti[prod] = prim[prod] = ptr;
	} else{
		//já temos um produto no array
		//No array ulti, apontamos o anterior para ptr 
		ulti[prod]->anterior = ptr;
		ulti[prod] = ptr;
	}
}
