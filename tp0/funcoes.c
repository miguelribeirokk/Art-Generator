void flush_in() { 
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

void Criar_Matriz(int matriz[17][77]){
    int i, j;
    for(i=0; i<17; i++){
        for(j=0; j<77; j++){
            matriz[i][j] = 0;
        }
    }
}

void Printar_Matriz(int matriz[17][77]){
    int i, j;
    for(int i=0; i<79; i++){
        printf("-");
    }
    printf("\n");
    for (i=0; i<17; i++){
        printf("|");
        for (j=0; j<77; j++){
            if (matriz[i][j] == 0){
                printf(" ");
            }
            else{
                printf("*");
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

void Figuras_Aleatorias(int matriz[17][77], int opcao2){
    for (int i = 0; i < opcao2; i++){
        int opcao3 = rand() % 3;
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
        }
    }
}

           
    

void menu(int matriz[17][77]){
    do{
        int opcao, opcao2, new_option;
        char continuar;
        system("clear");
        printf("PROGRAMA GERADOR DE OBRA DE ARTE\n");
        printf("================================\n");
        printf("1 - Asterisco simples\n");
        printf("2 - Simbolo de soma com asteriscos\n");
        printf("3 - Letra X com asteriscos\n");
        printf("4 - Figuras aleatorias\n");
        printf("5 ou qualquer outro numero - Obra minha\n");
        printf("================================\n");
        printf("Digite o numero da opcao desejada: \n");
        scanf("%d", &opcao);
        flush_in();
        printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio): \n");
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
                    printf("Obra minha\n");
                    break;
            }
            Printar_Matriz(matriz);
            printf("Continuar? (s/n)\n");
            scanf("%c", &continuar);
            flush_in();
            system("clear");
            if(continuar == 'n'){
                break;
            }
            else if(continuar == 's'){
                printf("Digite uma das opcoes abaixo:\n");
                printf("1 - Refazer o quadro com mesmos valores (exclui as figuras anteriores!)\n");
                printf("2 - Refazer com novos valores\n");
                printf("3 - Inserir novas figuras no quadro\n");
                printf("4 ou qualquer outro - Sair\n");
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


                










            /*else if (continuar == 's'){
                printf("Selecione uma das opcoes abaixo:\n");
                printf("1 - Continuar com mesmo quadro e inserir novas figuras\n");
                printf("2 - Refazer o quadro\n");
                printf("3 - Limpar quadro e continuar com novos valores\n");
                int opcao4;
            scanf("%d", &opcao4);
            flush_in();
            system("clear");
            switch(opcao4){
                case 1:
                    break;
                case 2:
                    for(int i = 0; i < 17; i++){
                        for(int j = 0; j < 77; j++){
                            matriz[i][j] = 0;
                        }
                    }
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
                            printf("Obra minha\n");
                            break;
                    }
                    Printar_Matriz(matriz);
                    break;

                case 3:
                    for(int i = 0; i < 17; i++){
                        for(int j = 0; j < 77; j++){
                            matriz[i][j] = 0;
                        }
                    }
                    printf("Digite o numero da opcao desejada: \n");
                    scanf("%d", &opcao);
                    flush_in();
                    printf("Digite a quantidade de figuras (menor ou igual a zero para aleatorio): \n");
                    scanf("%d", &opcao2);
                    flush_in();
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
                            printf("Obra minha\n");
                            break;
                    }
                    break;
            }
        }
    }*/
   // while(1);
//}

            
            














