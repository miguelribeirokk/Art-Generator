#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//Funcao que limpa o buffer
void flush_in() { 
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

//Funcoes usadas para mudar a cor do texto
void Red(){
    printf("\033[1;31m");
}

void Green(){
    printf("\033[1;32m");
}

void White(){
    printf("\033[0m");
}
 void Pink(){
    printf("\033[1;35m");
 }

 void Blue(){
    printf("\033[1;34m");
 }

void Yellow(){
    printf("\033[1;33m");
}

void Cyan(){
    printf("\033[1;36m");
}

void Black(){
    printf("\033[1;30m");
}


//Funcao que cria a matriz, inicializando com 0 em todas as posicoes
void Criar_Matriz(int matriz[17][77]){
    int i, j;
    for(i=0; i<17; i++){
        for(j=0; j<77; j++){
            matriz[i][j] = 0;
        }
    }
}

//Funcao que imprime a matriz no terminal, se for 0 imprime um espaco, se for 1 imprime um *
void Printar_Matriz(int matriz[17][77]){
    int i, j;
    for(int i=0; i<79; i++){
        printf("-");
    }
    printf("\n");
    for (i=0; i<17; i++){
        printf("|");
        for (j=0; j<77; j++){
            if(matriz[i][j] == 0){
                printf(" ");
            }
            else if(matriz[i][j] == 1){
                printf("*");
            }
            else if(matriz[i][j] == 2){
                int cor = rand()%8;
                if(cor == 0){
                    Red();
                    printf("█");
                    White();

                }
                else if(cor == 1){
                    Green();
                    printf("█");
                    White();

                }
                else if(cor == 2){
                    White();
                    printf("█");
                    White();
                }
                else if(cor == 3){
                    Pink();
                    printf("█");
                    White();
                }
                else if(cor == 4){
                    Blue();
                    printf("█");
                    White();
                }
                else if(cor == 5){
                    Yellow();
                    printf("█");
                    White();
                }
                else if(cor == 6){
                    Cyan();
                    printf("█");
                    White();
                } 
                else if(cor == 7){
                    Black();
                    printf(" ");
                    White();
                }
            }
            
        }
        printf("|\n");
    }
    for(int i=0; i<79; i++){
        printf("-");
    }
    printf("\n");
    return;
}

//Funcao que cria uma arte com asteriscos simples aleatorios
void Asterisco_Simples(int matriz[17][77], int opcao2){
    
    for(int i = 0; i < opcao2; i++){
        do{
            int x = rand() % 17;
            int y = rand() % 77;
            if(matriz[x][y] == 0){
                matriz[x][y] = 1;
                break;
            }
        }
        while(1);  
    }
}

//Funcao que cria uma arte com asteriscos (simbolo de +) aleatorios
void Soma_Asterisco(int matriz[17][77], int opcao2){
    for(int i = 0; i < opcao2; i++){
        do{
            int x = rand() % 17;
            int y = rand() % 77;
            if(matriz[x][y] == 0 && matriz[x+1][y+1] == 0 && matriz[x+1][y]==0 && matriz[x+1][y-1]==0 && matriz [x+2][y] == 0 && x <15 && y <75 && y > 1){
                matriz[x][y] = 1;
                matriz[x+1][y] = 1;
                matriz[x+1][y+1] = 1;
                matriz[x+1][y-1] = 1;
                matriz[x+2][y] = 1;
                break;
            }
        }
        while(1);  
    }
}

//Funcao que cria uma arte com asteriscos (simbolo de X) aleatorios
void X_Asterisco(int matriz[17][77], int opcao2){
    for(int i = 0; i < opcao2; i++){
        do{
            int x = rand() % 17;
            int y = rand() % 77;
            if(matriz[x][y] == 0 && matriz[x+1][y+1] == 0 && matriz[x+2][y+2] == 0 && matriz[x][y+2] == 0 && matriz[x+2][y] == 0 && x <15 && y <75 && y > 1){
                matriz[x][y] = 1;
                matriz[x+1][y+1] = 1;
                matriz[x+2][y+2] = 1;
                matriz[x][y+2] = 1;
                matriz[x+2][y] = 1;
                break;

            }
        }
        while(1);
    }
}

//Funcao que cria uma arte com blocos aleatorios coloridos
void Arte_Colorida(int matriz[17][77], int opcao2){
    for(int i = 0; i < opcao2; i++){
        do{
            int x = rand() % 17;
            int y = rand() % 77;
            if(matriz[x][y] == 0){
                matriz[x][y] = 2;
                break;
            }
        }
        while(1);
    }
}

//Funcao que cria uma arte com asteriscos (mistura das anteriores) aleatorios
void Figuras_Aleatorias(int matriz[17][77], int opcao2){
    for (int i = 0; i < opcao2; i++){
        int opcao3 = rand() % 4;
        switch(opcao3){
            case 0:
                Asterisco_Simples(matriz, 1);
                break;
            case 1:
                Soma_Asterisco(matriz, 1);
                break;
            case 2:
                X_Asterisco(matriz, 1);
                break;
            case 3:
                Arte_Colorida(matriz, 1);
                break;
        }
    }
}




    

           
    
//Menu de opcoes do usuario, onde ele escolhe o tipo de arte que deseja criar e como ela sera criada
void menu(int matriz[17][77]){
    do{
        int opcao, opcao2, new_option, escolha;
        char continuar;
        system("clear");
        printf("PROGRAMA GERADOR DE OBRA DE ARTE\n");
        printf("================================\n");
        printf("1 - Asterisco simples\n");
        printf("2 - Simbolo de soma com asteriscos\n");
        printf("3 - Letra X com asteriscos\n");
        printf("4 - Figuras aleatorias\n");
        printf("Outro - Arte Colorida\n");
        printf("================================\n");
        printf("Digite o numero da opcao desejada: \n");
        scanf("%d", &opcao);
        flush_in();
        printf("Digite a quantidade de figuras (<= 0 aleatorio | MAX 100): \n");
        scanf("%d", &opcao2);
        flush_in();
        if (opcao2 <= 0){
            opcao2 = rand() % 100;
        }
        if(opcao2 >= 100){
            opcao2 = 100;
        }
        do{
            switch(opcao){
                case 1:
                    Asterisco_Simples(matriz, opcao2);
                    break;
                case 2:
                    Soma_Asterisco(matriz, opcao2);
                    break;
                case 3:
                    X_Asterisco(matriz, opcao2);
                    break;
                case 4:
                    Figuras_Aleatorias(matriz, opcao2);
                    break;
                default:
                    printf("1 - Completar a imagem\n");
                    printf("2 - Apenas %d figuras\n", opcao2);
                    scanf("%d", &escolha);
                    flush_in();
                    if(escolha == 1){
                        for(int i = 0; i < 17; i++){
                            for(int j = 0; j < 77; j++){
                                if(matriz[i][j] == 0){
                                    matriz[i][j] = 2;
                                }
                            }
                        }
                        return;
                    }
                    else{
                        Arte_Colorida(matriz, opcao2);
                        break;
                    }
                    
                    
            }
            Printar_Matriz(matriz);
            printf("Aperte ENTER para continuar\n");
            getchar();
            system("clear");    
            printf("Digite uma das opcoes abaixo:\n");
            printf("1 - Refazer o quadro com mesmos valores |exclui as figuras anteriores!|\n");
            printf("2 - Refazer com novos valores\n");
            printf("3 - Inserir novas figuras no quadro\n");
            printf("Outro - Sair\n");
            scanf("%d", &new_option);
            flush_in();
            if(new_option == 1){
                Criar_Matriz(matriz);
                continue;
            }
            else{
                break;
            }
        }
        while(1);
        if(new_option == 2){
            Criar_Matriz(matriz);
            continue;
        }
        else if(new_option == 3){
            continue;
        }
        else{
            break;
        }
    }
    while(1);
    return;
}


 
