#include <stdio.h>
#include <stdlib.h>


// Lista Ligada

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

// Lista Dupla Ligada

typedef struct ldupla
{
    int qtd;
    struct registro *start;
    struct registro *end;

} ldupla;

typedef struct rdupla
{
    int valor;
    struct registro *next;
    struct registro *after;
} rdupla;



lista *alocarLista();
registro *alocarRegistro();
void mostrarLista(lista *l);
ldupla *alocaListadl();
rdupla *alocaRegistrodl();
void incluirDupla(ldupla *l, int x);
void mostrardupla(ldupla *l);
int primo(int x);


int main(){

    int n1,n2,i,nprimo;
    lista *lista_primo;
    ldupla *lista_3;

    lista_primo = alocarLista();
    lista_3 = alocaListadl();


    printf("\n\nN1 deve ser menor que N2");    
    printf("\n\nDigite o valor de N1: ");
    scanf("%d",&n1);
    printf("\n\nDigite o valor de N2: ");
    scanf("%d",&n2);

    for(i=n1;i<=n2;i++){


        nprimo = primo(i);

        if(i %3 ==0){
            incluirDupla(lista_3,i);
        }
        if(nprimo ==1){
            incluirRegistro(lista_primo,i);
        }


    }

    printf("\n\nLista de Primos: ");
    mostrarLista(lista_primo);
    printf("\n\nLista de multiplos de 3: ");
    mostrardupla(lista_3);


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



// Lista Dupla Ligada



ldupla *alocaListadl()
{
    ldupla *novo;
    novo = (ldupla *)malloc(sizeof(ldupla));
    novo->qtd = 0;
    novo->start = NULL;
    novo->end = NULL;
    return novo;
}

rdupla *alocaRegistrodl()
{
    rdupla *novo;
    novo = (rdupla*)malloc(sizeof(rdupla));
    novo->valor = 0;
    novo->next = NULL;
    novo->after = NULL;
    return novo;
}

void incluirDupla(ldupla *l, int x)
{
    rdupla *aux, *novo;
    novo = alocaRegistrodl();
    novo->valor = x;

    if (l->qtd == 0)
    {
        l->start = novo;
        l->end = novo;
    }
    else
    {
        aux = l->start;
        aux->after = novo;
        novo->next = aux;
        l->start = novo;
    }

    l->qtd++;
}

void mostrardupla(ldupla *l)
{
    rdupla *aux;
    if (l->start == NULL)
    {
        printf("\nNão há elementos para serem mostrados");
    }
    else
    {
        aux = l->start;
        while (aux != NULL)
        {
            printf("\nElemento = %d", aux->valor);
            aux = aux->next;
        }
    }
}


int primo(int x)
{
    int div;
    if (x == 1)
    {
        return 0;
    }
    else
    {
        if (x < 0)
        {
            x = x * (-1);
        }
        for (div = 2; div < x; div++)
        {
            if (x % div == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}