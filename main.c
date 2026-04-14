#include <stdio.h>
#include <stdbool.h>

void menu(){

    printf("insira a opção desejada: \n1 - jogo da velha\n2 - Palavras cruzadas\n3- jogo da forca\n0 - para sair\n");
}

void old_game(){
    int vidap1 = 9,vidap2 = 9;
    

    for(int c = 0;c<9;c++){
        printf("como jogar:\ncada jogador tera seu turno.\nescolha a posição que sera jogado na sua vez.\na posição deve ser colocada em um quadrado 3x3.\nexemplo de escolha:\ncoluna: 3\nlinha: 2\n")
        if(c%2==0){
            printf("turno %d\n,Vez do Jogador O - Escolha uma posição.\n", c);

        }else{
            printf("turno %d\nVez do Jogador X - Escolha uma posição.\n", c);
        }
    }
}

int main()
{
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