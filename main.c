#include "tic-tac-toe.h"

int main (void) {

    Matriz jogo;
    inicializacao_matriz(jogo);

    cumprimentos();

    char operador_jogador, operador_maquina;
    printf("\n\nEscolha X ou O para jogar: ");
    scanf("%c", &operador_jogador);

    (operador_jogador == 'X') ? (operador_maquina = 'O') : (operador_maquina = 'X');
    printf("\n\nJogador = <%c>  e  Maquina = <%c>\n\n", operador_jogador, operador_maquina);
    jogadas(jogo, operador_jogador, operador_maquina);

    return 0;
}

void cumprimentos() {
    printf("\n\nOi!\nVoce jogara contra uma maquina, faca o favor de nao perder\n\n");
}

void inicializacao_matriz(Matriz matriz) {
    for(int i = 0; i < LINHAS; i++) {
        for(int j = 0; j < COLUNAS; j++) {
            matriz[i][j] = ' ';
        }
    }
}

void impressao_jogo(Matriz matriz) {
    
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", matriz[0][0], matriz[0][1], matriz[0][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", matriz[1][0], matriz[1][1], matriz[1][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", matriz[2][0], matriz[2][1], matriz[2][2]);

    printf("     |     |     \n\n");
}

void jogadas(Matriz matriz, char operador_jogador, char operador_maquina) {

    int linhas, colunas;
    char disponibilidade;

    for(int i = 0; i < LINHAS; i++) {
        for(int j = 0; j < COLUNAS; j++) {

            if((i == 0 && j % 2 == 0) || (i == 2 && j % 2 == 0) || (i == 1 && j % 2 != 0)) {
                printf("\nJOGADOR: \n");
                while(1) {
                    printf("Informe linha e coluna para jogada: ");
                    scanf("%d %d", &linhas, &colunas);
                    disponibilidade = verificacao_posicao_disponivel(matriz, linhas, colunas);
                    if(disponibilidade == ' ') { matriz[linhas-1][colunas-1] = operador_jogador; break; }
                }
            }

            else {
                printf("\nMAQUINA: \n");
                while(1) {
                    linhas = (rand() % 3 + 1);
                    colunas = (rand() % 3 + 1);
                    disponibilidade = verificacao_posicao_disponivel(matriz, linhas, colunas);
                    if(disponibilidade == ' ') { matriz[linhas-1][colunas-1] = operador_maquina; break; }
                }
            }
            impressao_jogo(matriz);
        }

    }
    int x = verificacao_vitoria(matriz, operador_jogador);
    if(x) { vitoria();}
    else { derrota(); }
    
}

char verificacao_posicao_disponivel(Matriz matriz, int linha, int coluna) {
    return matriz[linha-1][coluna-1];
}

int verificacao_vitoria(Matriz matriz, char operador_jogador) {

    if(matriz[0][0] == operador_jogador) {
        //VERIFICICAÇÃO DAS DIAGONAIS   
        if((matriz[0][0] != ' ' && matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) || (matriz[0][2] != ' ' && matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0])) {
            return 1;
        }

        // //VERIFICACAO DAS HORIZONTAIS
        if((matriz[0][0] != ' ' && matriz[0][0] == matriz[0][1] && matriz[0][1] == matriz[0][2]) || (matriz[1][0] != ' ' && matriz[1][0] == matriz[1][1] && matriz[1][1] == matriz[1][2]) || (matriz[2][0] != ' ' && matriz[2][0] == matriz[2][1] && matriz[2][1] == matriz[2][2])) {
            return 1;
        }

        // //VERIFICAÇÃO DAS VERTICAIS
        if((matriz[0][0] != ' ' && matriz[0][0] == matriz[1][0] && matriz[1][0] == matriz[2][0]) || (matriz[0][1] != ' ' && matriz[0][1] == matriz[1][1] && matriz[1][1] == matriz[2][1]) || (matriz[0][2] != ' ' && matriz[0][2] == matriz[1][2] && matriz[1][2] == matriz[2][2])) {
            return 1;
        }
    }
    
    return 0;
}

int vitoria() {
    printf("WINNER CHICKEN WINNER!");
    return 1;
}

int derrota() {
    printf("GAME OVER!");
    return 0;
}