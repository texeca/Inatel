#include <iostream>
using namespace std;
struct treenode
{
    int info;
    treenode *esq;
    treenode *dir;
};
typedef treenode *treenodeptr;
// Insere x na arvore
void tInsere(treenodeptr &p, int x)
{
    if (p == NULL) // insere na raiz
    {
        p = new treenode;
        p->info = x;
        p->esq = NULL;
        p->dir = NULL;
    }
    else if (x < p->info) // insere na subarvore esquerda
        tInsere(p->esq, x);
    else // insere na subarvore direita
        tInsere(p->dir, x);
}
void somaPosOrdem (treenodeptr arvore, int &s1)
{
    if (arvore != NULL)
    {
        somaPosOrdem(arvore->esq, s1);
        somaPosOrdem(arvore->dir, s1);
        s1 += arvore->info;
    }
}
// Retorna a soma dos nos da arvore
int soma(treenodeptr arvore)
{
    int s1 = 0; // soma dos nos da arvore
    somaPosOrdem(arvore, s1);
    return s1;
}
int main()
{
    treenodeptr arvore = NULL; // ponteiro p/ raiz da arvore
    int s; // soma dos nos
    
    tInsere(arvore, 4);
    tInsere(arvore, 2);
    tInsere(arvore, 5);
    tInsere(arvore, 1);
    
    s = soma(arvore);
    
    cout << "s = " << s << endl;
    
    return 0;
}