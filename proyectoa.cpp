
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Usuario {
protected:
	int nUserID;
	string strNombre;
	string strApellido;
	string strEmail;
	int nEdad;
	
public:
	Usuario() : nUserID(0), strNombre(""), strApellido(""), strEmail(""), nEdad(0) {}
	
	Usuario(int userID, string nombre, string apellido, int edad) :
		nUserID(userID), strNombre(nombre), strApellido(apellido), nEdad(edad) {
		set_strEmail(); // Generar email automáticamente al crear la persona
	}
	
	int get_nUserID() const { return nUserID; }
	void set_nUserID(int userID) { nUserID = userID; }
	
	string get_strNombre() const { return strNombre; }
	void set_strNombre(const string& nombre) { strNombre = nombre; }
	
	string get_strApellido() const { return strApellido; }
	void set_strApellido(const string& apellido) { strApellido = apellido; }
	
	string get_strEmail() const { return strEmail; }
	void set_strEmail() { strEmail = strNombre + strApellido + "@gmail.com"; }
	
	int get_nEdad() const { return nEdad; }
	void set_nEdad(int edad) { nEdad = edad; }
	
	virtual void imprimirPrivilegios() const {
		cout << "Privilegios de usuario básico." << endl;
	}
};

class UsuarioNormal : public Usuario {
public:
	UsuarioNormal() : Usuario() {}
	
	UsuarioNormal(int userID, string nombre, string apellido, int edad) :
		Usuario(userID, nombre, apellido, edad) {}
	
	void imprimirPrivilegios() const override {
		cout << "Privilegios de usuario normal." << endl;
	}
};

class UsuarioAdmin : public Usuario {
public:
	UsuarioAdmin() : Usuario() {}
	
	UsuarioAdmin(int userID, string nombre, string apellido, int edad) :
		Usuario(userID, nombre, apellido, edad) {}
	
	void imprimirPrivilegios() const override {
		cout << "Privilegios de administrador." << endl;
	}
};

class Libro {
protected:
	int nLibroID;
	string strNombreLibro;
	string strAutor;
	string strISBN;
	int nAnioPublicacion;
	string strEditorial;
	int nNumeroRegistro;
	bool bDisponible;
	
public:
	Libro() : nLibroID(0), strNombreLibro(""), strAutor(""), strISBN(""),
		nAnioPublicacion(0), strEditorial(""), nNumeroRegistro(0), bDisponible(true) {}
	
	Libro(int libroID, string nombreLibro, string autor, string ISBN,
		  int anioPublicacion, string editorial, int numeroRegistro, bool disponible) :
		nLibroID(libroID), strNombreLibro(nombreLibro), strAutor(autor),
		strISBN(ISBN), nAnioPublicacion(anioPublicacion), strEditorial(editorial),
		nNumeroRegistro(numeroRegistro), bDisponible(disponible) {}
	
	// Métodos de acceso para obtener los valores de los atributos
	int get_nLibroID() const { return nLibroID; }
	string get_strNombreLibro() const { return strNombreLibro; }
	string get_strAutor() const { return strAutor; }
	string get_strISBN() const { return strISBN; }
	int get_nAnioPublicacion() const { return nAnioPublicacion; }
	string get_strEditorial() const { return strEditorial; }
	int get_nNumeroRegistro() const { return nNumeroRegistro; }
	bool get_bDisponible() const { return bDisponible; }
	
	void imprimirDetalles() const {
		cout << "ID del Libro: " << get_nLibroID() << endl;
		cout << "Nombre del Libro: " << get_strNombreLibro() << endl;
		cout << "Autor: " << get_strAutor() << endl;
		cout << "ISBN: " << get_strISBN() << endl;
		cout << "Año de Publicación: " << get_nAnioPublicacion() << endl;
		cout << "Editorial: " << get_strEditorial() << endl;
		cout << "Número de Registro: " << get_nNumeroRegistro() << endl;
		cout << "Disponible para leer: " << (get_bDisponible() ? "Sí" : "No") << endl;
	}
};

void imprimirDatosUsuario(const Usuario& u) {
	cout << "ID: " << u.get_nUserID() << endl;
	cout << "Nombre: " << u.get_strNombre() << endl;
	cout << "Apellido: " << u.get_strApellido() << endl;
	cout << "Edad: " << u.get_nEdad() << endl;
	cout << "Email: " << u.get_strEmail() << endl;
	u.imprimirPrivilegios();
	cout << "------------------------" << endl;
}

void llenadoDatosUsuarios(UsuarioNormal usuarios[]) {
	string nombres[] = {"Carlos", "Melfy", "Johanna", "Carla", "Cristian", "Eduardo", "Nicol", "Maria", "Jorge", "Jeremias"};
	
	srand(time(0));
	
	for (int i = 0; i < 10; i++) {
		string nombre = nombres[rand() % 10];
		string apellido = "Apellido" + to_string(i + 1);
		int edad = rand() % 36 + 15;
		int userID = rand() % 1000 + 1;
		
		usuarios[i] = UsuarioNormal(userID, nombre, apellido, edad);
	}
}

void imprimirUsuariosEnTabla(const UsuarioNormal& usuario) {
	cout << "| " << usuario.get_nUserID() << "\t| " << usuario.get_strNombre() << "\t| "
		<< usuario.get_strApellido() << "\t| " << usuario.get_nEdad() << "\t| "
		<< usuario.get_strEmail() << "\t| ";
	usuario.imprimirPrivilegios();
	cout << endl;
}

void imprimirUsuariosEnBloque(const UsuarioNormal& usuario) {
	cout << "ID: " << usuario.get_nUserID() << endl;
	cout << "Nombre: " << usuario.get_strNombre() << endl;
	cout << "Apellido: " << usuario.get_strApellido() << endl;
	cout << "Edad: " << usuario.get_nEdad() << endl;
	cout << "Email: " << usuario.get_strEmail() << endl;
	usuario.imprimirPrivilegios();
	cout << "------------------------" << endl;
}

void imprimirLibrosEnTabla(const Libro& libro) {
	cout << "| " << libro.get_nLibroID() << "\t| " << libro.get_strNombreLibro() << "\t| "
		<< libro.get_strAutor() << "\t| " << libro.get_nAnioPublicacion() << "\t| "
		<< libro.get_strEditorial() << "\t| " << (libro.get_bDisponible() ? "Sí" : "No") << "\t| ";
	cout << endl;
}

void imprimirLibrosEnBloque(const Libro& libro) {
	cout << "ID del Libro: " << libro.get_nLibroID() << endl;
	cout << "Nombre del Libro: " << libro.get_strNombreLibro() << endl;
	cout << "Autor: " << libro.get_strAutor() << endl;
	cout << "Año de Publicación: " << libro.get_nAnioPublicacion() << endl;
	cout << "Editorial: " << libro.get_strEditorial() << endl;
	cout << "Número de Registro: " << libro.get_nNumeroRegistro() << endl;
	cout << "Disponible para leer: " << (libro.get_bDisponible() ? "Sí" : "No") << endl;
	cout << "------------------------" << endl;
}

void llenadoDatosLibros(Libro libros[]) {
	string titulos[] = {"Harry Potter", "Cien años de soledad", "1984", "El señor de los anillos", "Don Quijote de la Mancha",
		"Orgullo y prejuicio", "Crimen y castigo", "Matar a un ruiseñor", "El gran Gatsby", "Ulises"};
	
	srand(time(0));
	
	for (int i = 0; i < 10; i++) {
		string titulo = titulos[i];
		string autor = "Autor" + to_string(i + 1);
		string ISBN = "ISBN-" + to_string(i + 1);
		int anioPublicacion = rand() % 50 + 1970; // Año entre 1970 y 2019
		string editorial = "Editorial" + to_string(i + 1);
		int numeroRegistro = rand() % 1000 + 1;
		bool disponible = rand() % 2 == 0;
		
		libros[i] = Libro(i + 1, titulo, autor, ISBN, anioPublicacion, editorial, numeroRegistro, disponible);
	}
}

void menu() {
	cout << " Bienvenidos al Menu " << endl;
	cout << " 1 .- Llenado de datos " << endl;
	cout << " 2 .- Listados " << endl;
	cout << " 3 .- Busquedas " << endl;
	cout << " S/s OPCION PARA SALIR DEL MENU " << endl;
}

void listadosSubMenu(bool datosLlenados, UsuarioNormal usuarios[], Libro libros[]) {
	char op;
	do {
		cout << "LISTADOS" << endl;
		cout << " A) Listado de Libros" << endl;
		cout << " B) Listado Usuarios" << endl;
		cout << " C) Listado Bibliotecarios" << endl;
		cout << " D) Salir" << endl;
		cin >> op;
		op = toupper(op);
		system("cls");
		switch (op) {
		case 'A':
			if (datosLlenados) {
				cout << "Has seleccionado Listado de Libros" << endl;
				cout << "Elija el formato de visualización:" << endl;
				cout << "1) Tabla" << endl;
				cout << "2) Bloque" << endl;
				int formato;
				cin >> formato;
				switch (formato) {
				case 1:
					cout << "| ID\t| Nombre\t\t| Autor\t\t| Año Publicación\t| Editorial\t\t| Disponible\t| " << endl;
					cout << "-------------------------------------------------------------" << endl;
					// Lógica para mostrar en tabla
					for (int i = 0; i < 10; i++) {
						imprimirLibrosEnTabla(libros[i]);
					}
					break;
				case 2:
					// Lógica para mostrar en bloque
					for (int i = 0; i < 10; i++) {
						imprimirLibrosEnBloque(libros[i]);
					}
					break;
				default:
					cout << "Formato no válido. Mostrando en tabla por defecto." << endl;
					// Lógica para mostrar en tabla por defecto
					break;
				}
			} else {
				cout << "Error: Primero debes llenar los datos de libros (opción 1)" << endl;
			}
			break;
		case 'B':
			if (datosLlenados) {
				cout << "Has seleccionado Listado Usuarios" << endl;
				cout << "Elija el formato de visualización:" << endl;
				cout << "1) Tabla" << endl;
				cout << "2) Bloque" << endl;
				int formato;
				cin >> formato;
				switch (formato) {
				case 1:
					cout << "| ID\t| Nombre\t| Apellido\t| Edad\t| Email\t\t\t| Privilegios" << endl;
					cout << "-------------------------------------------------------------" << endl;
					// Lógica para mostrar en tabla
					for (int i = 0; i < 10; i++) {
						imprimirUsuariosEnTabla(usuarios[i]);
					}
					break;
				case 2:
					// Lógica para mostrar en bloque
					for (int i = 0; i < 10; i++) {
						imprimirUsuariosEnBloque(usuarios[i]);
					}
					break;
				default:
					cout << "Formato no válido. Mostrando en tabla por defecto." << endl;
					// Lógica para mostrar en tabla por defecto
					break;
				}
			} else {
				cout << "Error: Primero debes llenar los datos de usuarios (opción 1)" << endl;
			}
			break;
		case 'C':
			cout << "Has seleccionado Listado Bibliotecarios" << endl;
			// Aquí puedes poner la lógica para listar los bibliotecarios
			break;
		case 'D':
			cout << "Volviendo al menú principal" << endl;
			break;
		default:
			cout << "Opción inválida" << endl;
		}
		system("pause");
		system("cls");
	} while (op != 'D');
}

int main() {
	char op;
	bool datosLlenadosUsuarios = false;
	bool datosLlenadosLibros = false;
	UsuarioNormal usuarios[10];
	Libro libros[10];
	
	do {
		menu();
		cin >> op;
		op = toupper(op);
		system("cls");
		switch (op) {
		case '1':
			llenadoDatosUsuarios(usuarios);
			llenadoDatosLibros(libros);
			datosLlenadosUsuarios = true;
			datosLlenadosLibros = true;
			break;
		case '2':
			listadosSubMenu(datosLlenadosUsuarios, usuarios, libros);
			break;
		case '3':
			cout << "Has seleccionado Busquedas" << endl;
			// Aquí puedes poner la lógica para búsquedas
			break;
		case 'S':
			cout << " USTED SALIO DEL MENU, UN GUSTO PODER ATENDERLO " << endl;
			break;
		default:
			cout << " ERROR NO COLOCO NINGUNA DE LAS OPCIONES DEL MENU " << endl;
			cout << " PORFAVOR COLOCAR OPCION QUE SE MUESTRA EN MENU " << endl;
		}
		system("pause");
		system("cls");
	} while (op != 'S');
	return 0;
}
