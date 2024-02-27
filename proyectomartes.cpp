#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

// Estructuras
struct Libro {
	string titulo;
	string autor;
	string ISBN;
	int publicationYear;
	string editorial;
	bool disponible;
	string num_registro;
};

struct Usuario {
	int userID;
	string nombre;
	string apellido;
	string email;
	int edad;
};

struct Bibliotecario {
	int employeeID;
	string nombre;
	string apellido;
	string email;
	string especialidad;
};

// Funciones de impresión aleatoria específicas
void imprimirLibrosAleatoriamente(Libro* libros, int size) {
	random_shuffle(libros, libros + size, [](int n) { return rand() % n; });
	
	cout << setw(30) << left << "Libro" << setw(20) << left << "Autor" << setw(10) << left << "ISBN" << setw(20) << left << "Año de Publicación"
		<< setw(15) << left << "Editorial" << setw(15) << left << "Num. Registro" << setw(25) << left << "Disponibilidad" << endl;
	
	for (int i = 0; i < size; ++i) {
		cout << setw(30) << left << libros[i].titulo << setw(20) << left << libros[i].autor << setw(10) << left << libros[i].ISBN << setw(20) << left << libros[i].publicationYear
			<< setw(15) << left << libros[i].editorial << setw(15) << left << libros[i].num_registro << setw(25) << left << (libros[i].disponible ? "Disponible para leer" : "No disponible para leer") << endl;
	}
}

void imprimirUsuariosAleatoriamente(Usuario* usuarios, int size) {
	random_shuffle(usuarios, usuarios + size, [](int n) { return rand() % n; });
	
	cout << "\nUsuarios" << endl;
	cout << "UserID\tNombre\t\tApellido\t\tEmail\t\t\tEdad" << endl;
	
	for (int i = 0; i < size; ++i) {
		cout << usuarios[i].userID << "\t" << setw(15) << left << usuarios[i].nombre << "\t" << setw(15) << left << usuarios[i].apellido << "\t" << usuarios[i].email
			<< "\tEdad: " << usuarios[i].edad << endl;
	}
}

void imprimirBibliotecariosAleatoriamente(Bibliotecario* bibliotecarios, int size) {
	random_shuffle(bibliotecarios, bibliotecarios + size, [](int n) { return rand() % n; });
	
	cout << "\nBibliotecarios" << endl;
	cout << "EmployeeID\tNombre\t\tApellido\t\tEmail\t\t\tEspecialidad" << endl;
	
	for (int i = 0; i < size; ++i) {
		cout << bibliotecarios[i].employeeID << "\t" << setw(15) << left << bibliotecarios[i].nombre << "\t" << setw(15) << left << bibliotecarios[i].apellido << "\t"
			<< bibliotecarios[i].email << "\tEspecialidad: " << bibliotecarios[i].especialidad << endl;
	}
}

// Nuevas funciones de búsqueda
void busquedaLibro(Libro* libros, int size) {
	string tituloBuscado;
	cout << "Ingrese el título o parte del título a buscar: ";
	cin.ignore();
	getline(cin, tituloBuscado);
	
	cout << setw(30) << left << "Libro" << setw(20) << left << "Autor" << setw(10) << left << "ISBN" << setw(20) << left << "Año de Publicación"
		<< setw(15) << left << "Editorial" << setw(15) << left << "Num. Registro" << setw(25) << left << "Disponibilidad" << endl;
	
	for (int i = 0; i < size; ++i) {
		if (libros[i].titulo.find(tituloBuscado) != string::npos) {
			cout << setw(30) << left << libros[i].titulo << setw(20) << left << libros[i].autor << setw(10) << left << libros[i].ISBN << setw(20) << left << libros[i].publicationYear
				<< setw(15) << left << libros[i].editorial << setw(15) << left << libros[i].num_registro << setw(25) << left << (libros[i].disponible ? "Disponible para leer" : "No disponible para leer") << endl;
		}
	}
}

void busquedaUsuario(Usuario* usuarios, int size) {
	char letraBuscada;
	cout << "Ingrese la letra del apellido a buscar: ";
	cin >> letraBuscada;
	
	cout << "UserID\tNombre\t\tApellido\t\tEmail\t\tEdad" << endl;
	
	for (int i = 0; i < size; ++i) {
		if (usuarios[i].apellido[0] == letraBuscada) {
			cout << usuarios[i].userID << "\t" << setw(15) << left << usuarios[i].nombre << "\t" << setw(15) << left << usuarios[i].apellido << "\t" << usuarios[i].email
				<< "\tEdad: " << usuarios[i].edad << endl;
		}
	}
}

void busquedaBibliotecario(Bibliotecario* bibliotecarios, int size) {
	char letraBuscada;
	cout << "Ingrese la letra del apellido a buscar: ";
	cin >> letraBuscada;
	
	cout << "EmployeeID\tNombre\t\tApellido\t\tEmail\t\t\tEspecialidad" << endl;
	
	for (int i = 0; i < size; ++i) {
		if (bibliotecarios[i].apellido[0] == letraBuscada) {
			cout << bibliotecarios[i].employeeID << "\t" << setw(15) << left << bibliotecarios[i].nombre << "\t" << setw(15) << left << bibliotecarios[i].apellido << "\t"
				<< bibliotecarios[i].email << "\tEspecialidad: " << bibliotecarios[i].especialidad << endl;
		}
	}
}

int main() {
	char op;
	Libro libros[] = {
		{"Yo visite ganimedes", "Carlos", "1", 2020, "Editorial A", true, "L123"},
	{"El poder de ahora", "Melfy", "2", 2018, "Editorial B", false, "L456"},
		{"Los juegos del hambre", "Cristian", "3", 2019, "Editorial C", true, "L789"},
	{"El juego infinito", "Jeremias", "4", 2017, "Editorial A", false, "L012"},
		{"Aprende C++", "Lulu", "5", 2021, "Editorial B", true, "L345"}
	};
	Usuario usuarios[] = {
		{1, "Carlos", "Montero", "carlosmontero@gmail.com", 25},
	{2, "Eduardo", "Flores", "eduardoflores@gmail.com", 30},
		{3, "Johanna", "Ponce", "johannaponce@gmail.com", 28},
	{4, "Maria", "Guzman", "mariaguzman@gmail.com", 22},
		{5, "Hernan", "Rodriguez", "hernanrodriguez@gmail.com", 35}
	};
	Bibliotecario bibliotecarios[] = {
		{101, "Oscar", "Fernandez", "oscarfernandez@gmail.com", "Ciencia Ficción"},
	{102, "Mario", "Lazarte", "mariolazarte@gmail.com", "Historia"},
		{103, "Daniel", "Baspineiro", "danielbaspineiro@gmail.com", "Biografías"},
	{104, "Leopoldo", "Ruiz", "leopoldoruiz@gmail.com", "Tecnología"},
		{105, "Nicol", "Arce", "nicolarce@gmail.com", "Misterio"}
	};
	
	do {
		cout << " Bienvenidos al Menu" << endl;
		cout << " 1 .- Llenados de Datos " << endl;
		cout << " 2 .- Listados " << endl;
		cout << " 3 .- Busquedas " << endl;
		cout << " 0 .- OPCION PARA SALIR DEL MENU " << endl;
		
		cin >> op;
		op = toupper(op);
		system("cls");
		
		switch (op) {
		case '1':
			// Función para llenar e imprimir datos aleatoriamente
			srand(time(0));
			
			cout << "Libros:\n";
			imprimirLibrosAleatoriamente(libros, 5);
			
			cout << "\nUsuarios:\n";
			imprimirUsuariosAleatoriamente(usuarios, 5);
			
			cout << "\nBibliotecarios:\n";
			imprimirBibliotecariosAleatoriamente(bibliotecarios, 5);
			break;
			
		case '2':
			char opListados;
			do {
				cout << " Listados" << endl;
				cout << " A) Listado de Libros" << endl;
				cout << " B) Listado Usuarios" << endl;
				cout << " C) Listado Bibliotecarios" << endl;
				cout << " X) Salir al Menú Principal" << endl;
				
				cin >> opListados;
				opListados = toupper(opListados);
				system("cls");
				
				switch (opListados) {
				case 'A':
					cout << "Listado de Libros" << endl;
					imprimirLibrosAleatoriamente(libros, 5);
					break;
				case 'B':
					cout << "Listado de Usuarios" << endl;
					imprimirUsuariosAleatoriamente(usuarios, 5);
					break;
				case 'C':
					cout << "Listado de Bibliotecarios" << endl;
					imprimirBibliotecariosAleatoriamente(bibliotecarios, 5);
					break;
				case 'X':
					cout << "Volviendo al Menú Principal" << endl;
					break;
				default:
					cout << "Opción inválida, por favor elija una opción válida del submenú." << endl;
				}
				
				system("pause");
				system("cls");
			} while (opListados != 'X');
			break;
			
		case '3':
			char opBusqueda;
			do {
				cout << " Busquedas" << endl;
				cout << " A) Buscar Libro" << endl;
				cout << " B) Buscar Usuario" << endl;
				cout << " C) Buscar Bibliotecario" << endl;
				cout << " X) Salir al Menú Principal" << endl;
				
				cin >> opBusqueda;
				opBusqueda = toupper(opBusqueda);
				system("cls");
				
				switch (opBusqueda) {
				case 'A':
					cout << "Busqueda de Libro" << endl;
					busquedaLibro(libros, 5);
					break;
				case 'B':
					cout << "Busqueda de Usuario" << endl;
					busquedaUsuario(usuarios, 5);
					break;
				case 'C':
					cout << "Busqueda de Bibliotecario" << endl;
					busquedaBibliotecario(bibliotecarios, 5);
					break;
				case 'X':
					cout << "Volviendo al Menú Principal" << endl;
					break;
				default:
					cout << "Opción inválida, por favor elija una opción válida del submenú." << endl;
				}
				
				system("pause");
				system("cls");
			} while (opBusqueda != 'X');
			break;
			
		case '0':
			cout << " USTED SALIO DEL MENU, UN GUSTO PODER ATENDERLO " << endl;
			break;
			
		default:
			cout << " ERROR NO COLOCO NINGUNA DE LAS OPCIONES DEL MENU " << endl;
			cout << " PORFAVOR COLOCAR OPCION QUE SE MUESTRA EN MENU " << endl;
		}
		
		system("pause");
		system("cls");
		
	} while (op != '0');
	
	return 0;
}
