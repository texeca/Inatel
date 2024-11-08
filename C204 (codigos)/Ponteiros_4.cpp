#include <iostream>
using namespace std;

void soma(int a, int b, int *c)
{
	*c = a + b;
}

int main()
{
	
	int x,y;
	int s = 0;
	
	cin >> x >> y;
	
	soma(x,y,&s);
	
	cout << "Soma = " << s << endl;
}