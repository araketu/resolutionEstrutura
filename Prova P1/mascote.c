#include <stdio.h>

typedef struct mascote {
    int matricula;
    int codigo;
    int idade;
}mascote;

void coletar_dados();

int main() {

    struct mascote animal;
    printf("Digite os dados do seu pet: \n");
    coletar_dados(animal);

    return 0;
}

void coletar_dados(mascote mascote1) {
    printf("Digite a matricula do pet: ");
    scanf("%d", &mascote1.matricula);
    printf("Digite o codigo do pet: ");
    scanf("%d", &mascote1.codigo);
    printf("Digite a idade do pet: ");
    scanf("%d", &mascote1.idade);
}