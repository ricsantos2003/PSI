#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//--------- CONSTANTES -----------
#define MAX_NOME_ESTUDANTE 50
#define MAX_transacoes 5000
#define MAX_utilizadores 200

typedef struct
{
    int id;
    char id_escola;
    char abrev_escola;
    char champus;
    char local;
}escola;

typedef struct
{
    int id;
    int id_transacoes;
    char tipo_transacao;
    int valor_transacao;
    int data;
    int hora;

}transacoes;

typedef struct
{
    int id;
    int id_escola;
    char nome_aluno[MAX_NOME_ESTUDANTE];
    int NIF;
    char tipo_utilizador;
    char mail;
    int saldo;

}utilizador;

void main()
{
    setlocale(LC_ALL, "Portuguese");
}


int menu()
{
    int opcao;
    system("cls");
    opcao = ler_numero_int("1 - Registar dados das escolas\n\n"
                           "2 - Importar dados das escolas  \n\n"
                           "3 - Registar dados dos utilizadores \n\n"
                           "4 - Consultar os dados dos utilizadores\n\n"
                           "5 - Registar os dados das transações  \n\n"
                           "6 - Consultar os dados das transações \n\n"
                           "0 - Sair \n"
                           "OPCAO -> ",
                           0, 6);
    return opcao;
}

int ler_numero_int(char *msg, int min, int max)
{
    int valor;
    int numero_inputs_sucesso;
    do
    {
        numero_inputs_sucesso = scanf("%d", &valor);
        if (numero_inputs_sucesso <1 || valor<min || valor>max)
        {
            printf("\nIntroduza um único valor entre %d e %d !\n", min, max);
            stop();
        }
    }
    while(numero_inputs_sucesso <1 || valor<min || valor> max);
    return valor;
}

void ler_string(char *msg, char *str, int min, int max)
{
    int num_carateres_lidos;
    do
    {
        fgets(str, max, stdin);
        num_carateres_lidos = strlen(str);
        if ( num_carateres_lidos <= (min+1))
        {
            printf("\nO texto introduzido deve ter pelo menos %d caracteres!\n", min);
            stop();
        }
    }
    while(num_carateres_lidos <= (min+1));
}

char confirmar_saida()
{
    system("cls");
    char opcao;
    do
    {
        printf("\n\nTem certeza que pretende sair:\nS - Sim\nN - Nao\n OPCAO ->");
        scanf(" %c", &opcao);
        opcao = toupper(opcao);

    }while(opcao != 'S' && opcao != 'N');
    return opcao;
}
