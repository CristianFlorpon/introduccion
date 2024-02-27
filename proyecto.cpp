#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

// Estructura para representar un Libro
struct Libro {
	string titulo;
	string autor;
	string ISBN;
	int publicationYear;
	string editorial;
	bool disponible;
	string num_registro;
};

// Estructura para representar un Usuario
struct Usuario {
	int userID;
	string nombre;
	string apellido;
	string email;
	int edad;
};

// Estructura para representar un Bibliotecario
struct Bibliotecario {
	int employeeID;
	string nombre;
	string apellido;
	string email;
	string especialidad;
};

void imprimirLibro(const Libro* libro) {
	cout << setw(30) << left << libro->titulo << setw(20) << left << libro->autor << setw(10) << left << libro->ISBN << setw(20) << left << libro->publicationYear
		<< setw(15) << left << libro->editorial << setw(15) << left << libro->num_registro << setw(25) << left << (libro->disponible ? "Disponible para leer" : "No disponible para leer") << endl;
}

void imprimirLibro(const Libro& libro) {
	imprimirLibro(&libro);
}

void imprimirLibrosAleatoriamente(Libro* libros, int size) {
	random_shuffle(libros, libros + size, [](int n) { return rand() % n; });
	
	cout << setw(30) << left << "Libro" << setw(20) << left << "Autor" << setw(10) << left << "ISBN" << setw(20) << left << "Año de Publicación"
		<< setw(15) << left << "Editorial" << setw(15) << left << "Num. Registro" << setw(25) << left << "Disponibilidad" << endl;
	
	for (int i = 0; i < size; ++i) {
		imprimirLibro(&libros[i]);
	}
}

void imprimirUsuario(const Usuario* usuario) {
	cout << usuario->userID << "\t" << setw(15) << left << usuario->nombre << "\t" << setw(15) << left << usuario->apellido << "\t" << usuario->email
		<< "\tEdad: " << usuario->edad << endl;
}

void imprimirUsuario(const Usuario& usuario) {
	imprimirUsuario(&usuario);
}

void imprimirUsuariosAleatoriamente(Usuario* usuarios, int size) {
	random_shuffle(usuarios, usuarios + size, [](int n) { return rand() % n; });
	
	cout << "\nUsuarios" << endl;
	cout << "UserID\tNombre\t\tApellido\t\tEmail\t\tEdad" << endl;
	
	for (int i = 0; i < size; ++i) {
		imprimirUsuario(&usuarios[i]);
	}
}

void imprimirBibliotecario(const Bibliotecario* bibliotecario) {
	cout << bibliotecario->employeeID << "\t" << setw(15) << left << bibliotecario->nombre << "\t" << setw(15) << left << bibliotecario->apellido << "\t"
		<< bibliotecario->email << "\tEspecialidad: " << bibliotecario->especialidad << endl;
}

void imprimirBibliotecario(const Bibliotecario& bibliotecario) {
	imprimirBibliotecario(&bibliotecario);
}

void imprimirBibliotecariosAleatoriamente(Bibliotecario* bibliotecarios, int size) {
	random_shuffle(bibliotecarios, bibliotecarios + size, [](int n) { return rand() % n; });
	
	cout << "\nBibliotecarios" << endl;
	cout << "EmployeeID\tNombre\t\tApellido\t\tEmail\t\tEspecialidad" << endl;
	
	for (int i = 0; i < size; ++i) {
		imprimirBibliotecario(&bibliotecarios[i]);
	}
}

void mostrarListadoLibros(Libro* libros, int size) {
	random_shuffle(libros, libros + size, [](int n) { return rand() % n; });
	
	cout << setw(30) << left << "Libro" << setw(20) << left << "Autor" << setw(10) << left << "ISBN" << setw(20) << left << "Año de Publicación"
		<< setw(15) << left << "Editorial" << setw(15) << left << "Num. Registro" << setw(25) << left << "Disponibilidad" << endl;
	
	for (int i = 0; i < size; ++i) {
		imprimirLibro(&libros[i]);
	}
}

void mostrarListadoUsuarios(Usuario* usuarios, int size) {
	random_shuffle(usuarios, usuarios + size, [](int n) { return rand() % n; });
	
	cout << "UserID\tNombre\t\tApellido\t\tEmail\t\tEdad" << endl;
	
	for (int i = 0; i < size; ++i) {
		imprimirUsuario(&usuarios[i]);
	}
}

void mostrarListadoBibliotecarios(Bibliotecario* bibliotecarios, int size) {
	random_shuffle(bibliotecarios, bibliotecarios + size, [](int n) { return rand() % n; });
	
	cout << "EmployeeID\tNombre\t\tApellido\t\tEmail\t\tEspecialidad" << endl;
	
	for (int i = 0; i < size; ++i) {
		imprimirBibliotecario(&bibliotecarios[i]);
	}
}

void busquedaLibro(Libro* libros, int size) {
	string tituloBuscado;
	cout << "Ingrese el título o parte del título a buscar: ";
	cin.ignore();
	getline(cin, tituloBuscado);
	
	cout << setw(30) << left << "Libro" << setw(20) << left << "Autor" << setw(10) << left << "ISBN" << setw(20) << left << "Año de Publicación"
		<< setw(15) << left << "Editorial" << setw(15) << left << "Num. Registro" << setw(25) << left << "Disponibilidad" << endl;
	
	for (int i = 0; i < size; ++i) {
		if (libros[i].titulo.find(tituloBuscado) != string::npos) {
			imprimirLibro(&libros[i]);
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
			imprimirUsuario(&usuarios[i]);
		}
	}
}

void busquedaBibliotecario(Bibliotecario* bibliotecarios, int size) {
	char letraBuscada;
	cout << "Ingrese la letra del apellido a buscar: ";
	cin >> letraBuscada;
	
	cout << "EmployeeID\tNombre\t\tApellido\t\tEmail\t\tEspecialidad" << endl;
	
	for (int i = 0; i < size; ++i) {
		if (bibliotecarios[i].apellido[0] == letraBuscada) {
			imprimirBibliotecario(&bibliotecarios[i]);
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
			llenarEImprimirDatosAleatoriamente(libros, usuarios, bibliotecarios);
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
					mostrarListadoLibros(libros, 5);
					break;
				case 'B':
					cout << "Listado de Usuarios" << endl;
					mostrarListadoUsuarios(usuarios, 5);
					break;
				case 'C':
					cout << "Listado de Bibliotecarios" << endl;
					mostrarListadoBibliotecarios(bibliotecarios, 5);
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
			char opBusquedas;
			do {
				cout << " Submenú de Búsquedas" << endl;
				cout << " A) Búsqueda de Libro (Titulo)" << endl;
				cout << " B) Lista Búsqueda do Usuario (Nombre y apellido)" << endl;
				cout << " C) Búsqueda Bibliotecarios (Nombre y apellido)" << endl;
				cout << " X) Salir al Menú Principal" << endl;
				
				cin >> opBusquedas;
				opBusquedas = toupper(opBusquedas);
				system("cls");
				
				switch (opBusquedas) {
				case 'A':
					cout << "Búsqueda de Libro" << endl;
					busquedaLibro(libros, 5);
					break;
				case 'B':
					cout << "Búsqueda de Usuario por Apellido" << endl;
					busquedaUsuario(usuarios, 5);
					break;
				case 'C':
					cout << "Búsqueda de Bibliotecario por Apellido" << endl;
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
			} while (opBusquedas != 'X');
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
