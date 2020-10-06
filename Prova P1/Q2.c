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



int main(){

    int num,opcao;
    lista *lista_geral;
    ldupla *lista_de_pares, *lista_de_impares;

    lista_geral = alocarLista();
    lista_de_impares = alocaListadl();
    lista_de_pares = alocaListadl();

    do
    {
        printf("\n 1 - Incluir");
        printf("\n-1 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n\nDigite um mumero: ");
            scanf("%d",&num);
            incluirRegistro(lista_geral, num);

            if(num % 2 ==0){
                incluirDupla(lista_de_pares, num);
            }else{
                incluirDupla(lista_de_impares, num);
            }
            break;

        case -1:
            printf("\n Sistema Finalizado!!");
            break;       
        default:
            printf("\n opcao invalida");
        }
  
    }while (opcao != -1);



    printf("\n\n Lista Geral: ");
    mostrarLista(lista_geral);
    printf("\n\n Lista de pares: ");
    mostrardupla(lista_de_pares);
    printf("\n\nLisra de Impares: ");
    mostrardupla(lista_de_impares);



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
