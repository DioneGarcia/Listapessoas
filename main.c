#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "StrLista.h"

int menu(ListaPessoas *lp);
void menuOrdenar(ListaPessoas *lp);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    ListaPessoas *listaPessoas;
    Pessoa *noCabeca;

    for(int i = 0; i == 0;){
        listaPessoas = (ListaPessoas*) malloc(sizeof(ListaPessoas));
        noCabeca = (Pessoa*) malloc(sizeof(Pessoa));
        if(listaPessoas != NULL){
            i = 1;
        }
    }
    noCabeca->idade = NULL;

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
                listarPessoa(lp);
                printf("\nQual posição deseja excluir?\n");
                scanf("%d", &posicao);
                excluiPessoa(lp, posicao);

                break;
            case 3:
                menuOrdenar(lp);

                break;
            case 4:
                return 0;
                break;

            default:
                printf("opção inválida\n");

        }

    }while( 0 == 0 );
}

void menuOrdenar(ListaPessoas *lp){

    int opcao = 0, qtd;
    Pessoa *p;

    ListaPessoas *listaNova;
    Pessoa *noCabeca;

    for(int i = 0; i == 0;){
        listaNova = (ListaPessoas*) malloc(sizeof(ListaPessoas));
        noCabeca = (Pessoa*) malloc(sizeof(Pessoa));
        if(listaNova != NULL){
            i = 1;
        }
    }

    noCabeca->idade = NULL;

    listaNova->quantidadePessoas = 0;

    listaNova->primeira = noCabeca;
    listaNova->ultima = noCabeca;

    do
    {
        system("cls");
        listarPessoa(lp);
        printf("\n=================================\n");
        printf("1 - Ordenar por Nome\n");
        printf("2 - Ordenar por Idade\n");
        printf("3 - Sair do Menu\n");
        printf("=================================\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                qtd = lp->quantidadePessoas;
                for(int i = 0; i < qtd; i++){
                    opcao = menorNome(lp);
                    p = selecionarPessoa(lp, opcao);
                    excluiPessoa(lp, opcao);
                    adicionarPessoaLista(listaNova, p, listaNova->quantidadePessoas);
                    listarPessoa(listaNova);
                }
                lp = listaNova;

                break;
            case 2:
                qtd= lp->quantidadePessoas;
                for(int i = 0; i < qtd; i++){
                    opcao=menorIdade(lp);
                    p = selecionarPessoa(lp, opcao);
                    excluiPessoa(lp, opcao);
                    adicionarPessoaLista(listaNova, p, listaNova->quantidadePessoas);
                    listarPessoa(listaNova);

                }
                lp = listaNova;
                break;
            case 3:

                return;
                break;

            default:
                printf("opção inválida\n");
                break;
        }
    }while(0 == 0);
}
