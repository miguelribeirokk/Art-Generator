#include "funcoes.h"


int main(){
    int matriz [17][77];
    srand(time(NULL));
    Criar_Matriz(matriz);
    menu(matriz);
    Printar_Matriz(matriz);
    printf("\n");
    printf("Fim do programa, vc e um artista!!\n");

    return 0;
}
