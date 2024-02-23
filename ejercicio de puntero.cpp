#include <iostream>
using namespace std;
void funcion (int var){
	var =100;
}
int main(int argc, char *argv[]) {
	
	int var=10;
	int num=0;
	double real=10
	double *ptreal;
	int * puntero= NULL;
	int * ptreal= NULL;
	puntero=&var;
	puntero=&num;
	ptreal=puntero;
	
	cout<<"var: "<<var<<endl;
	cout<<"Valor puntero: "<<*puntero<<endl;
	cout<<"Direccion de puntero: "<<puntero<<endl;
	return 0;
}

