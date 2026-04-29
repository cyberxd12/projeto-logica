#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void menu(){

    printf("insira a opção desejada: \n1 - jogo da velha\n2 - Palavras cruzadas\n3- jogo da forca\n0 - para sair\n");
}

void old_game(){
    int vidap1 = 9,vidap2 = 9;
    int game[3][3];
    int jogadaColuna,jogadaLinha;
    
    
    for(int i = 0; i < 3;i++){
            for(int c = 0;c < 3;c++){
                game[i][c] = 2; 
        }
    }
    
    printf("como jogar:\ncada jogador tera seu turno.\nescolha a posição que sera jogado na sua vez.\na posição deve ser colocada em um quadrado 3x3.\nexemplo de escolha:\ncoluna: 3\nlinha: 2\n");
    for(int c = 0;c<9;c++){
        
        for(int i = 0; i < 3;i++){
            for(int c = 0;c < 3;c++){
                printf("[%i] ", game[i][c]); 
        }
        printf("\n");
    }
        if(c%2==0){
            printf("\nturno %d\n,Vez do Jogador O - Escolha uma posição.\n", c);
            printf("linha: ");
            scanf(" %i", &jogadaLinha);
            printf("coluna: ");
            scanf(" %i", &jogadaColuna);
            if(game[jogadaLinha-1][jogadaColuna-1] != 1 && game[jogadaLinha-1][jogadaColuna-1] != 0){
                game[jogadaLinha-1][jogadaColuna-1] = 1;
                printf("o jogador x jogou na posição %i x %i o valor %i\n", jogadaLinha, jogadaColuna, game[jogadaLinha][jogadaColuna]);
            }else{
                printf("\njá foi jogado nesse lugar\n\n");
                c--;
            }
            
        }else{
            printf("turno %d\nVez do Jogador X - Escolha uma posição.\n", c);
            printf("linha: ");
            scanf(" %i", &jogadaLinha);
            printf("coluna: ");
            scanf(" %i", &jogadaColuna);
            
            
            if(game[jogadaLinha-1][jogadaColuna-1] != 1 && game[jogadaLinha-1][jogadaColuna-1] != 0){
                game[jogadaLinha-1][jogadaColuna-1] = 0;
                printf("o jogador x jogou na posição %i x %i o valor %i\n", jogadaLinha, jogadaColuna, game[jogadaLinha][jogadaColuna]);
            }else{
                printf("\njá foi jogado nesse lugar\n\n");
                c--;
            }
        }
    }
}

int main(){
    bool loop = true;
    int opc;
    
    menu();
    scanf("%i", &opc);
    
    do{
        switch (opc)
        {
        case 1:
            printf("iniciando jogo da velha...\n\n");
            loop = false;
            old_game();

        break;

        case 2:
            printf("iniciando palavras cruzadas...\n\n");
            loop = false;

            
        break;

        case 3:
            printf("iniciando forca...\n\n");
            loop = false;

            
        break;

        case 0:
            printf("saindo do sistema...\n\n");
            loop = false;
        break;
        
        default:
            printf("insira uma opção valida.\n\n");
        break;
        }
    }while(loop == true);
    
    return 0;
}
