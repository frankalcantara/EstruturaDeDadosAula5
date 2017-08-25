/*
* Exemplo da estrutura pilha (stack) usando como estrutura e armazenamento um array unidimensional
* Neste exemplo temos as fun��es b�sicas de uma pilha, fun��es de pop e push. 
* e uma fun��o para listar a pilha apenas para verificar o que est� acontecendo.
* Uma pilha seguindo a regra �ltimo a entrar, primeiro a sair.
*/
#include <stdio.h>
#include <stdlib.h>

#define TAMANHOPILHA 200

int stack[TAMANHOPILHA] = { -1 }; //array para conter a pilha preenchido com -1 para a indicar posi��o vazia
int top;	//inteiro que conter� o topo da pilha

 //prot�tipos 
void push(int);
int pop();
void listar();

int main(){
	
	int opcao = 1,  num, c = 0;
	
	while (opcao == 1){
		//um menu para testar a pilha
		printf("MAIN MENU: \n"); 
		printf("1.Adicionar elemento.\n");	
		printf("2.Remover elemento.\n");
		printf("Sua escolha: ");

		scanf_s("%d", &opcao);
		//sempre limpe o buffer do teclado.
		while ((c = getchar()) != '\n' && c != EOF) {}

		switch (opcao){
			case 1:
					printf("Digite o elemento... ");
					scanf("%d", &num);
					//sempre limpe o buffer do teclado.
					while ((c = getchar()) != '\n' && c != EOF) {}
					//colocando o elemento na pilha
					push(num);
					//vamos listar a pilha s� para testes
					listar();
					break;
			case 2: 
					//buscando o valor no topo da pilha
					printf("O valor no topo da pilha: %d\n", pop());
					//vamos listar a pilha s� para testes
					listar();
					break;
			default: 
				printf("ESCOLHA INVALIDA...");
		}

		printf("Deseja fazer novas operacoes na pilha (1 para sim, 2 para nao)?\n");
		scanf("%d", &opcao);
		//sempre limpe o buffer do teclado.
		while ((c = getchar()) != '\n' && c != EOF) {}
		
		//vamos limpar a tela a cada opera��o
		system("cls");
	} 

	system("Pause");
	return 0;
}

//fun��o push, coloca um elemento na pilha
void push(int y){

	if (top > TAMANHOPILHA){
		printf("Pilha Cheia");
		return;
	}	else {
		stack[top] = y;
		top++;
	}

}
//fun��o pop, retira um elemento da pilha
int pop(){
	int a;
	if (top <= 0){
		printf("PILHA VAZIA");
		return 0;
	}	else {
		top--;
		a = stack[top];
		stack[top] = -1;
	}
	return(a);
}

void listar() {
	printf("A pilha atual:\n");
	for (int i = 0; i < TAMANHOPILHA; i++) {
		if (stack[i] <=0)	{
			break;
		}
		printf("%d\n", stack[i]);
	}

}