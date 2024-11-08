#include <iostream>
using namespace std;


struct treenode
{
	int info;
	treenode *esq;
	treenode *dir;
};
typedef treenode * treenodeptr; // treenode* = treenodeptr


int main(){
	
	   treenodeptr arvore = NULL;
	   treenodeptr t = NULL;
	   
	   arvore = new treenode;
	   
	   arvore->info = 14;
	   arvore->esq = NULL;
	   arvore->dir = NULL;
	   
	   arvore->esq = new treenode; //PONTEIRO Q APONTAVA PARA O NÓ ESQUERDO, VIRA UMA STRUCT
	   
	   (arvore->esq)->info = 4; 
	   (arvore->esq)->esq = NULL;
	   (arvore->esq)->dir = NULL;
	   
	   (arvore->dir) = new treenode; //PONTEIRO Q APONTAVA PARA O NÓ DIREITO, VIRA UMA STRUCT
	   
	   (arvore->dir)->info = 15;
	   (arvore->dir)->esq = NULL;
	   (arvore->dir)->dir = NULL;
	   
	   t = arvore; // T APONTA PARA O NÓ INICIAL (14)
	   cout << t->info << endl;
	   t = arvore->esq;
	   cout <<t->info << endl;
	   t = arvore->dir;
	   cout << t->info << endl;
	   
	   
	   
return 0;	
}