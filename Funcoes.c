#include "Cabecalho.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Definição da estrutura "info" que armazena as informações adicionais de um filme
struct info {
    char diretor[101];
    char genero[51];
    int ano;
    int faixaEtaria;
};

// Definição da estrutura "filme" que representa um filme
struct filme {
    char nome[101];
    float preco;
    struct info* informacoes;
};

// Função para criar um novo filme
Filme* criar_filme() {
    struct filme* novo_filme = (struct filme*)malloc(sizeof(struct filme));
    if (novo_filme != NULL) {
        novo_filme->informacoes = (struct info*)malloc(sizeof(struct info));
        if (novo_filme->informacoes != NULL) {
            novo_filme->preco = 0.0;
            strcpy(novo_filme->nome, "");
            strcpy(novo_filme->informacoes->genero, "");
            novo_filme->informacoes->faixaEtaria = 0;
            strcpy(novo_filme->informacoes->diretor, "");
            novo_filme->informacoes->ano = 0;
        } else {
            free(novo_filme);
            novo_filme = NULL;
        }
    }
    return novo_filme;
}

// Função para liberar a memória alocada para um filme
void free_filme(Filme* f) {
    if (f != NULL) {
        free(f->informacoes);
        free(f);
    }
}

// Função para imprimir as informações de um filme
void imprimir_filme(Filme* f) {
    if (f != NULL) {
        printf(" %.2f R$ ## %s (%s, %d) ## %s %d",
        f->preco,
        f->nome,
        f->informacoes->genero,
        f->informacoes->faixaEtaria,
        f->informacoes->diretor,
        f->informacoes->ano);
    }
}

// Função para definir o nome de um filme
void set_nome(Filme* f, char* novo) {
    if (f != NULL && novo != NULL) {
        strcpy(f->nome, novo);
    }
}

// Função para definir o preço de um filme
void set_preco(Filme* f, float novo) {
    if (f != NULL) {
        f->preco = novo;
    }
}

// Função para definir o diretor de um filme
void set_diretor(Filme* f, char* novo) {
    if (f != NULL && novo != NULL) {
        strcpy(f->informacoes->diretor, novo);
    }
}

// Função para definir o gênero de um filme
void set_genero(Filme* f, char* novo) {
    if (f != NULL && novo != NULL) {
        strcpy(f->informacoes->genero, novo);
    }
}

// Função para definir o ano de um filme
void set_ano(Filme* f, int novo) {
    if (f != NULL) {
        f->informacoes->ano = novo;
    }
}

// Função para definir a faixa etária de um filme
void set_faixaetaria(Filme* f, int novo) {
    if (f != NULL) {
        f->informacoes->faixaEtaria = novo;
    }
}

// Função para imprimir a tabela de filmes
void print_tabela(Filme** tabela, int tam) {
    printf("\n-------------TABELA DE FILMES-------------\n\n");
    for (int i = 0; i < tam; i++) {
        if (tabela[i] != NULL){
          printf("%.4d -- ", i + 1);
        imprimir_filme(tabela[i]);
        printf("\n");  
        }else{
            break;
        }
    }
}

// Função para exibir o menu de opções
void menu() {
    printf("\n MENU DE OPCOES\n");
        printf("1. CADASTRAR UM NOVO TITULO,\n");
        printf("2. ATUALIZAR INFO DE UM TITULO\n");
        printf("3. EXCLUIR UM TITULO\n");
        printf("4. FINALIZAR OPERACAO\n");
}

// Função que verifica se uma determinada string possui a palavra "Terror"
// Retorna 1 se a palavra é encontrada, caso contrário retorna 0
int possui_genero_terror(char *genero){
    if (strstr(genero, "Terror") != NULL) {
        return 1;
    } else if (strstr(genero, "TERROR") != NULL) {
        return 1;
    } else {
        return 0;
    }
}
