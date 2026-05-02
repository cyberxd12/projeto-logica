#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void menu() {

	printf("insira a opção desejada: \n1 - jogo da velha\n2 - Palavras cruzadas\n3- jogo da forca\n0 - para sair\n");
}

// Função para inicializar o tabuleiro
void inicializar_tabuleiro(char game[3][3]) {
    int caunt = 2;
    for(int i = 0; i < 3; i++) {
        for(int c = 0; c < 3; c++) {
            caunt++;
            game[i][c] = caunt;
        }
    }
}

// Função para exibir o tabuleiro
void exibir_tabuleiro(char game[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int c = 0; c < 3; c++) {
            printf("[%i] ", game[i][c]);
        }
        printf("\n");
    }
}

// Função para verificar vencedor
bool verificar_vencedor(char game[3][3]) {
    for(int i = 0; i < 3; i++) {
        if(game[i][0] == game[i][1] && game[i][1] == game[i][2]) {
            return true;
        }
    }
    for(int i = 0; i < 3; i++) {
        if(game[0][i] == game[1][i] && game[1][i] == game[2][i]) {
            return true;
        }
    }
    if(game[0][0] == game[1][1] && game[1][1] == game[2][2]) {
        return true;
    }
    if(game[0][2] == game[1][1] && game[1][1] == game[2][0]) {
        return true;
    }
    return false;
}

// Função para processar o turno de um jogador
bool processar_turno(char game[3][3], int jogador, int jogadaLinha, int jogadaColuna) {
    if(game[jogadaLinha-1][jogadaColuna-1] != 1 && game[jogadaLinha-1][jogadaColuna-1] != 0) {
        game[jogadaLinha-1][jogadaColuna-1] = jogador;
        printf("O jogador %c jogou na posição %i x %i\n", jogador == 1 ? 'O' : 'X', jogadaLinha, jogadaColuna);
        return true;
    } else {
        printf("\nJá foi jogado nesse lugar\n\n");
        return false;
    }
}

void old_game() {
    char game[3][3];
    int jogadaColuna, jogadaLinha;

    inicializar_tabuleiro(game);

    printf("Como jogar:\nCada jogador terá seu turno.\nEscolha a posição que será jogada na sua vez.\nA posição deve ser colocada em um quadrado 3x3.\nExemplo de escolha:\nLinha: 2\nColuna: 3\n\n");

    for(int c = 0; c < 9; c++) {
        exibir_tabuleiro(game);

        printf("\nTurno %d\nVez do Jogador %c - Escolha uma posição.\n", c, c % 2 == 0 ? 'O' : 'X');
        printf("Linha: ");
        scanf(" %i", &jogadaLinha);
        printf("Coluna: ");
        scanf(" %i", &jogadaColuna);

        if(!processar_turno(game, c % 2, jogadaLinha, jogadaColuna)) {
            c--;
            continue;
        }

        if(c >= 4 && verificar_vencedor(game)) {
            printf("Jogador %c venceu!\n", c % 2 == 0 ? 'O' : 'X');
            break;
        }

        if(c == 8) {
            printf("Empate!\n");
        }
    }
}

int main() {
	bool loop = true;
	int opc;

	menu();
	scanf("%i", &opc);

	do {
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
	} while(loop == true);
	
	return 0;
}
