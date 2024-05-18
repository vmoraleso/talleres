#include <iostream>
#include <malloc.h>
#include <stdlib.h>
using namespace std;

struct empresat{
    int RNT;
    int year  ;
    int mes ;
    int dia;
    empresat*izq;
    empresat*der;
}; 
empresat *raiz, *raiz2, * aux, *aux2 , *aux3, *aux4 ;                       

int posicionar(){
    if(aux->RNT < aux2->RNT){
        if(aux2->izq==NULL){
            aux2->izq = aux;
            aux2 = aux = NULL;
            free(aux);
            free(aux2);
        } else {
            aux2 = aux2->izq;
            posicionar();
        }
    } 
    else if(aux->RNT > aux2->RNT){
        if(aux2->der==NULL){
            aux2->der = aux;
            aux2 = aux = NULL;
            free(aux);
            free(aux2);
        } else {
            aux2 = aux2->der;
            posicionar();
        }
    }
    return 0;
};
int posicionar2(){
    if(aux3->dia < aux4->dia ||(aux3->dia == aux4->dia && aux3->mes < aux4->mes) ||
        (aux3->dia == aux4->dia && aux3->mes == aux4->mes && aux->dia < aux2->dia) ||
        (aux3->dia == aux4->dia && aux3->mes == aux4->mes && aux->dia == aux2->dia &&
         aux->year < aux2->year )) {
        if(aux4->izq==NULL){
            aux4->izq = aux3;
            aux4 = aux3= NULL;
            free(aux3);
            free(aux4);
        } else {
            aux4 = aux4->izq;
            posicionar2();
        }
    } 
    else if(aux3->dia < aux4->dia ||(aux3->dia == aux4->dia && aux3->mes < aux4->mes) ||
        (aux3->dia == aux4->dia && aux3->mes == aux4->mes && aux->dia < aux2->dia) ||
        (aux3->dia == aux4->dia && aux3->mes == aux4->mes && aux->dia == aux2->dia &&
         aux->year < aux2->year ) ){
        if(aux4->der==NULL){
            aux4->der = aux3;
            aux3 = aux4 = NULL;
            free(aux3);
            free(aux4);
        } else {
            aux4 = aux4->der;
            posicionar2();
        }
    }
    return 0;
};
int registrar(){

    aux = (struct empresat*)malloc(sizeof(struct empresat));
    cout<<"Ingrese su RNT "<<endl;
    cin>>aux->RNT;
    
        
    aux->der = aux->izq = NULL;
    if(!raiz){
        raiz = aux;
        aux = NULL;
        free(aux);
    }
    else {
        aux2 = raiz;
        posicionar();
    }

    aux3 = (struct empresat*)malloc(sizeof(struct empresat));
    cout<<"Fecha de vencimiento  ";
        cout <<" dia "<<endl;
        cin>>aux3->dia;
        cout <<" mes  "<<endl;
        cin>>aux3->mes;
        cout <<" año "<<endl;
        cin>>aux3->year;
    aux3->der = aux3->izq = NULL;
    if(!raiz2){
        raiz2 = aux3;
        aux3 = NULL;
        free(aux3);
    }
    else {
        aux4 = raiz2;
        posicionar2();
    }
return 0;
};


int preorden (empresat *recursive ){
cout<< " RNT de la empresa  "<<recursive->RNT<<endl;
if (recursive->izq!=NULL){
 preorden(recursive->izq);
}
 if (recursive->der!=NULL)
{
 preorden(recursive->der);   
}


return 0;
};
int posorden (empresat *recursive){
if (recursive->izq!=NULL){
 posorden(recursive->izq);
}

 if (recursive->der!=NULL)
{
posorden(recursive->der);   
}
cout<< " RNT de la empresa  "<<recursive->RNT<<endl;
return 0;

};
int inorden (empresat *recursive){

if (recursive->izq!=NULL){
inorden(recursive->izq);
}
cout<< " RNT de la empresa  "<<recursive->RNT<<endl;
 if (recursive->der!=NULL)
{
 inorden(recursive->der);   
}
return 0;
};
int  ubicar (empresat *recursive,int aguja ){
if (recursive->RNT == aguja){
        aux = recursive;
        return 1;
    }
    else
    {
        if (recursive->izq != NULL)
        {
            ubicar(recursive->izq, aguja);
        }
        if (recursive->der != NULL)
        {
            ubicar(recursive->der, aguja);
        }
    }
    return 0;





};
int eliminar (){
int valbuscar;
cout<<" digite el valor a buscar"<<endl;
cin>>valbuscar;
ubicar(raiz,valbuscar);
if (aux==NULL){
cout<<" el dato a buscar no se encuentra "<<endl;
}
else 
cout<<" el dato encontrado "<<endl;
return 0;
};


//Funcion Recursiva


main(){
    int opc=0;
    do {
        cout<<"1. Registrar"<<endl;
        cout<<"2.preorden"<<endl;
        cout<<"3.inorden"<<endl;
        cout<<"4.posorden"<<endl;
        cout<<"------------- "<<endl;
        cout<<"5.eliminar"<<endl;
        cout<<"6.salir  "<<endl;
        cin>>opc;
        switch (opc)
        {
        case 1: registrar();
            break;
            case 2:preorden (raiz);
            break ;
            case 3 :inorden (raiz);
            break;
            case 4 :posorden (raiz);
            break;
        case 5 : eliminar();
        }

    } while(opc!=5);
}