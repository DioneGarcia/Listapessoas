#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrLista.h"

Pessoa* iniciaPessoa()
{
    Pessoa *p;

    for(int i = 0; i == 0;){
        p = (Pessoa*) malloc(sizeof(Pessoa));
        if( p != NULL){
            i = 1;
        }
    }
    p->proximo = NULL;
}

void adicionarPessoaLista(ListaPessoas *lp, Pessoa *p, int possicao)
{

    printf("\n%s", p->nome);
    printf("\n%d", p->idade);

    if(possicao == lp->quantidadePessoas){
        p->proximo = NULL;
        (lp->ultima)->proximo = p;
        lp->ultima = p;
        lp->quantidadePessoas++;
        return;
    }

    Pessoa *pAux1, *pAux2;

    pAux2 = lp->primeira;
    pAux1 = pAux2->proximo;

    for(int i = 1; i <= possicao; i++){
        pAux2 = pAux1;
        pAux1 = pAux2->proximo;
    }

    p->proximo = pAux1;
    pAux2->proximo = p;

    free(pAux1);
    free(pAux2);

    lp->quantidadePessoas++;
}

void excluiPessoa(ListaPessoas *lp, int possicao)
{
    Pessoa *pAux1, *pAux2;

    pAux2 = lp->primeira;
    pAux1 = pAux2->proximo;

    for(int i = 1; i <= possicao; i++){
        pAux2 = pAux1;
        pAux1 = pAux2->proximo;
    }

    pAux2->proximo = pAux1->proximo;
    free(pAux1->proximo);

    if(possicao == lp->quantidadePessoas){
        lp->ultima = pAux2;
    }

    free(pAux1);
    free(pAux2);

    lp->quantidadePessoas--;
}

void selecionarPessoa(ListaPessoas *lp)
{
    Pessoa *pAux1, *pAux2 = lp->primeira;
    pAux1 = pAux2->proximo;

    for(int i = 0; i < lp->quantidadePessoas; i++){
        pAux2 = pAux1;
        pAux1 = pAux2->proximo;
        printf("\nNome: %s, Idade: %d", pAux2->nome, pAux2->idade);
    }
}
