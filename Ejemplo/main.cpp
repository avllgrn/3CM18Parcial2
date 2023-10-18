#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class LSE{
private:
    class Nodo{
    public:
        int dato;
        Nodo* siguiente;
        Nodo(void){
            dato = 0;
            siguiente = NULL;
            //cout<<"Nodo construido..."<<endl;
        };
        Nodo(int d, Nodo* s){
            dato = d;
            siguiente = s;
            //cout<<"Nodo construido..."<<endl;
        };
        ~Nodo(void){
            //cout<<"Nodo destruido..."<<endl;
        };
    };
    Nodo* primero;
    Nodo* ultimo;
public:
    LSE(void){
        primero = NULL;
        ultimo = NULL;
    };
    ~LSE(void){
        liberaLista();
    };
    void insertaDato(int d){
        if(estaVacia() || d <= primero->dato)
            insertaPrimero(d);
        else if(d >= ultimo->dato)
            insertaUltimo(d);
        else{
            Nodo* aux1;
            Nodo* aux2;
            aux1 = primero;
            aux2 = primero->siguiente;
            while(d >= aux2->dato){
                aux1 = aux1->siguiente;
                aux2 = aux2->siguiente;
            }
            aux1->siguiente = new Nodo(d,aux2);
        }
    };
    void insertaPrimero(int d){
        if(estaVacia()){
            primero = new Nodo(d,NULL);
            ultimo = primero;
        }
        else{
            primero = new Nodo(d,primero);
        }
    };
    void insertaUltimo(int d){
        if(estaVacia()){
            ultimo = new Nodo(d,NULL);
            primero = ultimo;
        }
        else{
            ultimo->siguiente = new Nodo(d,NULL);
            ultimo = ultimo->siguiente;
        }
    };
    bool eliminaDato(int d){
        if(estaVacia())
            return false;
        else if(d == primero->dato){
            eliminaPrimero();
            return true;
        }
        else if(d == ultimo->dato){
            eliminaUltimo();
            return true;
        }
        else{
            Nodo* aux1;
            Nodo* aux2;
            aux1 = primero;
            aux2 = primero->siguiente;
            while(aux2!=NULL && d!=aux2->dato){
                aux1 = aux1->siguiente;
                aux2 = aux2->siguiente;
            }
            if(aux2==NULL)
                return false;
            else{
                aux1->siguiente = aux2->siguiente;
                delete aux2;
                return true;
            }
        }
    };
    int eliminaPrimero(void){
        Nodo* aux;
        int d;

        if(!estaVacia()){
            d = primero->dato;
            if(primero == ultimo){
                delete primero;
                primero = NULL;
                ultimo = NULL;
            }
            else{
                aux = primero;
                primero = primero->siguiente;
                delete aux;
            }
        }
        return d;
    };
    int eliminaUltimo(void){
        Nodo* aux;
        int d;

        if(!estaVacia()){
            d = ultimo->dato;
            if(primero == ultimo){
                delete ultimo;
                ultimo = NULL;
                primero = NULL;
            }
            else{
                aux = primero;
                while(aux->siguiente != ultimo){
                    aux = aux->siguiente;
                }
                delete ultimo;
                ultimo = aux;
                ultimo->siguiente = NULL;
            }
        }
        return d;
    };
    bool buscaDato(int d){
        Nodo* aux;

        aux=primero;
        while(aux != NULL){
            if(aux->dato == d)
            return true;
            aux = aux->siguiente;
        }
        return false;
    };
    void muestraPrimeroAUltimo(void){
        Nodo* aux;

        aux=primero;
        while(aux != NULL){
            cout<<aux->dato;
            if(aux->siguiente!=NULL)
                cout<<" -> ";
            aux = aux->siguiente;
        }
    };
    void muestraUltimoAPrimero(void){
        Nodo*aux1;
        Nodo*aux2;
        if(!estaVacia()){
            aux2 = ultimo;
            cout<<aux2->dato;
            while(aux2!=primero){
                cout<<" <- ";
                aux1=primero;
                while(aux1->siguiente != aux2){
                    aux1 = aux1->siguiente;
                }
                aux2 = aux1;
                cout<<aux2->dato;
            }
        }
    };
    void generaListaOrdenada(LSE& L){
        Nodo*aux;
        L.liberaLista();//Asegurarse de que no tenga datos previos, posiblemente desordenados

        aux = primero;
        while(aux!=NULL){
            L.insertaDato(aux->dato);
            aux = aux->siguiente;
        }
    };
    bool estaVacia(void){
        return
            primero == NULL
            &&
            ultimo == NULL
        ;
    };
    void liberaLista(void){
        while(!estaVacia()){
            cout<<eliminaUltimo()<<endl;
        }
    };
};

int main(void){
    srand(time(NULL));
    LSE L1,L2,L3;
    int i,d;

    for(i=0; i<15; i++){
        d = rand()%100;
        cout<<"Se inserta "<<d<<endl;
        L1.insertaPrimero(d);   //Se inserta siempre por el inicio
        L2.insertaUltimo(d);    //Se inserta siempre por el final
        L3.insertaDato(d);      //Se inserta ordenadamente
        cout<<"L1: ";
        L1.muestraPrimeroAUltimo();cout<<endl;
        cout<<"L2: ";
        L2.muestraPrimeroAUltimo();cout<<endl;
        cout<<"L3: ";
        L3.muestraPrimeroAUltimo();cout<<endl<<endl;
    }
    system("pause");
    system("cls");

    cout<<"L1: ";
    L1.muestraPrimeroAUltimo();cout<<endl;
    cout<<"L2: ";
    L2.muestraPrimeroAUltimo();cout<<endl;
    cout<<"L3: ";
    L3.muestraPrimeroAUltimo();cout<<endl<<endl;

    cout<<"Se elimina el primero."<<endl;
    cout<<L1.eliminaPrimero()<<endl;
    cout<<L2.eliminaPrimero()<<endl;
    cout<<L3.eliminaPrimero()<<endl<<endl;

    cout<<"L1: ";
    L1.muestraPrimeroAUltimo();cout<<endl;
    cout<<"L2: ";
    L2.muestraPrimeroAUltimo();cout<<endl;
    cout<<"L3: ";
    L3.muestraPrimeroAUltimo();cout<<endl<<endl;
    system("pause");
    system("cls");

    cout<<"L1: ";
    L1.muestraPrimeroAUltimo();cout<<endl;
    cout<<"L2: ";
    L2.muestraPrimeroAUltimo();cout<<endl;
    cout<<"L3: ";
    L3.muestraPrimeroAUltimo();cout<<endl<<endl;

    cout<<"Se elimina el ultimo."<<endl;
    cout<<L1.eliminaUltimo()<<endl;
    cout<<L2.eliminaUltimo()<<endl;
    cout<<L3.eliminaUltimo()<<endl<<endl;

    cout<<"L1: ";
    L1.muestraPrimeroAUltimo();cout<<endl;
    cout<<"L2: ";
    L2.muestraPrimeroAUltimo();cout<<endl;
    cout<<"L3: ";
    L3.muestraPrimeroAUltimo();cout<<endl<<endl;
    system("pause");
    system("cls");

    cout<<"L1: ";
    L1.muestraPrimeroAUltimo();cout<<endl;
    cout<<"L2: ";
    L2.muestraPrimeroAUltimo();cout<<endl;
    cout<<"L3: ";
    L3.muestraPrimeroAUltimo();cout<<endl<<endl;
    cout<<"Ingresa un numero que NO se encuentre en las listas ";
    cin>>d;
    cout<<endl;

    if(L1.eliminaDato(d))
        cout<<"FUE eliminado"<<endl;
    else
        cout<<"NO fue eliminado"<<endl;

    if(L2.eliminaDato(d))
        cout<<"FUE eliminado"<<endl;
    else
        cout<<"NO fue eliminado"<<endl;

    if(L3.eliminaDato(d))
        cout<<"FUE eliminado"<<endl;
    else
        cout<<"NO fue eliminado"<<endl;

    cout<<endl;
    cout<<"L1: ";
    L1.muestraPrimeroAUltimo();cout<<endl;
    cout<<"L2: ";
    L2.muestraPrimeroAUltimo();cout<<endl;
    cout<<"L3: ";
    L3.muestraPrimeroAUltimo();cout<<endl<<endl;
    system("pause");
    system("cls");

    cout<<"L1: ";
    L1.muestraPrimeroAUltimo();cout<<endl;
    cout<<"L2: ";
    L2.muestraPrimeroAUltimo();cout<<endl;
    cout<<"L3: ";
    L3.muestraPrimeroAUltimo();cout<<endl<<endl;
    cout<<"Ingresa un numero que SE ENCUENTRE en las listas (que no sea ni el primero ni el ultimo) ";
    cin>>d;
    cout<<endl;

    if(L1.eliminaDato(d))
        cout<<"FUE eliminado"<<endl;
    else
        cout<<"NO fue eliminado"<<endl;

    if(L2.eliminaDato(d))
        cout<<"FUE eliminado"<<endl;
    else
        cout<<"NO fue eliminado"<<endl;

    if(L3.eliminaDato(d))
        cout<<"FUE eliminado"<<endl;
    else
        cout<<"NO fue eliminado"<<endl;

    cout<<endl;
    cout<<"L1: ";
    L1.muestraPrimeroAUltimo();cout<<endl;
    cout<<"L2: ";
    L2.muestraPrimeroAUltimo();cout<<endl;
    cout<<"L3: ";
    L3.muestraPrimeroAUltimo();cout<<endl<<endl;
    system("pause");

    L3.liberaLista();
    system("cls");
    cout<<"L1: ";
    L1.muestraPrimeroAUltimo();cout<<endl;
    cout<<"L3: ";
    L3.muestraPrimeroAUltimo();cout<<endl<<endl;

    L1.generaListaOrdenada(L3);
    cout<<"Se genera L3 ordenadamente, con los datos desordenados de L1."<<endl<<endl;

    cout<<"L3 de inicio a fin: ";
    L3.muestraPrimeroAUltimo();cout<<endl;
    cout<<"L3 de fin a inicio: ";
    L3.muestraUltimoAPrimero();cout<<endl<<endl;
    system("pause");
    system("cls");

    return 0;
}
