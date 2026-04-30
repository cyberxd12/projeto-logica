#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void menu() {

	printf("insira a opção desejada: \n1 - jogo da velha\n2 - Palavras cruzadas\n3- jogo da forca\n0 - para sair\n");
}

void old_game() {

	char game[3][3];
	int jogadaColuna,jogadaLinha;
	int caunt = 2;

	for(int i = 0; i < 3; i++) {
		for(int c = 0; c < 3; c++) {
			caunt++;
			game[i][c] = caunt;
		}
	}

	printf("como jogar:\ncada jogador tera seu turno.\nescolha a posição que sera jogado na sua vez.\na posição deve ser colocada em um quadrado 3x3.\nexemplo de escolha:\ncoluna: 3\nlinha: 2\n");
	for(int c = 0; c<9; c++) {
		for(int i = 0; i < 3; i++) {
			for(int c = 0; c < 3; c++) {
				printf("[%i] ", game[i][c]);
			}
			printf("\n");
		}
		if(c%2==0) {
			printf("\nturno %d\n,Vez do Jogador O - Escolha uma posição.\n", c);
			printf("linha: ");
			scanf(" %i", &jogadaLinha);
			printf("coluna: ");
			scanf(" %i", &jogadaColuna);
			
			if(game[jogadaLinha-1][jogadaColuna-1] != 1 && game[jogadaLinha-1][jogadaColuna-1] != 0) {
				game[jogadaLinha-1][jogadaColuna-1] = 1;
				printf("o jogador x jogou na posição %i x %i\n", jogadaLinha, jogadaColuna);
			} else {
				printf("\njá foi jogado nesse lugar\n\n");
				c--;
			}

		} else {
			printf("turno %d\nVez do Jogador X - Escolha uma posição.\n", c);
			printf("linha: ");
			scanf(" %i", &jogadaLinha);
			printf("coluna: ");
			scanf(" %i", &jogadaColuna);


			if(game[jogadaLinha-1][jogadaColuna-1] != 1 && game[jogadaLinha-1][jogadaColuna-1] != 0) {
				game[jogadaLinha-1][jogadaColuna-1] = 0;
				printf("o jogador x jogou na posição %i x %i\n", jogadaLinha, jogadaColuna);
			} else {
				printf("\njá foi jogado nesse lugar\n\n");
				c--;
			}
		}

		bool vencedor = false;

		if (c>=4) {
			for(int i = 0; i < 3; i++) {
				if(game[i][0]== game[i][1] && game[i][1]== game[i][2]) {
					vencedor = true;
				}
			}
			for(int i = 0; i < 3; i++) {
				if(game[0][i]== game[1][i] && game[1][i]== game[2][i]) {
					vencedor = true;
				}
			}
			if(game[0][0]== game[1][1] && game[1][1]== game[2][2]) {
				vencedor = true;
			}
			if(game[0][2]== game[1][1] && game[1][1]== game[2][0]) {
				vencedor = true;
			}
		}

		if(vencedor == true) {
			printf("jogado %i venceu", c%2);
			break;
		} else if(c==9) {
			printf("empate");
			break;
		} else {
			continue;
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
