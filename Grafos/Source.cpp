#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#define TAM 3

using namespace std;

class Nodo
{
private:
	char valor[20];
	Nodo *hijos[TAM];
public:
	Nodo(char v[20]);
	friend class Grafo;
};

class Grafo
{
private:
	Nodo *inicio;
	Nodo *referencias[15];
	int numNodos;
	int conRef;
public:
	Grafo();
	//~Grafo();
	void menu();
	bool vacio();
	void insertar();
	void destinos();
	Nodo *buscar(char p[15]);
	void mostrar(Nodo *pais);
	//Nodo *buscarPadre(char nombre[20]);
	//void calcularNiveles();
	//void eliminar();
	//void mostrar();
};
Nodo::Nodo(char v[20])
{
	strcpy_s(valor, v);
	for (int i = 0; i = TAM; i++)
	{
		hijos[i] = NULL;
	}
}

Grafo::Grafo()
{
	numNodos = 0;
	conRef = 0;
	inicio = NULL;
}

void Grafo::menu()
{
	int opc = 0;
	while (opc!=4)
	{
		system("cls");
		cout << "*****AEROLINAS TDA´s*****" << endl << endl;
		cout << "1. Insertar pais" << endl;
		cout << "2. Definir vuelos" << endl;
		cout << "3. Mostrar vuelos dispoibles" << endl;
		cout << "4. Salir" << endl << endl << endl;
		cout << "Eligir la opcion: ";
		cin >> opc;

		switch (opc)
		{
		case 1:
			insertar();
			break;
		case 2:
			int aux;
			aux = vacio();
			if (aux == 1)
				destinos();
			else
				cout << endl << "DEBES INSERTAR PRIMERO LOS PAISES" << endl;
			_getch();
			break;
		case 3:
			system("cls");
			char pais[15];
			Nodo *p;
			cout << "Teclea el pais del que deseas saber los destinos: ";
			cin >> pais;
			p = buscar(pais);
			if (p != NULL)
				mostrar(p);
			else
			{
				cout << "PAIS NO ENCONTRADO" << endl;
				_getch();
			}
			break;
		case 4:
			break;
		default:
			cout << endl << "Opcion no valida";
			break;
		}
	}
}
bool Grafo::vacio()
{
	if (inicio != NULL)
		return 1;
	else
		return 0;
}
void Grafo::insertar()
{
	system("cls");
	char pais[15];
	int numPaises = 0;
	cout << "¿Cuantos paises vas a insertar?: ";
	cin >> numPaises;
	numPaises += numPaises;
	for (int i = 0; i < numPaises;i++)
	{
		cout <<endl<< "Teclea el nombre del pais "<<(i+1)<<":";
		cin >>pais ;
		Nodo *nuevo = new Nodo(pais);
		referencias[conRef] = nuevo;
		conRef++;
		inicio = nuevo;
	}
}

void Grafo::destinos()
{
	system("cls");
	Nodo *actual, *encontrado;
	int numDestinos;
	char pais[15];
	char destino[15];
	cout << "Teclea el pais al que desea buscar ";
	cin >> pais;
	actual = buscar(pais);
	if (actual!=NULL)
	{
		cout << endl << "Teclea el numero de destinos: ";
		cin >> numDestinos;
		if (numDestinos > (numNodos - 1))
			cout << endl << "excede el numero de destinos permitidos" << endl;
		else
		{
			for (int i = 0; i < numDestinos; i++)
			{
				cout << endl << "teclea el destino" << (i + 1) << ": ";
				cin >> destino;
				encontrado = buscar(destino);
				if (encontrado != NULL)
					actual->hijos[i] = encontrado;
				else
				{
					cout << endl << "DESTINO NO ENCONTRADO" << endl;
					i--;
				}
			}
		}

	}
	else
	{
		cout << endl << "PAIS NO ENCONTRADO" << endl;
		_getch();
	}
}

Nodo *Grafo::buscar(char p[15])
{
	int iguales = 0;
	for (int i = 0; i < conRef; i++)
	{
		iguales = strcmp(p, referencias[i]->valor);
		if (iguales == 0)
		{
			return referencias[i];
			break;
		}
	}
	if (iguales != 0)
	{
		return NULL;
	}
}
void Grafo::mostrar(Nodo *pais)
{
	Nodo *hijo = pais->hijos[0];
	system("cls");
	cout << "DESTINOS DISPONIBLES DE " << pais->valor << ": " << endl << endl;
	for (int i = 0; i < numNodos - 1; i++)
	{
		hijo = pais->hijos[i];
		if (hijo != NULL)
			cout << (i + 1) << " .- " << hijo->valor << endl << endl;
	}
	_getch();
}

int main()
{
	int ciclo;
	Grafo obj;
	obj.menu();
}