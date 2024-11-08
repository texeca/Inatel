#include <iostream>
#include <algorithm> // biblioteca para a funcao sort

using namespace std;

int V[1000000]; // vetor

// vetor,tamanho,numero a ser procurado
int busca_binaria(int *v,int tam,int num)
{
	int ini,mid,fim;
	bool achei;
	
	ini = 0; // primeira posicao	
	fim = tam - 1; // ultima posicao
	achei = false;
	
	while(!achei && ini <= fim)
	{
		mid = (ini+fim)/2;
		if(v[mid] == num)
		{
			achei = true;
		}
		else if(v[mid] > num)
		{
			fim = mid-1;
		}
		else
		{
			ini = mid+1;
		}
	}
	if(achei) // se encontrei
		return mid; // retorna a posicao
	else // senao
		return -1; // retorna -1
}

int main()
{
	int N; // tamanho do vetor 
	int X; // numero a ser buscado no vetor
	int pos;

	N = 1000000;
		
	for(int i = 0;i < N; i++)
	{
		V[i] = i; // entrada do vetor
	}
	
	// funcao para ordenar os valores
	// sort(nome_do_vetor,nome_do_vetor + numero_de_elementos);
	// vetor já está ordenado
	sort(V,V+N);
	
	X = rand(); //numero aleatorio

	pos = busca_binaria(V,N,X); // posicao que foi encontrado
	if(pos == -1) // nao achei
	{
		cout << "O numero " << X << " nao esta no vetor" << endl;
	}
	else
	{
		cout << "O numero " << X << " esta no vetor" << endl;
	}
	return 0;
}