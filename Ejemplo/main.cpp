#include <iostream>
#include <stdlib.h>
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
};

int main(void){
    LSE L;

    L.insertaUltimo(17);
    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    L.insertaUltimo(29);
    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    L.insertaPrimero(25);
    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    L.insertaPrimero(33);
    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    L.insertaPrimero(55);
    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    L.insertaPrimero(38);
    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    L.insertaPrimero(12);
    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    L.insertaUltimo(127);
    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    L.insertaUltimo(94);
    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    L.insertaPrimero(17);
    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    L.insertaUltimo(57);
    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    L.insertaPrimero(18);
    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    L.insertaUltimo(70);
    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    L.insertaUltimo(-7);
    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    L.insertaUltimo(-9);
    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    system("pause");
    system("cls");

    int d;
    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    cout<<"Que dato buscas? ";cin>>d;

    if(L.buscaDato(d))
        cout<<"SI esta"<<endl<<endl;
    else
        cout<<"NO esta"<<endl<<endl;
    system("pause");
    system("cls");

    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    L.eliminaUltimo();
    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    L.eliminaUltimo();
    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    L.eliminaUltimo();
    L.muestraPrimeroAUltimo();cout<<endl<<endl;
    system("pause");
    system("cls");

    return 0;
}
