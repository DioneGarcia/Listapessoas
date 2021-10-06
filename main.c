#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "StrLista.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    ListaPessoas *listaPessoas;
    Pessoa *noCabeca;

    for(int i = 0; i == 0;){
        listaPessoas = (ListaPessoas*) malloc(5 * sizeof(ListaPessoas));
        noCabeca = (Pessoa*) malloc(sizeof(Pessoa));
        if(listaPessoas != NULL){
            i = 1;
        }
    }
    noCabeca->idade = NULL;
    //noCabeca->nome = NULL;

    listaPessoas->quantidadePessoas = 0;

    listaPessoas->primeira = noCabeca;
    listaPessoas->ultima = noCabeca;

    menu(listaPessoas);

    free(listaPessoas);
    return 0;
}

int menu(ListaPessoas *lp)
{
    int opcao = 0;
    Pessoa *p = NULL;
    char nome[30], *pNome;
    int posicao;
    short int idade;

    do
    {
        system("cls");
        printf("=================================\n");
        printf("1 - Adicionar pessoa\n");
        printf("2 - Excluir pessoa\n");
        printf("3 - Listar pessoas\n");
        printf("4 - Sair do programa\n");
        printf("=================================\n");
        scanf("%d", &opcao);


        switch(opcao)
        {
            case 1:
                p = iniciaPessoa();
                printf("\nNome: ");
                scanf("%s", &nome);
                strcpy(p->nome, nome);
                printf("\nIdade: ");
                scanf("%d", &idade);
                p->idade = idade;
                adicionarPessoaLista(lp, p, lp->quantidadePessoas);

                break;
            case 2:

                break;
            case 3:
                selecionarPessoa(lp);
                system("pause");

                break;
            case 4:
                return 0;
                break;
            default:
                printf("op��o inv�lida\n");

        }

    }while( 0 == 0 );

}