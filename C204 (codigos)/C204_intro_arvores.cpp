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


int main()
{
	
		Node *root;  //No (ponteiro)
		root = NULL;
	   
	   
	   Card teste;
    
	   teste.number = 13;
	   teste.naipe = 3;
	   
	   Card nabo; 
	   
	   nabo.number = 3;
	   nabo.naipe =2;
	   
	   Node x;
	   
	   x.data = carta2;
	   x.right = NULL;
	   x.left = NULL;
	   
	   Node banana;
	   
	   banana.data = teste;
	   banana.right = NULL;
	   banana.left = NULL;
	   
	   if(x.data.number > root->data.number){
		   root->right = &x;
	   } else if(x.data.number < root->data.number){
		   root->left = &x;
	   }
	   
	   else
	   {
		   if(x.data.naipe > root->data.naipe){
			   root ->right = &x;
		   }else if(x.data.naipe < root->data.naipe){
			   root ->left = &x;
		   }
	   }
	   
	   
	   
	   
	   
	   
	   
	   
	   
	   cout << banana.data.number;
	        	   	   
	   root = &banana;  //Recebe endereço do no banana
	   
	   cout << (*root).data.number << endl; //Acessar conteudo do ponteiro
	   cout << root->data.number << endl; //Acessar conteudo do ponteiro
	  	
	return 0;
}