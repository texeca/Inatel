#include <iostream>

#include <queue>

using namespace std;

typedef struct Card {
	int number;
	int naipe;
} Card;

 typedef struct Node {
	Card data;
	Node * right;
	Node * left;
} Node;


void insert(Node *& curr, Card data){	
	if(curr == NULL){
		curr = new Node;
		curr->data = data;
		curr->right = NULL;
		curr->left = NULL;
	} else {
		if(data.number >= curr->data.number){
			//ir para a direita
			insert(curr->right, data);
		} else {
			//ir para a esquerda
			insert(curr->left, data);
		}		
	}	
}

Node * search(Node * curr, int number){
	if(curr == NULL)
		return NULL;
	if(number == curr->data.number){
		return curr;
	} else {
		if(number >= curr->data.number){
			return search(curr->right, number);
		} else {
			return search(curr->left, number);
		}
	}
	
}

void show_ordered(Node * curr){
	//varrer a esquerda
	if(curr->left != NULL)
		show_ordered(curr->left);
	//exibir
	cout << curr->data.number << ": " << curr->data.naipe << endl;
	//varrer a direita
	if(curr->right != NULL)
		show_ordered(curr->right);
}

void show_levels(Node * curr){
	
	if(curr == NULL){
		return;
	}
	
	queue<Node *> nodes;
	
	nodes.push(curr);
	
	while(! nodes.empty()){
		
		Node * aux = nodes.front();
		
		cout << aux->data.number << ": " << aux->data.naipe << endl;
		
		if(aux->left != NULL)
			nodes.push(aux->left);
		
		if(aux->right != NULL)
			nodes.push(aux->right);

		nodes.pop();
	}
}


// O objetivo dessa fun��o �:
// 1 - Encontrar o n� com o menor valor
// 2 - Desconectar ele da �rvore
// 3 - Retornar uma refer�ncia para esse n�
Node * disconnect_lesser(Node *& curr){
	
	Node * aux = curr;
	if(aux->left == NULL){ 	// encontrou o menor elemento da sub�rvore
		curr = curr->right; // temos que salvar os filhos da direita
		return aux;			// retornamos a refer�ncia para esse n�
	} else {				// sen�o continua a busca na sub�rvore da esquerda
		return disconnect_lesser(curr->left); 
	}
	
}


int remove(Node *& curr, int number){
	if(curr == NULL){
		return 0;
	}
	Node * aux;
	if(curr->data.number == number){
		aux = curr;		
		if(curr->left == NULL){
			curr = aux->right;
		} else if(curr->right == NULL){
			curr = aux->left;
		} else {
			// Caso o n� a ser removido tenha dois filhos
			// Pedimos para encontrar o menhor n� da sub�rvore da direita
			// Al�m disso devemos disconectar esse n� da �rvore
			// (n�o podemos esquecer de salvar os filhos desse n�)
			aux = disconnect_lesser(curr->right);
			// O n� a ser removido vai receber o valor do menor n� � direita
			curr->data = aux->data;
			// Em seguida podemos desalocar a mem�ria desse n�
		}		
		delete aux;
		return 1;		
	} else {
		if(number >= curr->data.number){
			return remove(curr->right, number);
		} else {
			return remove(curr->left, number);
		}
	}
}


void destruct(Node *& curr){
	
	if(curr->left == NULL)
		destruct(curr->left);
	
	if(curr->right == NULL)
	   	destruct(curr->right);
	
	delete curr;
	curr = NULL;
	return;
	
	
}




int main(){
	
	Node * root = NULL;
	
	Card card;
	card.number = 8;
	card.naipe = 1;
	insert(root, card);
	
	card.number = 13;
	card.naipe = 3;
	insert(root, card);
	
	card.number = 2;
	card.naipe = 3;
	insert(root, card);
	
	card.number = 4;
	card.naipe = 3;
	insert(root, card);
	
	card.number = 1;
	card.naipe = 1;
	insert(root, card);
	
	card.number = 12;
	card.naipe = 2;
	insert(root, card);
	
	card.number = 5;
	card.naipe = 2;
	insert(root, card);
	

	Node * result = search(root, 2);
	
	if(result == NULL)
		cout<<"A carta n�o foi encontrada!"<<endl;
	else {
		cout << result->data.number << ": " << result->data.naipe << endl;
	}
	
	
	show_ordered(root);
	cout << endl;
	
	show_levels(root);
	cout << endl;
	
	if(remove(root, 2) == 1){
		cout<< "Carta removida" << endl;
	} else {
		cout << "Carta nao encontrada" << endl;
	}
	
	show_ordered(root);
	cout << endl;
	
	show_levels(root);
	cout << endl;
	
	
	destruct(root);
	return 0;
}