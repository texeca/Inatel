#include <iostream>
#include <string>
#include <queue>

using namespace std;

string cards[14] = {"0","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
string naipes[4] = {"ouros","espadas","copas","paus"};

typedef struct Card{
	int number;
	int naipe;	
} Card;

typedef struct Node{
	Card data;
	Node * right;
	Node * left;
} Node;

Node * insert(Node * aux, Card newData){
	if(aux == NULL){
		Node * n = new Node;
		n->data = newData;
		n->right = NULL;
		n->left = NULL;	
		return n;
	} else {
		if(newData.number > aux->data.number){
			//inserir na direita
			aux->right = insert(aux->right, newData);
		} else if(newData.number < aux->data.number){
			//inserir na esquerda
			aux->left = insert(aux->left, newData);
		} else {
			if(newData.naipe >= aux->data.naipe){
				//inserir na direita
				aux->right = insert(aux->right, newData);
			} else if(newData.naipe < aux->data.naipe){
				//inserir na esquerda
				aux->left = insert(aux->left, newData);
			}
		}
	}
	return aux;	
}

Node * search(Node * aux, int number, int naipe){
	
	if(aux == NULL)
		return NULL;
	if(number == aux->data.number){
		if(naipe == aux->data.naipe){
			return aux;
		} else {
			if(naipe > aux->data.naipe){
				return search(aux->right,number, naipe);
			} else {
				return search(aux->left, number, naipe);
			}
		}
	} else {
		if(number > aux->data.number){
			return search(aux->right,number, naipe);
		} else {
			return search(aux->left, number, naipe);
		}	
	}
}


void show_ordered(Node * aux){
	//varredura a esquerda
	if(aux->left != NULL)
		show_ordered(aux->left);
	cout<< cards[aux->data.number] << " de " 
		<< naipes[aux->data.naipe] << endl;
	//varredura a direita
	if(aux->right != NULL)
		show_ordered(aux->right);	
}


void show_levels(Node * curr){
	if(curr == NULL)
		return;
	
	queue<Node*> nodes;
	
	nodes.push(curr);
	
	while(!nodes.empty()){
		curr = nodes.front();
		if(curr->left != NULL)
			nodes.push(curr->left);
		if(curr->right != NULL)
			nodes.push(curr->right);
		cout << curr->data.number << endl;
		nodes.pop();
	}
}

Node * menor(Node *& curr){
	Node * aux = curr;
	if(aux == NULL)
		return NULL;
	if(aux->left == NULL){
		curr = curr->right;		
		return aux;
	} else {
		return menor(aux->left);
	}
}


int remove(Node *& aux, int number, int naipe){
	Node * p = aux;
	if(aux == NULL)
		return 0;
	if(aux->data.number == number && aux->data.naipe == naipe){
		if(aux->left == NULL)
		{
			aux = aux->right;
		} else if(aux->right == NULL){
			aux = aux->left;
		} else {
			p = menor(aux->right);
			aux->data = p->data;
		}
		delete p;	
	} else {
		if(number > aux->data.number){
			return remove(aux->right,number, naipe);
		} else if(number < aux->data.number) {
			return remove(aux->left, number, naipe);
		} else {
			if(naipe >= aux->data.naipe){
				return remove(aux->right,number, naipe);
			} else if(naipe < aux->data.naipe) {
				return remove(aux->left, number, naipe);
			}
		}
	}
}

void destroy(Node *& aux){
	if(aux->left != NULL)
		destroy(aux->left);
	if(aux->right != NULL)
		destroy(aux->right);
	delete aux;
	aux = NULL;
}



int main(){
	
	Node * root;
	root = NULL;
	
	Card newData;
	newData.number = 8;
	newData.naipe = 3;
	root = insert(root,newData);
	
	newData.number = 13;
	newData.naipe = 2;
	insert(root,newData);
	
	newData.number = 4;
	newData.naipe = 3;
	insert(root,newData);
	
	newData.number = 5;
	newData.naipe = 3;
	insert(root,newData);
	
	newData.number = 12;
	newData.naipe = 3;
	insert(root,newData);
	
	newData.number = 1;
	newData.naipe = 3;
	insert(root,newData);
	
	newData.number = 6;
	newData.naipe = 3;
	insert(root,newData);
	
	newData.number = 1;
	newData.naipe = 0;
	insert(root,newData);
	
	// Node * result = search(root, 5);
	// if(result != NULL)
	// 	cout << result->data.number << endl;
	// else
	// 	cout<< "Card not found!" <<endl;
	
	show_ordered(root);
	
	destroy(root);
	return 0;
}