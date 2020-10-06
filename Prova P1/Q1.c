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
void mostrarLista(lista *l);
void incluirInicio(lista *l, int x);
void incluirFinal(lista *l, int x);
void removerRegistro(lista *l, int x);




int main(){


    int opcao, num;
    lista *l1,*l2;
    l1 = alocarLista();
    l2 = alocarLista();
  
    do
    {
        printf("\n 1 - Inserir no inicio da lista 1");
        printf("\n 2 - Inserir no inicio da lista 2");
        printf("\n 3 - inserir no final da lista 1");
        printf("\n 4 - inserir no final da lista 2");
        printf("\n 5 - Remover número da lista 1");
        printf("\n 6 - Remover número da lista 2");
        printf("\n 7 - Mostrar Lista 1");
        printf("\n 8 - Mostrar Lista 2");
        printf("\n 9 - Fechar Aplicação\n");
        printf("\n\nDigite uma opção:");

        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n\nDigite um numero: ");
            scanf("%d",&num);
            incluirInicio(l1,num); 
            break;
        case 2:
            printf("\n\nDigite um numero: ");
            scanf("%d",&num);
            incluirInicio(l2,num);             
            break;
        case 3:
            printf("\n\nDigite um numero: ");
            scanf("%d",&num);
            incluirFinal(l1,num);            
            break; 
        case 4:
            printf("\n\nDigite um numero: ");
            scanf("%d",&num);
            incluirFinal(l2,num);               
            break;            
        case 5:
            printf("\n\nDigite um numero: ");
            scanf("%d",&num);
            removerRegistro(l1,num);
            break; 
        case 6:
            printf("\n\nDigite um numero: ");
            scanf("%d",&num);
            removerRegistro(l2,num);
            break; 
        case 7:
            printf("\n\nLista 1: ");
            mostrarLista(l1);
            break;
        case 8:
            printf("\n\nLista 2:");
            mostrarLista(l2);
            break;
        case 9:
            printf("\n\nFechando aplicação");
            break;    
        default:
            printf("\n Opção Invalida");
        }
  
    }while (opcao != 9);

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
        
    }else{
       novo->next= l->start;
       l->start = novo;
    }
    l->qtd++;
}


void incluirFinal(lista *l, int x){

    registro *novo, *aux;

    novo =alocarRegistro();
    novo->valor = x;

    if(l->qtd==0){
        l->start = novo;
        
    }else{
        aux = l->start;
        while(aux->next !=NULL){
            aux = aux -> next;
        }
        aux->next=novo;

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

void removerRegistro(lista *l, int x)
{
    registro *aux = NULL, *after = NULL;

    if (l->start == NULL)
    {   
        printf("\nLista vazia!");
        return;
    }
    else
    {
        aux = l->start;

        while (aux != NULL)
        {
            if (aux->valor == x)
            {
                if (after == NULL)
                {
                    l->start = aux->next;
                }
                else
                {
                    after->next = aux->next;
                }
                free(aux);
                l->qtd--;
                return;
            }
            else
            {
                after = aux;
                aux = aux->next;
            }
        }

        printf("Valor não consta na lista");

        return;
    }
}