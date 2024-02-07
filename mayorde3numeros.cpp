#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float a,b,c;
		
	cout << "Ingrese el primer numero porfavor";
	cin >> a;
	cout << "Ingrese el segundo numero porfavor";
	cin >> b;
	cout << "Ingrese el ultimo numero porfavor";
	cin >> c;
	if(a>b && a>c){
		cout<<"el numero mayor es: "<<a;
	}
	if(b>c && b>a){
		cout<<"el numero mayor es: "<<b;        
	}
	if(c>b && c>a){
		cout<<"el numero mayor es: "<<c;        
	}
	
	cout << "El numero mayor es: " << c << endl;
	return 0;
}

