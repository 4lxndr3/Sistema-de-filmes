#include <stdio.h>

// Estrutura para um Filme
typedef struct filme Filme;

// Função que cria e retorna um ponteiro simples para o tipo Filme
Filme* criar_filme();

// Função que exclui um filme e libera memória
void free_filme(Filme* f);

// Função que imprime informações de um filme
void imprimir_filme(Filme* f);

// FUNÇÕES DE MANIPULAÇÃO

// Função que acessa e modifica o nome de um filme
void set_nome(Filme* f, char* novo);

// Função que acessa e modifica o preço de um filme
void set_preco(Filme* f, float novo);

// Função que acessa e renomeia um diretor de um filme
void set_diretor(Filme* f, char* novo);

// Função que acessa e renomeia os gêneros de um filme
void set_genero(Filme* f, char* novo);

// Função que acessa e modifica o ano de um filme
void set_ano(Filme* f, int novo);

// Função que acessa e modifica a faixa etária de um filme
void set_faixaetaria(Filme* f, int novo);

// Função que imprime a tabela atualizada dos filmes cadastrados
void print_tabela(Filme** tabela, int tam);

// Função que exibe o menu de opções
void menu();

// Funçao que verifica se possui Terror como um dos generos
int possui_genero_terror(char *genero);
