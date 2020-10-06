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



lista *alocarLista();
registro *alocarRegistro();
void juntarListas(lista *l1, lista *l2);
void mostrarLista(lista *l);
void incluirRegistro(lista *l, int x);


int main(){

    int i,num;
    lista *lista_1,*lista_2,lista_concatenada;

    lista_1 = alocarLista();
    lista_2 = alocarLista();
    // lista_concatenada = alocarLista();

    for(i=1;i<=5;i++){
        printf("\n\nDigite um numero: ");
        scanf("%d",&num);
        incluirRegistro(lista_1,num);
    }

    for(i=1;i<=5;i++){
        printf("\n\nDigite um numero: ");
        scanf("%d",&num);
        incluirRegistro(lista_2,num);
    }

    juntarListas(lista_1,lista_2);

    mostrarLista(lista_1);

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

void juntarListas(lista *l1, lista *l2)
{
    if (l2->qtd == 0){
        return;
    }

    if (l1->qtd = 0){
        l1->qtd = l2->qtd;
        l1->start = l2->start;
    }
    else{
        l1->start->next = l2->start;
        l1->qtd = l1->qtd + l2->qtd;
    }

    l2->qtd = 0;
    l2->start = NULL;

    return;

}