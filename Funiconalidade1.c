#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No
{
    char raca;
    struct No *esquerda;
    struct No *direita;
};
typedef struct No No; 

No* criarArvore()
{
    return NULL;
}

void insert(No** Raiz, char raca2)
{
	if (*Raiz == NULL) {
		*Raiz =(No*)malloc(sizeof(No));
	    (*Raiz)->esquerda=NULL;
	    (*Raiz)->direita=NULL;
	    (*Raiz)->raca=raca2;
	}
	else 
        {
		if (raca2 < (*Raiz)->raca)
		{
			insert(&(*Raiz)->esquerda, raca2);
		}
		else
		{
			insert(&(*Raiz)->direita, raca2);
		}
	}
}

int main(void)
{
	char raca;
	int option = 0;
	printf(" -=> Seja Bem-Vindo ao HELPet <=-\n");
	printf(" 1 - Inserir\n 2 - Consultar\n");
	printf("--------------------------------\n");
	while(option != -1) {
		scanf("%d", &option);
		//inserir
		struct No* Raiz;
		Raiz = criarArvore();
		if(option == 1) {
			printf("Digite a Raca(se tiver) ou a espécie do animal que deseja inserir:\n");
			insert(&Raiz, raca);
		}
		//Buscar
		if(option == 2){
			
		//printf("if do consultar");
		}
	}
	return 0;
}
