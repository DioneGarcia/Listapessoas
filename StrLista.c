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
    if(possicao == lp->quantidadePessoas){
        adicionarPessoaListaFinal(lp, p);
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

    for(int i = 1; i < possicao; i++){
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

void listarPessoa(ListaPessoas *lp)
{
    Pessoa *pAux1, *pAux2 = lp->primeira;
    pAux1 = pAux2->proximo;

    for(int i = 0; i < lp->quantidadePessoas; i++){
        pAux2 = pAux1;
        pAux1 = pAux2->proximo;
        printf("\nPosição: %d, Nome: %s, Idade: %d", (i + 1), pAux2->nome, pAux2->idade);
    }
}

int menorNome(ListaPessoas *lp)
{
    Pessoa *pAux1, *pAux2 = lp->primeira;
    int psMenorNome = 1;

    pAux1 = pAux2->proximo;
    pAux2 = pAux1;

    for(int i = 1; i < lp->quantidadePessoas; i++){
        pAux1 = pAux1->proximo;

        if( strcmp(pAux2->nome, pAux1->nome) > 0){ // quando nome aux2 for maior que nome aux1
            pAux2 = pAux1;
             psMenorNome = i + 1;
        }
    }

    return psMenorNome;
}

int menorIdade (ListaPessoas *lp)
{
    int posicao=1;
    Pessoa *pAux, *pAux2 = lp->primeira;
    pAux=pAux2->proximo;
    pAux2=pAux;

    for(int i = 1; i < lp->quantidadePessoas; i++){
        pAux=pAux->proximo;

        if ( pAux2 ->idade > pAux->idade )
        {
            pAux2=pAux;
            posicao = i + 1;
        }

    }
    return posicao;
}

Pessoa* selecionarPessoa(ListaPessoas *lp, int ps)
{
    Pessoa *pAux = lp->primeira;

    for(int i = 0; i < ps; i++){
        pAux = pAux->proximo;
    }

    return pAux;
}

void adicionarPessoaListaFinal(ListaPessoas *lp, Pessoa *p){ // funcionalidade parecida com uma fila

    p->proximo = NULL;
    (lp->ultima)->proximo = p;
    lp->ultima = p;
    lp->quantidadePessoas++;
}
