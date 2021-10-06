#ifndef STRLISTA_H_INCLUDED
#define STRLISTA_H_INCLUDED

typedef struct PESSOA
{
    char nome[30];
    short int idade;
    struct Pessoa *proximo;
}Pessoa;

typedef struct LISTAPESSOAS
{
    int quantidadePessoas;
    Pessoa *primeira;
    Pessoa *ultima;
}ListaPessoas;

Pessoa* iniciaPessoa();
void adicionarPessoaLista(ListaPessoas *lp, Pessoa *p, int possicao);
void excluiPessoa(ListaPessoas *lp, int possicao);
void selecionarPessoa(ListaPessoas *lp);

#endif
