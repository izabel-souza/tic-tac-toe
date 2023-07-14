#include <stdio.h> 
#include <stdlib.h>
#define LINHAS 3
#define COLUNAS 3

typedef char Matriz[LINHAS][COLUNAS];

void cumprimentos();
void impressao_jogo(Matriz matriz);
void jogadas(Matriz matriz, char operador_jogador, char operador_maquina);
void inicializacao_matriz(Matriz matriz);
char verificacao_posicao_disponivel(Matriz matriz, int linha, int coluna);
int verificacao_vitoria(Matriz matriz, char operador_jogador);
int vitoria();
int derrota();