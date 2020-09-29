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

// void menu();
lista *alocarLista();
registro *alocarRegistro();
void mostrarLista(lista *l);
int size(lista *l);

int main()
{
    int i, num;
    
    lista *listaPrincipal, *lista_de_pares, *lista_de_impares;

    listaPrincipal = alocarLista();
    lista_de_pares = alocarLista();
    lista_de_impares = alocarLista();
    
    // menu(listaPrincipal);
    i=0;
    while(i != 10)
    {
        printf("\n Qual numero deseja inserir: ");
        scanf("\n %d", &num);

        if(num % 2 ==0)
        {
            incluirRegistro(lista_de_pares, num);
        }
        else
        {
            incluirRegistro(lista_de_impares, num);
        }


        // incluirRegistro(listaPrincipal, num);
        // mostrarLista(listaPrincipal);

    i++;    
    }

    int par, impar;

    par = size(lista_de_pares);
    impar = size(lista_de_impares);
    
    if(par == impar){

        printf("\n Lista iguais");
    }else if (par > impar)
    {
        mostrarLista(lista_de_pares);
    
    }else if (impar > par)
    {
        mostrarLista(lista_de_impares);
    }
    
    
    
    


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

int size(lista *l)
{
    registro *aux;
    int count = 0;

    if(l->start == NULL)
    {
        return 0;
    }
    else
    {
        aux = l->start;

        while(aux != NULL)
        {
            count++;
            aux = aux ->next;
        }
        return count;
    }
    
}

