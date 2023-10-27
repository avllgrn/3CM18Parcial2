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
    int cuentaNodos(void){
        int n=0;
        return n;
    };
    float sumaNodos(void){
        float s=0;
        return s;
    };
    float promediaNodos(void){
        int n=0;
        float s=0,prom=0;
        return prom;
    };
    float buscaMenor(void){
        float menor=-1;
        return menor;
    };
    float buscaMayor(void){
        float mayor=-1;
        return mayor;
    };
    void concatenaListas(LDE& A, LDE& B){
    };
    void concatenaListasInvertidas(LDE& A, LDE& B){
    };
    void concatenaListasOrdenadamente(LDE& A, LDE& B){
    };
    float datoEnNodoEnMitad(void){
        return -1;
    };
    float datoEnNesimoNodo(int nesimo){
        return -1;
    };
};
int main(void){
    srand(time(NULL));
    LDE L,L2,L3,L4,L5;
    int i,n1,n2,nesimo,d;

    n1 = rand()%10;
    nesimo = rand()%20;
    cout<<"n1: "<<n1<<endl<<endl;
    for(i=0; i<n1; i++){
        L.insertaPrimero((rand()%100));
    }

    n2 = rand()%10;
    cout<<"n2: "<<n2<<endl<<endl;
    for(i=0; i<n2; i++){
        L2.insertaPrimero((rand()%100));
    }

    cout<<"L"<<endl;
    L.muestraPrimeroAUltimo();
    cout<<endl;
    L.muestraUltimoAPrimero();
    cout<<endl<<endl;
    cout<<"n1 = "<<L.cuentaNodos()<<endl
        <<"suma = "<<L.sumaNodos()<<endl
        <<"prom = "<<L.promediaNodos()<<endl
        <<"menor = "<<L.buscaMenor()<<endl
        <<"mayor = "<<L.buscaMayor()<<endl
        <<"dato en mitad = "<<L.datoEnNodoEnMitad()<<endl
        <<"dato en nodo #"<<nesimo<<" = "<<L.datoEnNesimoNodo(nesimo)<<endl<<endl;

    cout<<"L2"<<endl;
    L2.muestraPrimeroAUltimo();
    cout<<endl;
    L2.muestraUltimoAPrimero();
    cout<<endl<<endl;
    cout<<"n2 = "<<L2.cuentaNodos()<<endl
        <<"suma = "<<L2.sumaNodos()<<endl
        <<"prom = "<<L2.promediaNodos()<<endl
        <<"menor = "<<L2.buscaMenor()<<endl
        <<"mayor = "<<L2.buscaMayor()<<endl
        <<"dato en mitad = "<<L2.datoEnNodoEnMitad()<<endl
        <<"dato en nodo #"<<nesimo<<" = "<<L2.datoEnNesimoNodo(nesimo)<<endl<<endl;

    L3.concatenaListas(L,L2);
    cout<<"L"<<endl;
    L.muestraPrimeroAUltimo();
    cout<<endl;
    L.muestraUltimoAPrimero();
    cout<<endl<<endl;
    cout<<"L2"<<endl;
    L2.muestraPrimeroAUltimo();
    cout<<endl;
    L2.muestraUltimoAPrimero();
    cout<<endl<<endl;
    cout<<"L3"<<endl;
    L3.muestraPrimeroAUltimo();
    cout<<endl;
    L3.muestraUltimoAPrimero();
    cout<<endl<<endl;
    cout<<"n3 = "<<L3.cuentaNodos()<<endl
        <<"suma = "<<L3.sumaNodos()<<endl
        <<"prom = "<<L3.promediaNodos()<<endl
        <<"menor = "<<L3.buscaMenor()<<endl
        <<"mayor = "<<L3.buscaMayor()<<endl
        <<"dato en mitad = "<<L3.datoEnNodoEnMitad()<<endl
        <<"dato en nodo #"<<nesimo<<" = "<<L3.datoEnNesimoNodo(nesimo)<<endl<<endl;

    system("pause");
    system("cls");

    L4.concatenaListasInvertidas(L,L2);
    cout<<"L"<<endl;
    L.muestraPrimeroAUltimo();
    cout<<endl;
    L.muestraUltimoAPrimero();
    cout<<endl<<endl;
    cout<<"L2"<<endl;
    L2.muestraPrimeroAUltimo();
    cout<<endl;
    L2.muestraUltimoAPrimero();
    cout<<endl<<endl;
    cout<<"L4"<<endl;
    L4.muestraPrimeroAUltimo();
    cout<<endl;
    L4.muestraUltimoAPrimero();
    cout<<endl<<endl;
    cout<<"n4 = "<<L4.cuentaNodos()<<endl
        <<"suma = "<<L4.sumaNodos()<<endl
        <<"prom = "<<L4.promediaNodos()<<endl
        <<"menor = "<<L4.buscaMenor()<<endl
        <<"mayor = "<<L4.buscaMayor()<<endl
        <<"dato en mitad = "<<L4.datoEnNodoEnMitad()<<endl
        <<"dato en nodo #"<<nesimo<<" = "<<L4.datoEnNesimoNodo(nesimo)<<endl<<endl;
    system("pause");
    system("cls");

    L5.concatenaListasOrdenadamente(L,L2);
    cout<<"L"<<endl;
    L.muestraPrimeroAUltimo();
    cout<<endl;
    L.muestraUltimoAPrimero();
    cout<<endl<<endl;
    cout<<"L2"<<endl;
    L2.muestraPrimeroAUltimo();
    cout<<endl;
    L2.muestraUltimoAPrimero();
    cout<<endl<<endl;
    cout<<"L5"<<endl;
    L5.muestraPrimeroAUltimo();
    cout<<endl;
    L5.muestraUltimoAPrimero();
    cout<<endl<<endl;
    cout<<"n5 = "<<L5.cuentaNodos()<<endl
        <<"suma = "<<L5.sumaNodos()<<endl
        <<"prom = "<<L5.promediaNodos()<<endl
        <<"menor = "<<L5.buscaMenor()<<endl
        <<"mayor = "<<L5.buscaMayor()<<endl
        <<"dato en mitad = "<<L5.datoEnNodoEnMitad()<<endl
        <<"dato en nodo #"<<nesimo<<" = "<<L5.datoEnNesimoNodo(nesimo)<<endl<<endl;
    system("pause");
    system("cls");

    return 0;
}
