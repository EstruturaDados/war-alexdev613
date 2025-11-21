#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERRITORIOS 5
#define TAM_NOME 50
#define TAM_COR 20

// Estrutura que representa território
struct Territorio {
  char nome[TAM_NOME];
  char corExercito[TAM_COR];
  int tropas;
};

// Função para limpar o buffer do teclado
void limparBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

// A nossa função principal:
int main() {
  struct Territorio mapa[MAX_TERRITORIOS];
  int total = 0;
  int opcao;

  do {
    printf("\n=====================================\n");
        printf("        WAR - NIVEL INICIANTE\n");
        printf("=====================================\n");
        printf("1 - Cadastrar Territorio\n");
        printf("2 - Listar Territorios\n");
        printf("0 - Sair\n");
        printf("=====================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
          case 1:
            if (total >= MAX_TERRITORIOS) {
                printf("\nLimite de 5 territorios atingido!\n");
                break;
            }

            printf("\n--- Cadastrando Territorio %d ---\n", total + 1);

            printf("Nome do Territorio: ");
            fgets(mapa[total].nome, TAM_NOME, stdin);
            mapa[total].nome[strcspn(mapa[total].nome, "\n")] = '\0';

            printf("Cor do Exercito (ex: Azul, Verde): ");
            fgets(mapa[total].corExercito, TAM_COR, stdin);
            mapa[total].corExercito[strcspn(mapa[total].corExercito, "\n")] = '\0';

            printf("Numero de Tropas: ");
            scanf("%d", &mapa[total].tropas);
            limparBuffer();

            total++;

            printf("\nTerritorio cadastrado com sucesso!\n");
            printf("\nPressione Enter para continuar...");
            getchar();
            break;

          case 2:
            if (total == 0) {
              printf("\nNenhum territorio cadastrado ainda!\n");
            } else {
              printf("\n===== MAPA DO MUNDO - ESTADO ATUAL =====\n");

              for (int i = 0; i < total; i++) {
                printf("\nTERRITORIO %d:\n", i + 1);
                printf(" - Nome: %s\n", mapa[i].nome);
                printf(" - Dominado por: Exercito %s\n", mapa[i].corExercito);
                printf(" - Tropas: %d\n", mapa[i].tropas);
              }

              printf("\nPressione Enter para continuar...");
              getchar();
            }
            break;

          case 0:
            printf("\nSaindo...\n");
            break;

          default:
            printf("\nOpcao invalida!\n");
            printf("\nPressione Enter para continuar...");
            getchar();
        }

  } while (opcao != 0);

  return 0;  
}

/* Notas:

// fgets lê uma linha inteira do teclado, ele é melhor que scanf("%s") pois permite espaços,
// não corta palavras, evita problemas de buffer e não gera vazamento de memória

Resumindo:

printf("Nome do Territorio: "); // Mostra a pergunta na tela

// Lê uma linha do teclado (inclui espaços e o ENTER)
fgets(mapa[total].nome, TAM_NOME, stdin);

// Remove o ENTER '\n' que o fgets deixa na string
// strcspn retorna a posição do primeiro '\n' encontrado
// então substituímos pelo terminador '\0'
mapa[total].nome[strcspn(mapa[total].nome, "\n")] = '\0';

*/

// Criar executável e rodar no terminal:

// gcc war_novato.c -o war_novato.exe

// rodar no windows:

// ./war_novato.exe