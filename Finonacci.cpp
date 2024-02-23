#include <iostream>
using namespace std;


int fib (int n){
	if (n <=1) 
		return n;
	else
	{
		cout<<(n-1)<<" "<< (n-2)<<endl;
		return fib(n-1)+ fib(n-2); 
	}
}
	int main(int argc, char *argv[]) {
		const int NUM=5;
		
		cout<<"FINONACCI DE : "<<NUM<<"="<<fib(NUM)<<endl; 
		return 0;
	}
