#include "Cabecalho.h"  // Inclui o arquivo de cabeçalho personalizado
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int tamanho_tabela, filmes_inseridos = 0;
    
    printf("Informe o tamanho da tabela de filmes: ");
    scanf("%d", &tamanho_tabela);
    getchar(); 
    
    // Aloca espaço na memória para a tabela de filmes
    Filme** tabela_filmes = (Filme**)malloc(tamanho_tabela * sizeof(Filme*));
    if (tabela_filmes == NULL) {
        printf("Erro ao alocar memória para a tabela de filmes.\n");
        return 1;
    }
    
    int opcao;
    do {
        menu();  // Exibe o menu de opções
        
        scanf("%d", &opcao);
        getchar(); 
        
        switch (opcao) {
            case 1: {
                if (filmes_inseridos == tamanho_tabela) {
                    printf("A tabela de filmes está cheia.\n");
                    break;
                }
                
                Filme* novo_filme = criar_filme();  // Cria um novo filme
                if (novo_filme == NULL) {
                    printf("Erro ao criar um novo filme.\n");
                    break;
                }
                
                // Solicita informações sobre o novo filme
                printf("Nome: ");
                char nome[101];
                scanf("  %[^\n]", &nome);
                set_nome(novo_filme, nome);
                
                printf("Preco: ");
                float preco;
                scanf("%f", &preco);
                getchar(); 
                set_preco(novo_filme, preco);

                printf("Diretor: ");
                char diretor[101];
                scanf("  %[^\n]", &diretor);
                set_diretor(novo_filme, diretor);

                printf("Ano: ");
                int ano;
                scanf("%d", &ano);
                getchar(); 
                set_ano(novo_filme, ano);

                printf("Genero: ");
                char genero[51];
                scanf("  %[^\n]", &genero);
                set_genero(novo_filme, genero);
                
                while (1) {
                    printf("Faixa Etaria: ");
                    int faixa_etaria;
                    scanf("%d", &faixa_etaria);
                    getchar(); 

                    // Verifica se a faixa etária é válida
                    if (possui_genero_terror(genero) && faixa_etaria < 18) {
                        printf("\nFaixa etaria invalida para o genero. Insira novamente.\n\n");
                    } else {
                        set_faixaetaria(novo_filme, faixa_etaria);
                        break;
                    }
                }
                
                tabela_filmes[filmes_inseridos] = novo_filme;
                filmes_inseridos++;
                print_tabela(tabela_filmes, filmes_inseridos);
                break;
            }
            case 2: {
                printf("Informe o codigo do filme que deseja atualizar: ");
                int codigo;
                scanf("%d", &codigo);
                getchar(); 
                
                if (codigo < 1 || codigo > tamanho_tabela) {
                    printf("Codigo invalido.\n");
                    break;
                }
                
                Filme* filme_atualizar = tabela_filmes[codigo - 1];
                printf("\n----- Opcoes de Atualizacao -----\n\n");
                printf("1. Renomear titulo\n");
                printf("2. Atualizar preco\n");
                printf("3. Atualizar genero\n");
                printf("Escolha uma opcao: ");
                int opcao_atualizar;
                scanf("%d", &opcao_atualizar);
                getchar(); 
                
                switch (opcao_atualizar) {
                    case 1: {
                        printf("Informe o novo nome do filme: ");
                        char nome[101];
                        scanf("  %[^\n]", &nome);
                        set_nome(filme_atualizar, nome);
                        break;
                    }
                    case 2: {
                        printf("Informe o novo preco do filme: ");
                        float preco;
                        scanf("%f", &preco);
                        getchar();
                        set_preco(filme_atualizar, preco);
                        break;
                    }
                    case 3: {
                        printf("Informe o novo genero do filme: ");
                        char genero[51];
                        scanf("  %[^\n]", &genero);
                        set_genero(filme_atualizar, genero);
                        break;
                    }
                    default:
                        printf("Opcao invalida.\n");
                        break;
                }
                
                print_tabela(tabela_filmes, filmes_inseridos);
                break;
            }
            case 3: {
                printf("Informe o codigo do filme que deseja excluir: ");
                int codigo;
                scanf("%d", &codigo);
                getchar(); // Limpa o buffer do teclado
                
                // Analisa se o filme escolhido está no catálogo
                if (codigo < 1 || codigo > tamanho_tabela) {
                    printf("Codigo invalido.\n");
                    break;
                }

                // Apaga o filme
                free_filme(tabela_filmes[codigo - 1]);
                
                // Reorganiza os filmes que estão após o que foi excluído
                for (int i = codigo - 1; i < filmes_inseridos - 1; i++) {
                    tabela_filmes[i] = tabela_filmes[i + 1];
                }
                
                filmes_inseridos--;
                print_tabela(tabela_filmes, filmes_inseridos);
                break;
            }
            case 4: {
                printf("Finalizando operacao.\n");
                break;
            }
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 4);
    
    // Libera a memória alocada para os filmes
    for (int i = 0; i < tamanho_tabela; i++) {
        free_filme(tabela_filmes[i]);
    }
    free(tabela_filmes);
    
    return 0;
}


//gcc main.c Funcoes.c -o programa.exe
