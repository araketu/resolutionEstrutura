/*

Construa um programa que insira números em uma lista ligada.
O usuário poderá escolher se deseja incluir o número no ínício da lista ou no final da lista;



*/


#include <stdio.h>
#include <stdlib.h>


typedef struct lista
{
    int qtd;
    struct registro *start;
    struct registro *last;
}lista;

typedef struct registro
{
    int valor;
    struct registro *next;
    struct registro *after;

}registro;

// void menu();
lista *alocarLista();
registro *alocarRegistro();
void mostrarLista(lista *l);
void incluirInicio(lista *l, int x);
void incluirFinal(lista *l, int x);

int main()
{

    int opcao;
    int num;
    lista *l1;
    l1 = alocarLista();
  
    do
    {
        printf("\n 1 - Incluir no Inicio");
        printf("\n 2 - Incluir no Final");
        printf("\n 3 - Sair\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n\nDigite um número: ");
            scanf("%d",&num);
            incluirInicio(l1,num);
            mostrarLista(l1);
            break;
        case 2:
            printf("\n\nDigite um número: ");
            scanf("%d",&num);
            incluirFinal(l1,num);
            mostrarLista(l1);
            break;
        case 3:
            printf("\n Sistema Finalizado!!");
            break;       
        default:
            printf("\n opcao invalida");
        }
  
    }while (opcao != 3);

    printf("\n");
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


void incluirInicio(lista *l, int x){

    registro *novo, *aux;

    novo =alocarRegistro();
    novo->valor = x;

    if(l->qtd==0){
        l->start = novo;
        l->last = novo;
    }else{
        aux = l->start;
        aux->after = novo;
        novo->next = aux;
        l -> start = novo;
    }
    l->qtd++;
}

void incluirFinal(lista *l, int x){

    registro *novo, *aux;

    novo =alocarRegistro();
    novo->valor = x;

    if(l->qtd==0){
        l->start = novo;
        l->last = novo;
    }else{
        aux = l->last;
        aux->next = novo;
        novo->after = aux;
        l -> last= novo;
    }
    l->qtd++;
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

