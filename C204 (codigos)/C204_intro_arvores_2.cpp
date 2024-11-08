#include <iostream>

using namespace std;


typedef struct Node{
	Card data;
	Node *right;
	Node *left;
}

typedef struct Card{
	int number;
	int naipe;
}Card;

void insert(Node *aux,Card newData){
	
	if(aux == NULL;){
	Node *n = new Node;
	n->data = teste;
	n->right = NULL;
	n->left = NULL;
	
	return n;
	}
	
	else
	{
		if(newData.number >= aux->data.number){
			aux -> right = insert(aux->right,newData);			
		}
		else
		{
			aux -> left = insert(aux->left,newData);
		}
	}
}

int main(){
	
	Node *root;
	root = NULL;
	
	Card newData;
	newData.number = 13;
	newData.naipe = 3;
	
	root = insert(root,newData)
	
	Card otherData;
	otherData.number = 3;
	otherData.naipe = 2;
	
	root = insert(root,newData)
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//Alocando memoria dinamicamente
	
	Node *n = new Node; //Alocar memoria, fica reservado ate desligar a RAM
	n->data = teste;
	n->right = NULL;
	n->left = NULL;
	
	delete n; //Desaloca o espaço de *n*
	
	


}