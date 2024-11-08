#include <iostream>
#include <algorithm>

using namespace std;

int V[1000000]; // vetor

int main() // O(N)
{
	int N; // tamanho do vetor 
	int X; // numero a ser buscado no vetor
	bool achei;

	N = 1000000;
	
	for(int i = 0;i < N; i++)
	{
		V[i] = i; // entrada do vetor
	}
	
	//X = rand(); //numero aleatorio
	
	cin >> X; // numero a ser buscado no vetor
	
	achei = false; // inicialmente, nao achei
	for(int i = 0;i < N; i++)
	{
		if(X == V[i]) // se for igual
			achei = true; // achei
	}

	if(achei)
	{
		cout << "O numero " << X << " esta no vetor" << endl;
	}
	else
	{
		cout << "O numero " << X << " nao esta no vetor" << endl;
	}
	return 0;
}