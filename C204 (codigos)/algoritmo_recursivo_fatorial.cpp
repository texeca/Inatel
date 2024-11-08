#include <iostream>

using namespace std;


int fatorial(int n, int &rep){
	
	rep++;
	
	if(n == 0)
		return 1;
	else
		return n * fatorial(n - 1, rep);		
}


int fib (int n, int &rep){
	
	rep++;
	if(n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fib(n-1,rep) + fib(n-2,rep);
}


int main(){
	
	int n, f, rep = 0;
	
	
	cin >> n;
	
	f = fib(n, rep);
	
	
	
	cout << f << endl;
	
	return 0;
	
}	