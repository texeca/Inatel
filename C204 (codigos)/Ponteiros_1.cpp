#include <iostream>
using namespace std;

int main()
{
	int v[5];
	int soma;
	int *p, *r;
	
	p = v; //p aponta para o inicio do vetor
	//Atribuindo valores
	for(int i=0;i<5;i++)
	{
		*p = i;
		p++;
	}
	
	// Calculando a soma
	p = v;
	soma = 0;
	for(int i=0;i<5;i++)
	{
		  soma += *p;
		  p++;   	
	}	

	cout << "Soma = " << soma << endl;
	cout << endl;
	
	
	
	return 0;
}