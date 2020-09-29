/*

Construa um programa que insira números em uma lista duplamente ligada.
O usuário poderá escolher se deseja incluir o número no ínício da lista ou no final da lista;



*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
    struct registro *fim;

} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
    struct registro *ant;
} registro;


void menu(lista *l);
void mostrar(lista *l, int opcao);
void setTail(lista *l, int x);
void setHead(lista *l, int x);
lista *alocaLista();
registro *alocaRegistro();



int main()
{
    lista *l2;
    l2 = alocaLista();

    menu(l2);

    mostrar(l2,1);

    return 0;
}

lista *alocaLista()
{
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    novo->fim = NULL;
    return novo;
}

registro *alocaRegistro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}


void setTail(lista *l, int x)
{
    registro *aux;
    registro *novo;

    novo = alocaRegistro();
    novo->valor = x;

    if (l->qtd == 0)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        aux = l->fim;
        aux->prox = novo;
        novo->ant = aux;
        l->fim = novo;
    }

    l->qtd++;
}

void setHead(lista *l, int x)
{
    registro *aux, *novo;
    novo = alocaRegistro();
    novo->valor = x;

    if (l->qtd == 0)
    {
        l->inicio = novo;
        l->fim = novo;
    }
    else
    {
        aux = l->inicio;
        aux->ant = novo;
        novo->prox = aux;
        l->inicio = novo;
    }

    l->qtd++;
}


void mostrar(lista *l, int opcao)
{
    registro *aux;

    if (l == NULL)
    {
        printf("\n parametro invalido\n");
        return;
    }
    if (opcao != 1 && opcao != 2)
    {
        printf("\nparametro invalido\n");
        return;
    }

    if (l->qtd == 0)
    {
        printf("\n Lista vazia");
    }
    else
    {

        if (opcao == 1)
        {
            aux = l->inicio;
        }
        else
        {
            aux = l->fim;
        }

        while (aux != NULL)
        {
            printf("\n %d", aux->valor);
            if (opcao == 1)
            {
                aux = aux->prox;
            }
            else
            {
                aux = aux->ant;
            }
        }
    }
}

void menu(lista *l)
{
  

    int numero;
    int opcao;

    do
    {
        printf("\n 1 - Incluir no Inicio");
        printf("\n 2 - Incluir no Final");
        printf("\n 3 - Sair");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n Qual numero deseja inserir: ");
            scanf("%d", &numero);
            setHead(l, numero);
            mostrar(l,1);
            break;
        case 2:
            printf("\n Qual numero deseja inserir: ");
            scanf("%d", &numero);
            setTail(l,numero);
            mostrar(l,1);            
            break;

        case 3:
            printf("\n Finalizando sistema! ");
            break;
        default:
            printf("\n Opção invalida");
            break;
        }

    } while (opcao != 3);
}