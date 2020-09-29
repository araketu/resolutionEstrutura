/*

Construa um programa que receba N números do usuário e insira esses números de forma ordenada em uma lista ligada
Não é permitido a utilização de vetores;

O programa deverá ler números do usuário até que seja digitado o número -1

*/


#include <stdio.h>
#include <stdlib.h>


typedef struct lista
{
    int qtd;
    struct registro *start;
}lista;

typedef struct registro
{
    int valor;
    struct registro *next;
}registro;


int main()
{
    lista *l2;
    l2 = alocaLista();

    menu(l2);

    mostrar(l2,1);


    return 0;
}

lista *alocarLista()
{
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->start = NULL;
    novo->qtd = 0;
    return novo;
}


registro *alocarRegistro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->valor = 0;
    novo->next = NULL;
    return novo;
}


void incluirRegistro(lista *l, int x)
{
    registro *novo , *aux;

    novo= alocarRegistro();
    novo->valor = x;

    if(l->qtd == 0)
    {
        l->start = novo;
    }
    else
    {
        aux = l->start;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->next = novo;

    }
    l->qtd++;
}

void set(lista *l){
    registro *atual, *novo, *anterior;
    
    int num;
    
    novo = (lista *) malloc(sizeof(lista));

    atual = *l;
    anterior = NULL;
    
    printf("Insira um valor: ");
    scanf("%d", &num);
    
    novo->valor = num;
    
    if(atual == NULL){
        novo->next= NULL;
        *p = novo;
    } else{
        while(atual != NULL && atual->valor < num){
            anterior = atual;
            atual = atual->next
        }
        
        novo->next = atual;
        
        if(anterior == NULL){
            *l= novo;
        } else{
            anterior->next = novo;
        }
    }
}


void mostrarLista(lista *l)
{
    registro *aux;

    if(l->start == NULL)
    {
        printf("\n\t Não há elementos para serem mostrados");
    }
    else
    {
        aux = l->start;
        
        while(aux != NULL)
        {
            printf("\n\t Elemento = %d",aux->valor);
            aux = aux->next;
        }
    }    

}



void menu(lista *l)
{
  

    int numero;
    int opcao;

    do
    {
        printf("\n  1 - Incluir Numero");
        printf("\n -1 - Sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Qual numero deseja inserir: ");
            scanf("%d", &numero);
            set(l, numero);
            mostrar(l,1);
            break;

        case -1:
            printf("\n Finalizando sistema! ");
            break;
        default:
            printf("\n Opção invalida");
            break;
        }

    } while (opcao != -1);
}


