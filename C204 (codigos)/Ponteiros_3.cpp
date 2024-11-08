#include <iostream>
using namespace std;

struct info
{
	int idade;
	float peso;
};


int main(){
	
	info *pessoa;
	
	pessoa = new info;
	
	pessoa->idade = 22;
	pessoa->peso = 63.6;
	
	cout << "Idade: " << pessoa->idade << endl;
	cout << "Peso: " << pessoa->peso << endl;
	
	delete pessoa;
	
	return 0;
}