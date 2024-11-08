#include <iostream>
using namespace std;

int main()
{
	int *v = NULL;
	int soma;
	int *p = NULL;
	int tam;
	
	cin >> tam;
	v = new int[tam]; // aloca memoria para tam elementos
	
	p = v; //p aponta para o inicio do vetor
	//Atribuindo valores
	for(int i=0;i<tam;i++)
	{
		*p = i;
		p++;
	}
	
	// Calculando a soma
	p = v;
	soma = 0;
	for(int i=0;i<tam;i++)
	{
		  soma += *p;
		  p++;   	
	}	

	cout << "Soma = " << soma << endl;
	
	delete [] v;
	
	return 0;
}