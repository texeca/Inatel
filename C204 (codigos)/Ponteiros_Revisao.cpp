#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	int *p, *q, *r;
	
	a = 2;
	b = 3;
	
	p = &a;
	q = &b;
	r = &c;	
	
	*r = *p + *q;
	
	cout << "a = " << a << endl;
	cout << "&a = " << &a << endl;
	cout << "p = " << p << endl;
	cout << "*p  = " << *p << endl;
	cout << "c = " << c << endl;
	
	
	return 0;
}