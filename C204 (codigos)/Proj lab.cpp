#include <iostream>

#include <cstring>

#include <queue>

using namespace std;

typedef struct Item
{
	char Nome [51];
	char Propriedade[21];
	int ID;
	char Nivel;
	int n;

} Item;

typedef struct Node
{
	Item data;
	Node * right;
	Node * left;
} Node;


void insert(Node *& curr, Item data)
{
	if(curr == NULL)
	{
		curr = new Node;
		curr->data = data;
		curr->right = NULL;
		curr->left = NULL;
	}
	else
	{
		if(strcmp(data.Nome, curr->data.Nome) >= 0)
		{
			//ir para a direita
			insert(curr->right, data);
		}
		else
		{
			//ir para a esquerda
			insert(curr->left, data);
		}
	}
}

void insert_p(Node *& curr, Item data)
{
	if(curr == NULL)
	{
		curr = new Node;
		curr->data = data;
		curr->right = NULL;
		curr->left = NULL;
	}
	else
	{
		if(strcmp(data.Propriedade, curr->data.Propriedade) >= 0)
		{
			//ir para a direita
			insert(curr->right, data);
		}
		else
		{
			//ir para a esquerda
			insert(curr->left, data);
		}
	}
}

void insert_n(Node *& curr, Item data)
{
	if(curr == NULL)
	{
		curr = new Node;
		curr->data = data;
		curr->right = NULL;
		curr->left = NULL;
	}
	else
	{
		if(data.n >= curr->data.n)
		{
			//ir para a direita
			insert(curr->right, data);
		}
		else
		{
			//ir para a esquerda
			insert(curr->left, data);
		}
	}
}

Node * search(Node * curr, char Nome[])
{
	if(curr == NULL)
		return NULL;
	if(strcmp(Nome, curr->data.Nome) == 0)
	{
		return curr;
	}
	else
	{
		if(strcmp(Nome, curr->data.Nome) >= 0)
		{
			return search(curr->right, Nome);
		}
		else
		{
			return search(curr->left, Nome);
		}
	}

}

void show_ordered(Node * curr)
{
	//varrer a esquerda
	if(curr->left != NULL)
		show_ordered(curr->left);
	//exibir
	cout << curr->data.Nome << ": " << curr->data.Propriedade << ": " << curr->data.ID << ": " << curr->data.Nivel << endl;
	//varrer a direita
	if(curr->right != NULL)
		show_ordered(curr->right);
}

void show_levels(Node * curr)
{

	if(curr == NULL)
	{
		return;
	}

	queue<Node *> nodes;

	nodes.push(curr);

	while(! nodes.empty())
	{

		Node * aux = nodes.front();

		cout << aux->data.Nome << ": " << aux->data.Propriedade << ": " << aux->data.ID << ": " << aux->data.Nivel << endl;

		if(aux->left != NULL)
			nodes.push(aux->left);

		if(aux->right != NULL)
			nodes.push(aux->right);

		nodes.pop();
	}
}


// O objetivo dessa função é:
// 1 - Encontrar o nó com o menor valor
// 2 - Desconectar ele da árvore
// 3 - Retornar uma referência para esse nó
Node * disconnect_lesser(Node *& curr)
{

	Node * aux = curr;
	if(aux->left == NULL)  	// encontrou o menor elemento da subárvore
	{
		curr = curr->right; // temos que salvar os filhos da direita
		return aux;			// retornamos a referência para esse nó
	}
	else  				// senão continua a busca na subárvore da esquerda
	{
		return disconnect_lesser(curr->left);
	}

}


int remove(Node *& curr, char Nivel)
{
	if(curr == NULL)
	{
		return 0;
	}
	Node * aux;
	if(curr->data.Nivel == Nivel)
	{
		aux = curr;
		if(curr->left == NULL)
		{
			curr = aux->right;
		}
		else if(curr->right == NULL)
		{
			curr = aux->left;
		}
		else
		{
			// Caso o nó a ser removido tenha dois filhos
			// Pedimos para encontrar o menhor nó da subárvore da direita
			// Além disso devemos disconectar esse nó da árvore
			// (não podemos esquecer de salvar os filhos desse nó)
			aux = disconnect_lesser(curr->right);
			// O nó a ser removido vai receber o valor do menor nó à direita
			curr->data = aux->data;
			// Em seguida podemos desalocar a memória desse nó
		}
		delete aux;
		return 1;
	}
	else
	{
		if(Nivel >= curr->data.Nivel)
		{
			return remove(curr->right, Nivel);
		}
		else
		{
			return remove(curr->left, Nivel);
		}
	}
}


void destruct(Node *& curr)
{

	if(curr->left == NULL)
		destruct(curr->left);

	if(curr->right == NULL)
		destruct(curr->right);

	delete curr;
	curr = NULL;
	return;


}




int main()
{
	setlocale(LC_ALL, "portuguese");


	int id = 0;
	int aux;
	int aux2;
	int FOGO = 0;
	int VENENO = 0;
	int GELO = 0;

	Node * root = NULL;
	Node * root_p = NULL;
	Node * root_n = NULL;
	Node * result = NULL;

	Item item;

	cout << "Você abriu a Bolsa Devoradora, o que deseja?" << endl;

	while(aux != 5)
	{
		cout << endl;
		cout << "1 - Guardar Item" << endl;
		cout << "2 - Pesquisar por Item" << endl;
		cout << "3 - Listar itens" << endl;
		cout << "4 - Consumir itens (a bolsa irá devorar todos itens do nível desejado, ATENÇÃO!)" << endl;
		cout << "5 - Fechar Bolsa Devoradora" << endl;

		cin >> aux;


		switch(aux)
		{
		case 1:
			cout << endl;
			cout << "Nome do item : " << endl;
			cin.ignore();
			cin.getline(item.Nome, 51);

			while(strcmp(item.Nome, "fechar") != 0)
			{
				id++;
				cout << endl;
				cout << "Propriedade do Item : " << endl;

				cin.getline(item.Propriedade, 21);
				while(strcmp(item.Propriedade, "Fogo") != 0 && strcmp(item.Propriedade, "Gelo") != 0 && strcmp(item.Propriedade, "Veneno") != 0)
					cin.getline(item.Propriedade, 21);

				if(strcmp(item.Propriedade, "Fogo") == 0)
					FOGO++;
				if(strcmp(item.Propriedade, "Gelo") == 0)
					GELO++;
				if(strcmp(item.Propriedade, "Veneno") == 0)
					VENENO++;

				item.ID = id;
				cout << endl;
				cout << "Nivel do Item : " << endl;

				cin >> item.Nivel;
				while(item.Nivel != 'E' && item.Nivel != 'F' && item.Nivel != 'M')
					cin >> item.Nivel;

				if(item.Nivel == 'E')
					item.n = 3;
				if(item.Nivel == 'M')
					item.n = 2;
				if(item.Nivel == 'F')
					item.n = 1;


				insert(root, item);
				insert_p(root_p, item);
				insert_n(root_n, item);

				cout << endl;
				cout << "Nome do item (ou fechar ?) : " << endl;
				cin.ignore();
				cin.getline(item.Nome, 51);
			}
			break;

		case 2:
			cout << endl;
			cout << "Qual item deseja buscar?" << endl;

			char pesquisa[51];

			cin.getline(pesquisa, 51);


			result = search(root, pesquisa);

			if(result == NULL)
				cout << "O item não encontrado!" << endl;
			else
			{
				cout << endl;
				cout << "Item encontrado!" << endl;
			}

			break;

		case 3:
			cout << endl;
			cout << "Como deseja listar seus itens?" << endl;
			cout << "1 - Ordem aflabética" << endl;
			cout << "2 - Propriedades Mágicas" << endl;
			cout << "3 - Nivel" << endl;

			cin >> aux2;

			switch(aux2)
			{
			case 1:
				show_ordered(root);
				cout << endl;

				break;

			case 2:
				show_ordered(root_p);
				cout << endl;

				cout << "FOGO : " << FOGO << endl;
				cout << "GELO : " << GELO << endl;
				cout << "VENENO : " << VENENO << endl;

				break;

			case 3:
				show_ordered(root_n);
				cout << endl;

			default:
				break;
			}

			break;

		case 4:

			char pesq;
			cout << endl;
			cout << "Que nivel deve ser devorado ? " << endl;

			cin >> pesq;
			while(pesq != 'E' && pesq != 'F' && pesq != 'M')
				cin >> pesq;



			while(remove(root, pesq) == 1)
			{
				cout << "Item Devorado!" << endl;
			}
			if(remove(root, pesq) != 1)
			{
				cout << "Itens não encontrados" << endl;
			}

			break;

		}
	}


	destruct(root);
	destruct(root_n);
	destruct(root_p);
	return 0;
}
