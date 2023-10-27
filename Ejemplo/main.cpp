#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class LDE{
private:
    class Nodo{
    public:
        Nodo* previo;
        float dato;
        Nodo* siguiente;
        Nodo(void){
            previo = NULL;
            dato = 0;
            siguiente = NULL;
            //cout<<"Nodo construido..."<<endl;
        };
        Nodo(Nodo* p, float d, Nodo* s){
            previo = p;
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
    Nodo* busca(float d){
        Nodo* aux1;
        Nodo* aux2;
        aux1=primero;
        aux2=ultimo;
        while(aux1!=aux2 && aux1->siguiente!=aux2 &&
              d!=aux1->dato && d!=aux2->dato
              ){
            aux1=aux1->siguiente;
            aux2=aux2->previo;
        }
        if(d==aux1->dato)
            return aux1;
        else if(d==aux2->dato)
            return aux2;
        else
            return NULL;
    };
public:
    LDE(void){
        primero=NULL;
        ultimo=NULL;
    };
    ~LDE(void){
        liberaLista();
    };
    void insertaPrimero(float d){
        if(estaVacia()){
            primero = new Nodo(NULL,d,NULL);
            ultimo = primero;
        }
        else{
            primero->previo = new Nodo(NULL,d,primero);
            primero = primero->previo;
        }
    };
    void insertaUltimo(float d){
        if(estaVacia()){
            ultimo = new Nodo(NULL,d,NULL);
            primero = ultimo;
        }
        else{
            ultimo->siguiente = new Nodo(ultimo,d,NULL);
            ultimo = ultimo->siguiente;
        }
    };
    void insertaDato(float d){
        Nodo* aux1;
        Nodo* aux2;

        if(estaVacia() || d<=primero->dato)
            insertaPrimero(d);
        else if(d>=ultimo->dato)
            insertaUltimo(d);
        else{
            aux1=primero;
            aux2=ultimo;
            while(aux1!=aux2 && aux1->siguiente!=aux2 &&
                  d>aux1->dato && d<aux2->dato
                  ){
                aux1=aux1->siguiente;
                aux2=aux2->previo;
            }
            if(d<=aux1->dato){
                aux2 = aux1->previo;
                aux2->siguiente = new Nodo(aux2,d,aux1);
                aux1->previo = aux2->siguiente;
            }
            else if(d>=aux2->dato){
                aux1 = aux2->siguiente;
                aux2->siguiente = new Nodo(aux2,d,aux1);
                aux1->previo = aux2->siguiente;
            }
            else{
                aux1->siguiente = new Nodo(aux1,d,aux2);
                aux2->previo = aux1->siguiente;

            }
        }
    };
    float eliminaPrimero(void){
        Nodo*aux;
        int d=-1;
        if(!estaVacia()){
            d = primero->dato;
            if(primero==ultimo){
                delete primero;
                primero=NULL;
                ultimo=NULL;
            }
            else{
                aux = primero;
                primero = primero->siguiente;
                delete aux;
                primero->previo = NULL;
            }
        }
        return d;
    };
    float eliminaUltimo(void){
        Nodo*aux;
        int d=-1;
        if(!estaVacia()){
            d = ultimo->dato;
            if(ultimo==primero){
                delete ultimo;
                ultimo=NULL;
                primero=NULL;
            }
            else{
                aux = ultimo;
                ultimo = ultimo->previo;
                delete aux;
                ultimo->siguiente = NULL;
            }
        }
        return d;
    };
    bool eliminaDato(float d){
        Nodo* aux1;
        Nodo* aux2;
        aux2 = busca(d);
        if(aux2==NULL)
            return false;
        else if(aux2==primero)
            eliminaPrimero();
        else if(aux2==ultimo)
            eliminaUltimo();
        else{
            aux1 = aux2->previo;
            aux1->siguiente = aux2->siguiente;
            aux1=aux2->siguiente;
            aux1->previo = aux2->previo;
            delete aux2;
        }
        return true;
    };
    bool buscaDato(float d){
        return busca(d)!=NULL;
    };
    void muestraPrimeroAUltimo(void){
        Nodo* aux;
        aux=primero;
        while(aux!=NULL){
            cout<<aux->dato<<" ";
            aux=aux->siguiente;
        }
    };
    void muestraUltimoAPrimero(void){
        Nodo* aux;
        aux=ultimo;
        while(aux!=NULL){
            cout<<aux->dato<<" ";
            aux=aux->previo;
        }
    };
    bool estaVacia(void){
        return
            primero==NULL
            &&
            ultimo==NULL
        ;
    };
    void liberaLista(void){
        if(!estaVacia()){
            while(primero!=ultimo && primero->siguiente!=ultimo){
                cout<<eliminaPrimero()<<", ";
                cout<<eliminaUltimo()<<endl;
            }
            if(primero==ultimo){
                cout<<eliminaUltimo()<<endl;
            }
            else{
                cout<<eliminaPrimero()<<", ";
                cout<<eliminaUltimo()<<endl;
            }
        }
    };
    void generaListaOrdenada(LDE& L){
        Nodo* aux1;
        Nodo* aux2;
        L.liberaLista();
        if(!estaVacia()){
            aux1=primero;
            aux2=ultimo;
            while(aux1!=aux2 && aux1->siguiente!=aux2){
                L.insertaDato(aux1->dato);
                L.insertaDato(aux2->dato);
                aux1=aux1->siguiente;
                aux2=aux2->previo;
            }
            if(aux1==aux2){
                L.insertaDato(aux1->dato);
            }
            else{
                L.insertaDato(aux1->dato);
                L.insertaDato(aux2->dato);
            }
        }
    };
};

int main(void){
    srand(time(NULL));
    LDE L1, L2, L3;
    int i,d;

    for(i=0; i<20; i++){
        d = rand()%100;
        cout<<"Se inserta "<<d<<endl;
        L1.insertaPrimero(d);
        L2.insertaUltimo(d);
        L3.insertaDato(d);
        cout<<"L1: ";
        L1.muestraPrimeroAUltimo();
        cout<<endl;
        cout<<"L2: ";
        L2.muestraPrimeroAUltimo();
        cout<<endl;
        cout<<"L3: ";
        L3.muestraPrimeroAUltimo();
        cout<<endl<<endl;
    }
    system("pause");
    system("cls");

    cout<<"L1: ";
    L1.muestraPrimeroAUltimo();
    cout<<endl;
    cout<<"L2: ";
    L2.muestraPrimeroAUltimo();
    cout<<endl;
    cout<<"L3: ";
    L3.muestraPrimeroAUltimo();
    cout<<endl<<endl;

    system("pause");
    system("cls");
    return 0;
}
