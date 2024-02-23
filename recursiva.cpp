#include <iostream>
using namespace std;
void imprimir (int * n, int cant)
{
	for (int i = 0; i<cant; i++)
		cout<<i<<" = "<<n[i]<<endl;
}
void imprec (int * n,int cant){
	if (cant>0)
	{
		imprec(n,cant-1);
		cout<<cant<<" = "<<n<<n[cant-1]<<endl;
	}
}
int main(int argc, char *argv[]) {
	const int Tam = 7;
	int numeros [] =  {3,5,2,0,1,7,4};
	cout<<"IMPRESION BUCLE "<<endl;
	imprimir (numeros,Tam);
	cout<<"IMPRESION RECURSIVA "<<endl;
	imprec (numeros,Tam);
	return 0;
}

