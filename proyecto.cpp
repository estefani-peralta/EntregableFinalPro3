#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const size_t TAMANO = 9;

// Definicion de la clase Libro
class Libro {
private:
	int nISBN;
	string sTitulo;
	string sAutor;
	int nPublicacion;
	string sEditorial;
	string sEstado; // Valores posibles: "disponible", "prestado", "reservado"
	int nPaginas;
public:
	Libro() {
		this->nISBN = 0;
		this->sTitulo = "";
		this->sAutor = "";
		this->nPublicacion = 0;
		this->sEditorial = "";
		this->sEstado = "";
		this->nPaginas = 0;
	}
	// Constructor por atributos
	Libro(int isbn, string titulo, string autor, int publicacion, string  editorial, string estado, int paginas) {
		this->nISBN = isbn;
		this->sTitulo = titulo;
		this->sAutor = autor;
		this->nPublicacion = publicacion;
		this->sEditorial = editorial;
		this->sEstado = estado;
		this->nPaginas = paginas;
	}
	// Devuelve el valor actual de un atributo.
	int get_ISBN() const { return nISBN; }
	void set_ISBN(int isbn) { nISBN = isbn; }//Establece un nuevo valor para un atributo.
	
	string get_Titulo() const { return sTitulo; }
	void set_Titulo(const string& titulo) { sTitulo = titulo; }
	
	string get_Autor() const { return sAutor; }
	void set_Autor(const string& autor) { sAutor = autor; }
	
	int get_Publicacion() const { return nPublicacion; }
	void set_Publicacion(int publicacion) { nPublicacion = publicacion; }
	
	string get_Editorial() const { return sEditorial; }
	void set_Editorial(const string& editorial) { sEditorial = editorial; }
	
	string get_Estado() const { return sEstado; }
	void set_Estado(const string& estado) { sEstado = estado; }
	
	int get_Paginas() const { return nPaginas; }
	void set_Paginas(int paginas) { nPaginas = paginas; }
};
// Definicion de la clase Persona
class Persona {
private:
	int nID;
	string sNombre;
	string sApellido;
	string sEmail;
public:
	Persona() {
		this->nID = 0;
		this->sNombre = "";
		this->sApellido = "";
		this->sEmail = "";
	}
	// Constructor por parametros
	Persona(int id, string nombre, string apellido, string email) {
		this->nID = id;
		this->sNombre = nombre;
		this->sApellido = apellido;
		this->sEmail = email;
	}
	// Metodos de obtencion de los atributos
	int get_ID() const { return nID; }
	void set_ID(int id) { nID = id;}
	
	string get_Nombre() const { return sNombre; }
	void set_Nombre(const string& nombre) { sNombre = nombre; }
	
	string get_Apellido() const { return sApellido; }
	void set_Apellido(const string& apellido) { sApellido = apellido; }
	
	string get_Email() const { return sEmail; }
	void set_Email(const string& email) { sEmail = email; }
};
// Definicion de la clase Usuario
class Usuario : public Persona {
private:
	int nEdad;
public:
	Usuario() {
		this->nEdad = 0;
	}
		//constructor por parametros
	Usuario(int id, string nombre, string apellido, string email, int edad): Persona(id, nombre, apellido, email){
		this->nEdad=edad;
	}
	int get_Edad() const{ return nEdad; }
	void set_Edad(int edad) { nEdad = edad; }
};
// Definicion de la clase Bibliotecario
class Bibliotecario : public Persona {
private:
	string sCargo;
public:
	Bibliotecario() {
		this->sCargo = 0.0;
	}	
	//constructor por parametros
	Bibliotecario(int id, string nombre, string apellido, string email, string cargo): Persona(id, nombre, apellido, email){
		this->sCargo=cargo;
	}
	string get_Cargo() const{ return sCargo; }
	void set_Cargo(const string& cargo) { sCargo = cargo; }
};
// Definición de la clase GestorLibros
class GestorLibros {
private:
	Libro libros[TAMANO];
	int tamanoActual;
public:
	GestorLibros() : tamanoActual(0) {}
	bool tituloRepetido(const string& titulo, int cantidad) const {
		for (int i = 0; i < cantidad; i++) {
			if (titulo == libros[i].get_Titulo()) {
				return true; // Si el titulo esta repetido
			}
		}
		return false; // Si el titulo no esta repetido
	}
	void llenar() {
		string listaTitulo[] = {"el viejo y el mar", "rebelión en la granja", "la isla del tesoro", "el corazon de la luz", "aprende programacion", "inteligencia artificial", "ciberseguridad esencial", "javaScript moderno", "arduino proyectos"};
		string listaAutor[] = {"Alejandro Gutiérrez", "Emiliano Dominguez", "Francisco Martínez", "Antonieta Hernández", "Cristobal Pausinis ", "Valentina Fernández", "Magdalena Carrasco", "Antonella Rodríguez ", "Daniel Esteban", "Maribel Torrez"};
		string listaEstado[] = {"Prestado", "Reservado", "Disponible"};
		string listaEditorial[] = {"Editorial Santillana", "Acantilado Editorial", "Editorial Alfaguara", "Editorial Planeta", "Anagrama Editorial", "Ediciones Sir", "Alianza Editorial", "Ediciones Siglo XXI"};
		srand(time(nullptr)); // Inicializar la semilla del generador de números aleatorios
		tamanoActual = 0; // Reiniciar el contador para llenar desde el principio
		for (int i = 0; i < TAMANO; i++) {
			string tituloAleatorio;
			do {
				int indiceTitulo = rand() % 9; //generacion de numero randomico de 0 a 9
				tituloAleatorio = listaTitulo[indiceTitulo];
			} while (tituloRepetido(tituloAleatorio, tamanoActual)); // Verificar si el titulo esta repetido
			int isbnAleatorio = i + 1;
			int indiceAutor = rand() % 10;
			int indiceEstado = rand() % 3;
			int indiceEditorial= rand()% 8; 
			int publicacionAleatoria = rand() % 25 + 1980; // Años entre 1980 y 2024
			int paginasAleatorias = rand() % 500 + 100; // Paginas entre 100 y 599
			string AutorAleatorio = listaAutor[indiceAutor];
			string EditorialAleatorio = listaEditorial[indiceEditorial];
			string EstadoAleatorio= listaEstado[indiceEstado];
			libros[i] = Libro(isbnAleatorio, tituloAleatorio,AutorAleatorio , publicacionAleatoria,EditorialAleatorio , EstadoAleatorio, paginasAleatorias);
			tamanoActual++;
		}
	}
	void mostrar() const {
    if (tamanoActual == 0) { // Verifica si no hay libros llenados
        cout << "Datos no llenados." << endl;
        return;
    }
    // Imprimir datos de los libros
    cout << setw(2) << right << "ISBN" << setw(15) << "Titulo" << setw(30) << "Autor" << setw(15) << "Anio" << setw(15) << "Editorial" << setw(25) << "Estado" << setw(25) << "Paginas" << endl;
    for (int i = 0; i < tamanoActual; i++) {
        cout << left << setw(5) << libros[i].get_ISBN() << setw(30) << libros[i].get_Titulo() << setw(25) << libros[i].get_Autor() << setw(10) << libros[i].get_Publicacion() << setw(30) << libros[i].get_Editorial() << setw(25) << libros[i].get_Estado() << setw(15) << libros[i].get_Paginas() << endl;
    }
}
	// Función para mostrar los datos de los libros en forma de bloque
	void mostrar(string bloque) const {
		if (tamanoActual == 0) { // Verifica si no hay libros llenados
			cout << "Datos no llenados." << endl; // Mostrar mensaje si no hay datos
			return;
		}
		cout << "Datos de libros en bloques: " << endl;
		for (int i = 0; i < tamanoActual; i++) {
			
			cout << "ISBN: " << libros[i].get_ISBN() << endl;
			cout << "Titulo: " << libros[i].get_Titulo() << endl; 
			cout << "Autor: " << libros[i].get_Autor() << endl;
			cout << "Anio: " << libros[i].get_Publicacion() << endl; 
			cout << "Editorial: " << libros[i].get_Editorial() << endl; 
			cout << "Estado: " << libros[i].get_Estado() << endl;
			cout << "Paginas: " << libros[i].get_Paginas()  << endl;
			cout<<"----------------------------------------------------------------------------------------------"<<endl;
		}
		cout << bloque << endl;
	}
	// Funcion para convertir una cadena a minusculas
	string convertir(const string& cadena) const {
		string resultado = cadena;
		for (char& c : resultado) {
			c = tolower(c);
		}
		return resultado;
	}
	// Funcion recursiva para buscar libros por titulo
	void buscar(int indice, int fin, const string& busqueda) const {
		if (indice < fin) { //condicion base
			// Convertir a minúsculas los atributos del libro y la cadena de búsqueda
			string tituloMinuscula = convertir(libros[indice].get_Titulo());
			string autorMinuscula = convertir(libros[indice].get_Autor());
			string editorialMinuscula = convertir(libros[indice].get_Editorial());
			string estadoMiniscula = convertir(libros[indice].get_Estado());
			string busquedaMinuscula = convertir(busqueda);
			if (indice == 0) { //mostrar el encabezado de la tabla
				cout << setw(2) << right << "ISBN" << setw(10) << "Titulo" << setw(24) << "Autor" << setw(24) << "Anio" << setw(15) << "Editorial" << setw(20) << "Estado" << setw(20) << "Paginas" << endl;
			}
			// Verificar si la busqueda coincide con el titulo, autor, genero o precio
			if (tituloMinuscula.find(busquedaMinuscula) != string::npos || autorMinuscula.find(busquedaMinuscula) != string::npos || editorialMinuscula.find(busquedaMinuscula) != string::npos || estadoMiniscula.find(busquedaMinuscula) != string::npos) {
				//imprime los datos de los libros que coincidan con la busqueda
				cout << left << setw(8) << libros[indice].get_ISBN() << setw(25) << libros[indice].get_Titulo() << setw(25) << libros[indice].get_Autor() << setw(11) << libros[indice].get_Publicacion() << setw(23) << libros[indice].get_Editorial() << setw(20) << libros[indice].get_Estado() << setw(20) << libros[indice].get_Paginas() << endl;
				
			}
			buscar(indice + 1, fin, busqueda); // Llamada recursiva con el siguiente libro
		}
	}
};
// Definicion de la clase GestorUsuarios
class GestorUsuarios {
private:
	Usuario usuarios[TAMANO];
	int tamanoActual;
public:
	GestorUsuarios() : tamanoActual(0) {}
	void llenar() { // Funcion para llenar el arreglo de usuarios con datos aleatorios
		string listaNombres[] = {"Juan", "Maria", "Luis", "Ana", "Carlos", "Laura", "Pedro", "Elena", "Javier", "Sofia"};
		string listaApellidos[] = {"Peralta", "Osinaga", "Rodriguez", "Escobar", "Lopez", "Gonzalez", "Mendoza", "Roca", "Garcia", "Torres"};
		srand(time(nullptr)); // Inicializar la semilla del generador de números aleatorios
		tamanoActual = 0; // Reiniciar el contador para llenar desde el principio
		for (int i = 0; i < TAMANO; ++i) {
			int indiceNombre = rand() % 10; //generacion de numero randomico de 0 al 9
			int indiceApellido = rand() % 10; //generacion de numero randomico de 0 al 9
			int idAleatorio = i + 1;
			int edadAleatorio = (rand() % 13) + 18;
			string nombreAleatorio = listaNombres[indiceNombre];
			string apellidoAleatorio = listaApellidos[indiceApellido];
			string emailAleatorio = nombreAleatorio + apellidoAleatorio + "@gmail.com";
			usuarios[i] = Usuario(idAleatorio, nombreAleatorio, apellidoAleatorio, emailAleatorio, edadAleatorio);
			tamanoActual++; // Incrementar el contador de usuarios
		}
	}
	void mostrar() const {  // Funcion para mostrar los datos de los usuarios en forma de tabla
		if (tamanoActual == 0) { // Verificar si no hay usuarios para mostrar
			cout << "Datos no llenados." << endl; // Mostrar mensaje si no hay datos
			return;
		}
		cout << setw(5) << right << "User ID" << setw(14) << "Nombre" << setw(17) << "Apellido" << setw(12) << "Email" << setw(28) << "Edad" << endl;
		for (int i = 0; i < tamanoActual; ++i) { //imprimir datos de los usuarios
			cout << left << setw(15) << usuarios[i].get_ID() << setw(15) << usuarios[i].get_Nombre() << setw(15) << usuarios[i].get_Apellido() << setw(30) << usuarios[i].get_Email() << setw(35) << usuarios[i].get_Edad() << endl;
		}
	}
	// Función para mostrar los datos de los usuarios en forma de bloques
	void mostrar(string bloque) const {
		if (tamanoActual == 0) { // Verificar si no hay usuarios para mostrar
			cout << "Datos no llenados." << endl; // Mostrar mensaje si no hay datos
			return;
		}
		cout << "Datos de Usuarios en Bloques:" << endl;
		for (int i = 0; i < tamanoActual; ++i) { //imprimir datos de los usuarios
			//cout << "Usuario " << i+1 << ":" << endl;
			cout << "User ID: " << usuarios[i].get_ID() << endl;
			cout << "Nombre: " << usuarios[i].get_Nombre() << endl;
			cout << "Apellido: " << usuarios[i].get_Apellido() << endl;
			cout << "Email: " << usuarios[i].get_Email() << endl;
			cout << "Edad: " << usuarios[i].get_Edad() << endl;
			cout<<"----------------------------------------------------------------------------------------------"<<endl;
		}
	}
	// Funcion para convertir una cadena a minusculas
	string convertir(const string& cadena) const { 
		string resultado = cadena;
		for (char& c : resultado) {
			c = tolower(c);
		}
		return resultado;
	}
	// Funcion recursiva para buscar usuarios por nombre, apellido o nombre completo
	void buscar(int inicio, int fin, const string& busqueda) const {
		if (inicio < fin) {  //condicion base
			// Convertir a minusculas los atributos del usuario y la cadena de busqueda
			string nombreMinuscula = convertir(usuarios[inicio].get_Nombre()); //convertir las cadenas a minusculas
			string apellidoMinuscula = convertir(usuarios[inicio].get_Apellido());
			string emailMinuscula = convertir(usuarios[inicio].get_Email());
			string edadStr = to_string(usuarios[inicio].get_Edad());
			string busquedaMinuscula = convertir(busqueda);
			if (inicio == 0) { //mostrar el encabezado de la tabla
				cout << setw(5) << right << "User ID" << setw(14) << "Nombre" << setw(17) << "Apellido" << setw(12) << "Email" << setw(32) << "Edad" << endl;
			}
			// Verifica si la busqueda coincide con el nombre, apellido o nombre completo
			if (nombreMinuscula.find(busquedaMinuscula) != string::npos || apellidoMinuscula.find(busquedaMinuscula) != string::npos || (nombreMinuscula + " " + apellidoMinuscula).find(busquedaMinuscula) != string::npos || emailMinuscula.find(busquedaMinuscula) != string::npos || edadStr.find(busquedaMinuscula) != string::npos){
				// Imprimir los datos del usuario que coincidan con la busqueda
				cout << left << setw(15) << usuarios[inicio].get_ID() << setw(15) << usuarios[inicio].get_Nombre() << setw(15) << usuarios[inicio].get_Apellido() << setw(30) << usuarios[inicio].get_Email() << setw(15) << usuarios[inicio].get_Edad() << endl;
			}
			buscar(inicio + 1, fin, busqueda); //llamada recursiva con el siguiente usuario
		}
	}
};
// Definicion de la clase GestorBibliotecarios
class GestorBibliotecarios {
private:
	Bibliotecario bibliotecarios[TAMANO];
	int tamanoActual;
public:
	GestorBibliotecarios() : tamanoActual(0) {}
	void llenar() { // Función para llenar el arreglo de bibliotecarios con datos aleatorios
		string listaNombres[] = {"Santiago", "Belen", "Luz", "Isabel", "Fabian", "Carla", "Sergio", "Gustavo", "Mario", "Melanie"};
		string listaApellidos[] = {"Leon", "Roca", "Justiniano", "Soliz", "Rivero", "Torrico", "Cuellar", "Tantani", "Rivas", "Roque"};
		string listaCargos[] = {"Bibliotecario Infantil", "Asistente de Referencia", "Auxiliar de Biblioteca", "Encargado de Adquisiciones", "Coordinador de Programas Educativos"};
		srand(time(nullptr)); // Inicializar la semilla del generador de números aleatorios
		tamanoActual = 0; // Reiniciar el contador para llenar desde el principio
		for (int i = 0; i < TAMANO; ++i) {
			int indiceNombre = rand() % 10; //generar numero randomico del 0 al 9
			int indiceApellido = rand() % 10;
			int idAleatorio = i + 1;
			int indiceCargo= rand() % 5 ; // salario entre 1500 y 3000
			bibliotecarios[i] = Bibliotecario(idAleatorio, listaNombres[indiceNombre], listaApellidos[indiceApellido], listaNombres[indiceNombre] + listaApellidos[indiceApellido] + "@gmail.com", listaCargos[indiceCargo]);
			tamanoActual++;
		}
	}
	void mostrar() const {  // Funcion para mostrar los datos de los bibliotecarios en forma de tabla
		if (tamanoActual == 0) { // Verificar si no hay bibliotecarios para mostrar
			cout << "Datos no llenados." << endl; // Mostrar mensaje si no hay datos
			return;
		}
		//imprimir datos de los bibliotecarios
		cout << setw(5) << right << "Employee ID" << setw(10) << "Nombre" << setw(17) << "Apellido" << setw(12) << "Email" << setw(32) << "Cargo" << endl;
		for (int i = 0; i < tamanoActual; ++i) {
			cout << left << setw(15) << bibliotecarios[i].get_ID() << setw(15) << bibliotecarios[i].get_Nombre() << setw(15) << bibliotecarios[i].get_Apellido() << setw(30) << bibliotecarios[i].get_Email() << bibliotecarios[i].get_Cargo() << endl;
		}
	}
	// Función para mostrar los datos de los bibliotecarios en forma de bloques
	void mostrar(string bloque) const {
		if (tamanoActual == 0) {  // Verificar si no hay bibliotecarios para mostrar
			cout << "Datos no llenados." << endl; // Mostrar mensaje si no hay datos
			return;
		}
		cout << "Datos de Bibliotecarios en Bloques:" << endl;
		for (int i = 0; i < tamanoActual; ++i) { //imprimir datos de los bibliotecarios
			//cout << "Bibliotecario " << i+1 << ":" << endl;
			cout << "Employee ID: " << bibliotecarios[i].get_ID() << endl;
			cout << "Nombre: " << bibliotecarios[i].get_Nombre() << endl;
			cout << "Apellido: " << bibliotecarios[i].get_Apellido() << endl;
			cout << "Email: " << bibliotecarios[i].get_Email() << endl;
			cout << "Cargo: " << bibliotecarios[i].get_Cargo() << endl;
			cout<<"----------------------------------------------------------------------------------------------"<<endl;
		}
	}
	string convertir(const string& cadena) const { // Funcion para convertir una cadena a minusculas
		string resultado = cadena;
		for (char& c : resultado) {
			c = tolower(c);
		}
		return resultado;
	}
	// Funcion recursiva para buscar bibliotecarios por nombre, apellido o nombre completo
	void buscar(int inicio, int fin, const string& busqueda) const {
		if (inicio < fin) { //condicion base
			// Convertir a minusculas los atributos del bibliotecario y la cadena de busqueda
			string nombreMinuscula = convertir(bibliotecarios[inicio].get_Nombre());
			string apellidoMinuscula = convertir(bibliotecarios[inicio].get_Apellido());
			string emailMinuscula = convertir(bibliotecarios[inicio].get_Email());
			string cargoMiniscula= convertir(bibliotecarios[inicio].get_Cargo());
			string busquedaMinuscula = convertir(busqueda);
			if (inicio == 0) { //mostrar el encabezado de la tabla
				cout << setw(5) << right << "Employee ID" << setw(10) << "Nombre" << setw(17) << "Apellido" << setw(12) << "Email" << setw(32) << "Cargo" << endl;
			}
			// Verifica si la busqueda coincide con el nombre, apellido o nombre completo
			if (nombreMinuscula.find(busquedaMinuscula) != string::npos || apellidoMinuscula.find(busquedaMinuscula) != string::npos || (nombreMinuscula + " " + apellidoMinuscula).find(busquedaMinuscula) != string::npos || emailMinuscula.find(busquedaMinuscula) != string::npos || cargoMiniscula.find(busquedaMinuscula) != string::npos) {
				// Imprimir los datos del bibliotecario que coincidan con la busqueda
				cout << left << setw(15) << bibliotecarios[inicio].get_ID() << setw(15) << bibliotecarios[inicio].get_Nombre() << setw(15) << bibliotecarios[inicio].get_Apellido() << setw(30) << bibliotecarios[inicio].get_Email() << bibliotecarios[inicio].get_Cargo()<< endl;
			}
			buscar(inicio + 1, fin, busqueda); //llamada recursiva con el siguiente bibliotecario
		}
	}
};
// Menu para mostrar los listados
void menuListados(GestorLibros& gestorL, GestorUsuarios& gestorU, GestorBibliotecarios& gestorB) {
	int opcionListados;
	do {
		cout << "\nSubmenu de Listados:" << endl;
		cout << "1. Listado de Libros" << endl;
		cout << "2. Listado de Usuarios" << endl;
		cout << "3. Listado de Bibliotecarios" << endl;
		cout << "0. Volver al Menu Principal" << endl;
		cout << "Ingrese la opcion: ";
		cin >> opcionListados;
		switch (opcionListados) {
		case 1:
		{
			char respuesta;
			cout << "Desea ver los datos en forma de columna? (s/n): ";
			cin >> respuesta;
			if (respuesta == 's' || respuesta == 'S'){
				gestorL.mostrar();
			} else {
			    // Si la respuesta es negativa o cualquier otra cosa, llamar al método mostrar("BLOQUE") de gestorU
                // Esto indica que se desea mostrar los datos de alguna manera específica, en este caso, usando la palabra "BLOQUE"
				gestorL.mostrar("BLOQUE");
			}
		}  
		break;
	    case 2:
        {
            char respuesta;
            // Solicitar al usuario si desea ver los datos en forma de columna
            cout << "Desea ver los datos en forma de columna? (s/n): ";
            cin >> respuesta;
        
            // Evaluar la respuesta del usuario
            if (respuesta == 's' || respuesta == 'S') {
                // Si la respuesta es afirmativa ('s' o 'S'), llamar al método mostrar() de gestorU
                gestorU.mostrar();
            } else {
                // Si la respuesta es negativa o cualquier otra cosa, llamar al método mostrar("BLOQUE") de gestorU
                // Esto indica que se desea mostrar los datos de alguna manera específica, en este caso, usando la palabra "BLOQUE"
                gestorU.mostrar("BLOQUE");
            }
        }
        break;

		case 3:
		{
			char respuesta;
			cout << "Desea ver los datos en forma de columna? (s/n): ";
			cin >> respuesta;
			if (respuesta == 's' || respuesta == 'S') {
				gestorB.mostrar();
			} else {
				gestorB.mostrar("BLOQUE");
			}
		}
		break;
		case 0:
			cout << "Volviendo al Menu Principal..." << endl;
			break;
		default:
			cout << "Opcion invalida. Intente de nuevo." << endl;
		}
	} while (opcionListados != 0);
}
// Menu para realizar busquedas
void menuBusqueda(GestorLibros& gestorL, GestorUsuarios& gestorU, GestorBibliotecarios& gestorB) {
	int opcionBusqueda;
	do {
		cout << "\nSubmenu de Busqueda:" << endl;
		cout << "1. Busqueda de Libro" << endl;
		cout << "2. Busqueda de Usuario" << endl;
		cout << "3. Busqueda de Bibliotecario" << endl;
		cout << "0. Volver al Menu Principal" << endl;
		cout << "Ingrese la opcion: ";
		cin >> opcionBusqueda;
		switch (opcionBusqueda) {
		case 1:
		{
			string sBusquedaL;
			cout << "Ingrese el titulo del libro que desea buscar: ";
			cin.ignore(); // Limpiar el buffer de entrada
			getline(cin, sBusquedaL); // Leer la cadena de búsqueda
			cout << "\nResultados de la busqueda:" << endl;
			gestorL.buscar(0, TAMANO, sBusquedaL); // Realizar la busqueda de libros
		}
		break;
		case 2:
		{
			string sBusquedaU;
			cout << "Ingrese el nombre, apellido o nombre completo: ";
			cin.ignore(); // Limpiar el buffer de entrada
			getline(cin, sBusquedaU); // Leer la cadena de búsqueda
			cout << "\nResultados de la busqueda:" << endl;
			gestorU.buscar(0, TAMANO, sBusquedaU); // Realizar la busqueda de usuarios
		}
		break;
		case 3:
		{
			string sBusquedaB;
			cout << "Ingrese el nombre, apellido o nombre completo: ";
			cin.ignore(); // Limpiar el buffer de entrada
			getline(cin, sBusquedaB); // Leer la cadena de búsqueda
			cout << "\nResultados de la busqueda:" << endl;
			gestorB.buscar(0, TAMANO, sBusquedaB); // Realizar la busqueda de usuarios
		}
		break;
		case 0:
			cout << "Volviendo al Menu Principal..." << endl;
			break;
		default:
			cout << "Opcion invalida. Intente de nuevo." << endl;
		}
	} while (opcionBusqueda != 0);
}
// Menu principal
void menuPrincipal(GestorLibros& gestorL, GestorUsuarios& gestorU, GestorBibliotecarios& gestorB) {
	int opcionPrincipal;
	do {
		cout << "\nMenu Principal:" << endl;
		cout << "1. Llenar Datos" << endl;
		cout << "2. Listados" << endl;
		cout << "3. Busqueda" << endl;
		cout << "0. Salir" << endl;
		cout << "Ingrese la opcion: ";
		cin >> opcionPrincipal;
		cin.ignore(); //Limpiar el buffer de entrada
		switch (opcionPrincipal) {
		case 1:   // Llenar datos de libros, usuarios y bibliotecarios
			gestorL.llenar();
			gestorU.llenar();
			gestorB.llenar();
			cout << "Datos llenados exitosamente." << endl;
			break;
		case 2:
			menuListados(gestorL, gestorU, gestorB);
			break;
		case 3:
			menuBusqueda(gestorL, gestorU, gestorB);
			break;
		case 0:
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opcion invalida. Intente de nuevo." << endl;
		}
	} while (opcionPrincipal != 0);
}
int main() {
	srand(time(nullptr));
	// Crear instancias de los gestores de libros, usuarios y bibliotecarios
	GestorLibros gestorL;
	GestorUsuarios gestorU;
	GestorBibliotecarios gestorB;
	// Llamar a la función del menú principal, pasando los gestores como argumentos
	menuPrincipal(gestorL, gestorU, gestorB);
	return 0;
}
