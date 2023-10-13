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
    };
    int eliminaPrimero(void){
        int d;
        if(!estaVacia()){
            d = primero->dato;
            if(primero==ultimo){
                delete primero;
                primero = NULL;
                ultimo = NULL;
            }
            else{
                Nodo* aux;
                aux = primero;
                primero = primero->siguiente;
                delete aux;
            }
        }
        return d;
    };
    int eliminaUltimo(void){
        int d;
        if(!estaVacia()){
            d = ultimo->dato;
            if(ultimo==primero){
                delete ultimo;
                ultimo = NULL;
                primero = NULL;
            }
            else{
                Nodo* aux;
                aux=primero;
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
        aux = primero;
        while(aux != NULL){
            if(aux->dato == d)
                return true;

            aux = aux->siguiente;
        }

        return false;
    };
    void muestraPrimeroAUltimo(void){
        Nodo* aux;
        aux = primero;
        while(aux != NULL){
            cout<<aux->dato;
            if(aux->siguiente != NULL)
                cout<<" -> ";

            aux = aux->siguiente;
        }
    };
    void muestraUltimoAPrimero(void){
    };
    LSE generaListaOrdenada(void){
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
            cout<<eliminaPrimero()<<endl;
        }
    };
    int cuentaNodos(void){
        int n=0;
        Nodo* aux;
        aux = primero;
        while(aux != NULL){
            n = n + 1;
            aux = aux->siguiente;
        }
        return n;
    };
    int sumaNodos(void){
        int s=0;
        Nodo* aux;
        aux = primero;
        while(aux != NULL){
             s = s + aux->dato;
            aux = aux->siguiente;
        }
        return s;
    };
    float promediaNodos(void){
        float promedio;
        float s=0;
        int n=0;
        Nodo* aux;
        aux = primero;
        while(aux != NULL){
            s = s + aux->dato;
            n = n+1;
            aux = aux->siguiente;
        }
        promedio = s/n;
        return promedio;
    };
};

int main(void){
    srand(time(NULL));
    LSE L;
    int i,n;

    n = (rand()%15) + 1;//Genera un numero aleatorio entre 1 y 15
    for(i=0; i<n; i++)
        L.insertaPrimero(rand()%100);//Inserta un valor aleatorio entre 0 y 100

    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    cout<<"Hay "<<L.cuentaNodos()<<" nodos."<<endl<<endl;
    cout<<"La suma es "<<L.sumaNodos()<<endl<<endl;
    cout<<"Promedio es "<<L.promediaNodos()<<endl<<endl;

    return 0;
}
