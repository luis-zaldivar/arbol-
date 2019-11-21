#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo* der;
	Nodo* izq;
	
};
Nodo *crearNodo(int);
void agregar(Nodo *&,int );
void mostrar(Nodo *, int);
bool busqueda(Nodo *, int);
void orden(Nodo *);
void preOrden(Nodo *);

Nodo *arbol=NULL;

int main(){
	int dato, opcion, contador=0;
	
	do{
		cout<<"\t ...:::M E N Ú::..."<<endl;
		cout<<"1.- Agregar un nuevo nodo"<<endl;
		cout<<"2.- Mostrar el arbol completo"<<endl;
		cout<<"3.- Buscar un elemento en el arbol"<<endl;
		cout<<"4.- Recorrer el arbol en Orden"<<endl;
		cout<<"5.- Recorrer el arbol en posOrden"<<endl;
		cout<<"6.- Salir"<<endl;
		cout<<"¿Cual opcion deseas? ";
		cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"Digite un numero que desee: ";
				cin>>dato;
				agregar(arbol,dato);
				cout<<"\n";
				system("pause");
				break;
			case 2:
				cout<<"\nMostrando el arbol competo:\n";
				mostrar(arbol, contador);
				cout<<"\n";
				system("pause");
				break;
			case 3:
				cout<<"Digite el numero a buscar: ";
				cin>>dato;
				if(busqueda(arbol,dato)==true){
					cout<<"Elemento "<<dato<<" encontrado";
				}
				else{
					cout<<"No enontrado";
				}
				cout<<"\n";
				system("pause");
				break;
			case 4:
				cout<<"Recorrido en Orden: "<<endl;
				orden(arbol);
				cout<<"\n\n";
				system("pause");
			case 5:
				cout<<"Recorrido en preOrden: "<<endl;
				preOrden(arbol);
				cout<<"\n\n";
				system("pause");
		}
		system("cls");
		
	}while(opcion != 6);
	
	getch();
	return 0;
}

Nodo *crearNodo(int n){
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato= n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq =NULL;
	
	return nuevo_nodo;
}
void agregar(Nodo *&arbol,int n){
	if(arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(n);
		arbol = nuevo_nodo;
	}
	else{
		int valorRaiz = arbol->dato;
		if(n < valorRaiz){
			agregar(arbol->izq, n);
		}
		else{
			agregar(arbol->der, n);
		}
	}
}

void mostrar(Nodo *arbol, int cont){
	if(arbol == NULL){
		return;
	}
	else{
		mostrar(arbol->der,cont +1);
		for(int i=0; i<cont; i++){
			cout<<" ";
		}
		cout<<arbol->dato<<endl;
		mostrar(arbol->izq, cont+1);
	}
}

bool busqueda(Nodo *arbol, int n){
	if(arbol == NULL){
		return false;
	}
	else if(arbol->dato == n){
		return true;
	}
	else if(n< arbol->dato){
		return busqueda(arbol->izq, n);
	}
	else{
		return busqueda(arbol->der, n);
	}
}

void preOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		cout<<arbol->dato<<" ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void orden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		orden(arbol->izq);
		cout<<arbol->dato<<" ";
		orden(arbol->der);
		
	}
}

