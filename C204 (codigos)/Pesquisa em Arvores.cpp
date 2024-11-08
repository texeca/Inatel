#include <iostream>
using namespace std;


struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode * treenodeptr; // treenode* = treenodeptr

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

treenodeptr tProcura(treenodeptr p, int x)
{
	
	if (p == NULL) // elemento n~ao encontrado
		return NULL;
	else
	if (x == p->info) // elemento encontrado na raiz
		return p;
	else
	if (x < p->info) // procura na sub´arvore esquerda
		return tProcura(p->esq,x);
	else // procura na sub´arvore direita
		return tProcura(p->dir,x);

}

int main()
{
	
	   treenodeptr arvore = NULL;
	   treenodeptr t = NULL;
	   
	   
	   int N;
	   int lido;
	   int procurado;
	   
	   cout << "Entre com o tamanho do vetor" << endl;
	   cin >> N;
	   
	   
	   for(int i = 0;i < N; i++){
	   	
	   	cin >> lido;
		   
		   tInsere(arvore,lido);  
	   }		   
		cout << "Entre com o numero procurado" << endl;
	    cin >> procurado;
		
		treenodeptr resultado = NULL;
		
		resultado =  tProcura(arvore,procurado);
		
		
		
		if(resultado == NULL)
			cout << "Nao encontrado" << endl;
		else
			cout <<"Encontrado: " << resultado->info << endl;  
		    
	   return 0;
}