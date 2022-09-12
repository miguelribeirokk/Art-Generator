#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "funcoes.c"


int main(){
    int matriz [17][77];
    srand(time(NULL));
    Criar_Matriz(matriz);
    menu(matriz);
    Printar_Matriz(matriz);
    

    
    return 0;
}