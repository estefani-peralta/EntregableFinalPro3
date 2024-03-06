#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class Libro {
	string strTitulo;
	string strAutor;
	int nISBN;
	int nAnioPublicacion;
	string strEditorial;
	string strEstado; // Valores posibles: "disponible", "prestado", "reservado"
	int nPaginas;
	
public:
	Libro() {
		strTitulo = generarTituloAleatorio();
		strAutor = generarAutorAleatorio();
		nISBN = generarISBNAleatorio();
		nAnioPublicacion = generarAnioPublicacionAleatorio();
		strEditorial = generarEditorialAleatorio();
		strEstado = generarEstadoAleatorio();
		nPaginas = generarPaginasAleatorio();
	}
	
	int get_ISBN() { return nISBN; }
	void set_ISBN(int isbn) { nISBN = isbn; }
	
	string get_Titulo() { return strTitulo; }
	void set_Titulo(string titulo) { strTitulo = titulo; }
	
	string get_Autor() const { return strAutor; }
	void set_Autor(string autor) { strAutor = autor; }
	
	int get_AnioPublicacion() { return nAnioPublicacion; }
	void set_AnioPublicacion(int anio) { nAnioPublicacion = anio; }
	
	string get_Editorial() { return strEditorial; }
	void set_Editorial(string editorial) { strEditorial = editorial; }
	
	string get_Estado() { return strEstado; }
	void set_Estado(string estado) { strEstado = estado; }
	
	int get_Paginas() { return nPaginas; }
	void set_Paginas(int paginas) { nPaginas = paginas; }
	
	string generarTituloAleatorio() {
		string arrTitulos[] = {"el viejo y el mar", "rebelión en la granja", "la isla del tesoro", "el corazón de la luz", "aprende programación", "inteligencia artificial", "ciberseguridad esencial", "javaScript moderno", "arduino proyectos"};
		int indice = rand() % (sizeof(arrTitulos) / sizeof(arrTitulos[0]));
		return arrTitulos[indice];
	}
	
	string generarAutorAleatorio() {
		string arrNombresAutores[] = {"Alejandro", "Emiliano", "Francisco", "Antonieta", "Cristobal", "Valentina", "Magdalena", "Antonella"};
		string arrApellidosAutores[] = {"Gutiérrez", "Dominguez", "Martínez", "Hernández", "Pausinis", "Fernández", "Carrasco", "Rodríguez"};
		int indice = rand() % (sizeof(arrNombresAutores) / sizeof(arrNombresAutores[0]));
		return arrNombresAutores[indice] + " " + arrApellidosAutores[indice];
	}
	
	int generarISBNAleatorio() {
		static int isbn = 0;
		isbn = rand() % 1000 + 1; // Reiniciar isbn con un valor aleatorio entre 1 y 1000
		return isbn++;
	}
	
	
	
	
	int generarAnioPublicacionAleatorio() {
		int anioMinimo = 1845;
		int anioMaximo = 2020;
		return anioMinimo + rand() % (anioMaximo - anioMinimo + 1);
	}
	
	string generarEditorialAleatorio() {
		string arrEditoriales[] = {"Editorial Santillana", "Acantilado Editorial", "Editorial Alfaguara", "Editorial Planeta", "Anagrama Editorial", "Ediciones Sir", "Alianza Editorial", "Ediciones Siglo XXI"};
		int indice = rand() % (sizeof(arrEditoriales) / sizeof(arrEditoriales[0]));
		return arrEditoriales[indice];
	}
	
	string generarEstadoAleatorio() {
		string arrEstados[] = {"Prestado", "Reservado", "Disponible"};
		int indice = rand() % (sizeof(arrEstados) / sizeof(arrEstados[0]));
		return arrEstados[indice];
	}
	
	int generarPaginasAleatorio() {
		int paginaMinima = 300;
		int paginaMaxima = 400;
		return paginaMinima + rand() % (paginaMaxima - paginaMinima + 1);
	}
	
	void mostrarDatos() {
		cout << "ISBN:" << setw(5) << get_ISBN()
			<< "\tTitulo:" << setw(25) << get_Titulo()
			<< "\tAutor:" << setw(25) << get_Autor()
			<< "\tAño publicacion:" << setw(5) << get_AnioPublicacion()
			<< "\tEditorial:" << setw(25) << get_Editorial()
			<< "\tPaginas:" << setw(5) << get_Paginas() << endl;
	}
	
	void mostrarDatos(string t) {
		cout << get_ISBN() << "\t\t" << get_Titulo() << "\t\t" << get_Autor() << "\t\t" << get_AnioPublicacion() << "\t\t"
			<< get_Editorial() << "\t\t" << get_Paginas() << endl;
	}
	
	
};

class Usuario {
	int nUserID;
	string strNombre;
	string strApellido;
	string strEmail;
	int nEdad;
	
public:
	Usuario() {
		nUserID = generarUserIDAleatorio();
		strNombre = generarNombreAleatorio();
		strApellido = generarApellidoAleatorio();
		strEmail = generarEmail(strNombre, strApellido);
		nEdad = generarEdadAleatoria();
	}
	
	int get_UserID() { return nUserID; }
	void set_UserID(int userID) { nUserID = userID; }
	
	string get_Nombre() { return strNombre; }
	void set_Nombre(string nombre) { strNombre = nombre; }
	
	string get_Apellido() { return strApellido; }
	void set_Apellido(string apellido) { strApellido = apellido; }
	
	string get_Email() { return strEmail; }
	void set_Email(string email) { strEmail = email; }
	
	int get_Edad() { return nEdad; }
	void set_Edad(int edad) { nEdad = edad; }
	
	int generarUserIDAleatorio() {
		static int userID = 0;
		return ++userID;
	}
	
	string generarNombreAleatorio() {
		string arrNombres[] = {"Gabriela", "Isabella", "Valentina", "Fernando", "Benjamin", "Jhonatan", "Leonardo", "Salvador"};
		int indice = rand() % (sizeof(arrNombres) / sizeof(arrNombres[0]));
		return arrNombres[indice];
	}
	
	string generarApellidoAleatorio() {
		string arrApellidos[] = {"González", "Montanese", "Martínez", "Pausinis", "Rodríguez", "Villegas", "Fernández", "Clemente"};
		int indice = rand() % (sizeof(arrApellidos) / sizeof(arrApellidos[0]));
		return arrApellidos[indice];
	}
	
	string generarEmail(string nombre, string apellido) {
		string email = nombre + apellido + "@gmail.com";
		return email;
	}
	
	int generarEdadAleatoria() {
		int edadMinima = 18;
		int edadMaxima = 65;
		return edadMinima + rand() % (edadMaxima - edadMinima + 1);
	}
	
	void mostrarDatos() {
		cout << "ID:" << get_UserID() << endl;
		cout << "Nombre:" << get_Nombre() << endl;
		cout << "Apellido:" << get_Apellido() << endl;
		cout << "Email:" << get_Email() << endl;
		cout << "Edad:" << get_Edad() << endl;
	}
	
	void mostrarDatos(string t) {
		cout << get_UserID() << "\t\t" << get_Nombre() << "\t\t" << get_Apellido() << "\t\t" << get_Email() << "\t\t" << get_Edad() << endl;
	}
	
	
};

class Bibliotecario : public Usuario {
	string strCargo;
	
public:
	Bibliotecario() {
		strCargo = generarCargoAleatorio();
	}
	
	string get_cargo() { return strCargo; }
	void set_cargo(string cargo) { strCargo = cargo; }
	
	string generarCargoAleatorio() {
		string arrCargos[] = {"Bibliotecario Infantil", "Asistente de Referencia", "Auxiliar de Biblioteca", "Encargado de Adquisiciones", "Coordinador de Programas Educativos"};
		int indice = rand() % (sizeof(arrCargos) / sizeof(arrCargos[0]));
		return arrCargos[indice];
	}
	
	void mostrarDatos() {
		cout << "ID:" << get_UserID() << endl;
		cout << "Nombre:" << get_Nombre() << endl;
		cout << "Apellido:" << get_Apellido() << endl;
		cout << "Email:" << get_Email() << endl;
		cout << "Cargo:" << get_cargo() << endl;
	}
	
	void mostrarDatos(string t) {
		cout << get_UserID() << "\t\t" << get_Nombre() << "\t\t" << get_Apellido() << "\t\t" << get_Email() << "\t\t" << get_cargo() << endl;
	}
	
};

void submenuListados(Libro libros[], Usuario usuarios[], Bibliotecario bibliotecarios[], const int tam, int formatoGeneral) {
	char opcionListados;
	do {
		cout << "SUBMENU LISTADOS" << endl;
		cout << "A) Listado de Libros" << endl;
		cout << "B) Listado Usuarios" << endl;
		cout << "C) Listado Bibliotecarios" << endl;
		cout << "X) Salir" << endl;
		cout << "Ingrese su opción: ";
		cin >> opcionListados;
		
		switch (opcionListados) {
		case 'A':
			cout << "LISTADO DE LIBROS" << endl;
			if (formatoGeneral == 1) {
				for (int i = 0; i < tam; ++i) {
					libros[i].mostrarDatos();
				}
			} else {
				cout << setw(5) << "ISBN" << setw(25) << "Titulo" << setw(25) << "Autor" << setw(8) << "Año" << setw(25) << "Editorial" << setw(8) << "Páginas" << endl;
				for (int i = 0; i < tam; ++i) {
					libros[i].mostrarDatos("columna");
				}
			}
			break;
			
		case 'B':
			cout << "LISTADO DE USUARIOS" << endl;
			if (formatoGeneral == 1) {
				for (int i = 0; i < tam; ++i) {
					usuarios[i].mostrarDatos();
				}
			} else {
				cout << setw(5) << "ID" << setw(15) << "Nombre" << setw(15) << "Apellido" << setw(20) << "Email" << setw(5) << "Edad" << endl;
				for (int i = 0; i < tam; ++i) {
					usuarios[i].mostrarDatos("columna");
				}
			}
			break;
			
		case 'C':
			cout << "LISTADO DE BIBLIOTECARIOS" << endl;
			if (formatoGeneral == 1) {
				for (int i = 0; i < tam; ++i) {
					bibliotecarios[i].mostrarDatos();
				}
			} else {
				cout << setw(5) << "ID" << setw(15) << "Nombre" << setw(15) << "Apellido" << setw(20) << "Email" << setw(20) << "Cargo" << endl;
				for (int i = 0; i < tam; ++i) {
					bibliotecarios[i].mostrarDatos("columna");
				}
			}
			break;
			
		case 'X':
			cout << "Saliendo del submenu de listados." << endl;
			break;
		default:
			cout << "Opción no válida. Intente de nuevo." << endl;
		}
	} while (opcionListados != 'X');
}




int main() {
	const int tam = 8;
	Libro libros[tam];
	Usuario usuarios[tam];
	Bibliotecario bibliotecarios[tam];
	int opcion;
	int formatoGeneral;  // Nueva variable para el formato
	
	do {
		cout << "MENU" << endl;
		cout << "1) Llenado de datos" << endl;
		cout << "2) Listados" << endl;
		cout << "0) Salir" << endl;
		cout << "Ingrese su opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			// Llenado de datos orientado a objetos
			for (int i = 0; i < tam; ++i) {
				libros[i] = Libro();
				usuarios[i] = Usuario();
				bibliotecarios[i] = Bibliotecario();
			}
			cout << "Datos llenados correctamente." << endl;
			break;
			
		case 2:
			// Verifica si los datos se han llenado antes de mostrar los listados
			if (libros[0].get_Titulo().empty()) {
				cout << "Debe llenar los datos primero." << endl;
				break;
			}
			
			cout << "Elija el formato de presentación:" << endl;
			cout << "1) Columna" << endl;
			cout << "2) Horizontal" << endl;
			cout << "Ingrese su opción: ";
			cin >> formatoGeneral;
			
			submenuListados(libros, usuarios, bibliotecarios, tam, formatoGeneral);
			break;
			
		case 0:
			cout << "Saliendo del programa. ¡Hasta luego!" << endl;
			break;
			
		default:
			cout << "Opción no válida. Intente de nuevo." << endl;
		}
	} while (opcion != 0);
	
	return 0;
 }
