#include <iostream>
#include <math.h>
#include <queue>

using namespace std;

// Funções para Árvore Binária de Busca ---------------------------------------

typedef double KeyType;
typedef float ValueType;

struct Data {
	KeyType key;
	ValueType value;
};

typedef struct Data DataType;

 typedef struct Node {
	DataType data;
	Node * right;
	Node * left;
} Node;


void insert(Node *& curr, DataType data){	
	if(curr == NULL){
		curr = new Node;
		curr->data = data;
		curr->right = NULL;
		curr->left = NULL;
	} else {
		if(data.key >= curr->data.key){
			insert(curr->right, data);
		} else if(data.key < curr->data.key) {
			insert(curr->left, data);
		}		
	}	
}

Node * search(Node * curr, KeyType key){
	if(curr == NULL)
		return NULL;
	if(key == curr->data.key){
		return curr;
	} else {
		if(key > curr->data.key){
			return search(curr->right, key);
		} else if(key < curr->data.key){
			return search(curr->left, key);
		}
	}
	return NULL;
}

void show_ordered(Node * curr){
	if(curr->left != NULL)
		show_ordered(curr->left);
	cout << curr->data.key << ":" << curr->data.value << endl;
	if(curr->right != NULL)
		show_ordered(curr->right);
}

void show_ordered_a(Node * curr, int tmin, int tmax){
	if(curr->left != NULL)
		show_ordered(curr->left);
	if(curr->data.key >= tmin && curr->data.key <= tmax)
		cout << curr->data.key << ":" << curr->data.value << endl;
	if(curr->right != NULL)
		show_ordered(curr->right);
}

void show_ordered_b(Node * curr, int tmax){
	if(curr->left != NULL)
		show_ordered(curr->left);
	if(curr->data.key <= tmax)
		cout << curr->data.key << ":" << curr->data.value << endl;
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
		
		cout << aux->data.key << ":" << aux->data.value << endl;
		
		if(aux->left != NULL)
			nodes.push(aux->left);
		
		if(aux->right != NULL)
			nodes.push(aux->right);

		nodes.pop();
	}
}

Node * disconnect_lesser(Node *& curr){
	
	Node * aux = curr;
	if(aux->left == NULL){ 	
		curr = curr->right; 
		return aux;			
	} else {				
		return disconnect_lesser(curr->left);
	}
	
}


int remove(Node *& curr, KeyType old_key){
	if(curr == NULL){
		return 0;
	}
	Node * aux;
	if(curr->data.key == old_key){
		aux = curr;		
		if(curr->left == NULL){
			curr = aux->right;
		} else if(curr->right == NULL){
			curr = aux->left;
		} else {
			aux = disconnect_lesser(curr->right);
			curr->data = aux->data;
		}		
		delete aux;
		return 1;		
	} else {
		if(old_key > curr->data.key){
			return remove(curr->right, old_key);
		} else if(old_key < curr->data.key) {
			return remove(curr->left, old_key);
		}
	}
	return 0;
}


void destruct(Node *& curr){
	if(curr->left != NULL)
		destruct(curr->left);
	if(curr->right != NULL)
	   	destruct(curr->right);
	delete curr;
	curr = NULL;
	return;
}

// ----------------------------------------------------------------------------


// Funções para Algoritmos Geométricos ----------------------------------------

typedef struct {
	float x;
	float y;	
} Ponto;

double area_triangulo(
	Ponto a, 
	Ponto b, 
	Ponto c
){
	return 
		((a.x*b.y) - (a.y*b.x) + 
		(a.y*c.x) - (a.x*c.y) + 
		(b.x*c.y) - (b.y*c.x))/2.0;  
}

double distancia(Ponto p1, Ponto p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y));
}

int orientacao(Ponto a, Ponto b, Ponto c){
	double area = area_triangulo(a,b,c);
	if(area > 0){
		return 1; 
	} else if(area < 0){
		return -1; 
	} else {
		return 0; 
	}
}
// ----------------------------------------------------------------------------


int main (){
	

	Node * root = NULL;
    int n;
    Ponto p1,p2,p3;
    float tam1,tam2;
    Data peixe;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
  		cin >> p1.x >> p1.y;
		cin >> p2.x >> p2.y;
		cin >> p3.x >> p3.y;
        
        tam1 = distancia(p1,p2);
		tam2 = distancia(p1,p3);
		
		if(tam1 < tam2){
		peixe.value = tam1;
		DataType peixe;
        peixe.key = i;
        peixe.value = tam1 ;
        insert(root, peixe);
		}
		else
		{
		peixe.value = tam2;
		DataType peixe;
        peixe.key = i;
        peixe.value = tam2 ;
        insert(root, peixe);
		}
		
    }
   
	show_levels(root);
    destruct(root);
}