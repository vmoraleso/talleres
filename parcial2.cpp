#include <iostream>
#include <malloc.h>
#include <stdlib.h>
using namespace std;

struct empresat{
    int RNT;
    int year;
    int fecha ;
    int mes ;
    int dia;
    int value;
    empresat*izq;
    empresat*der;
}; 
empresat *raiz, *raiz2, * aux, *aux2 , *aux3, *aux4,*rem,*elim ;                       

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
    if(aux3->fecha < aux4->fecha) {
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
    else if(aux3->fecha > aux4->fecha) {
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
   
    cout <<" ingrese la fecha en formato AAAAMMDD"<<endl;
    cin>>aux3->fecha;
    aux3->year =aux3-> fecha / 10000;
    aux3-> mes = (aux3->fecha / 100) % 100;
    aux3->dia = aux3->fecha % 100;
    cout << "Fecha ingresada: " <<    aux3->dia << "/" <<    aux3->mes << "/" <<  aux3->year  << endl;
        
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
   
    aux3->RNT= aux->RNT;

    aux3->dia= aux->dia;  

    aux3->mes= aux->mes;  

    aux3->year= aux->year;

    aux3->der= aux3->izq=NULL;

    if(!raiz2){

        raiz2 = aux3;

        aux3 =NULL;

        free(aux3);
}

    else {

        aux4 = raiz2;

        posicionar2();

    }

return
0;

};






int Ubicar_Padre(empresat *Padre){

    if ((Padre->izq != NULL) && (Padre->izq != aux))
    {
        Ubicar_Padre(Padre->izq);
    }
    if (Padre->izq == aux)
    {
        aux2 = Padre;
    }
    else if ((Padre->der != NULL) && (Padre->der != aux))
    {
        Ubicar_Padre(Padre->der);
    }
    if (Padre->der == aux)
    {
        aux2 = Padre;
    }
    return 0;}
int ubicar_padre2(empresat *papi){
if ((papi->izq != NULL) && (papi->izq != aux))
    {
        ubicar_padre2(papi->izq);
    }
    if (papi->izq == aux)
    {
        aux4 = papi;
    }
    else if ((papi->der != NULL) && (papi->der != aux3))
    {
        ubicar_padre2(papi->der);
    }
    if (papi->der == aux3)
    {
        aux4= papi;
    }


    return 0;
}
int sin_hijos(){ 
    /* 1.Que nodo va a eliminar
       2.Buscar dicho nodo
       3.Garantizar que el nodo padre apunte a NULL.
       4.Liberar el nodo.*/
 if (aux != raiz)
    {
        Ubicar_Padre(raiz);
    } 
    if (aux2->izq == aux)
    {
        aux2->izq = NULL;
    }
    else if (aux2->der == aux)
    {
        aux2->der = NULL;
    } 
    free(aux);
    return 0; 

}
int un_hijos(){
    /* 1.Que nodo va a eliminar
       2.Buscar dicho nodo
       3.Garantizar que el nodo padre apunte al nodo hijo de su  hijo (su nieto).
       4.Liberar el nodo.*/
    if (aux != raiz)
    {
        Ubicar_Padre(raiz);
    } 
    if (aux2->izq == aux)
    {
        if (aux->izq != NULL)
            aux2->izq = aux->izq;
        else if (aux->der != NULL)
            aux2->izq = aux->der;
    }
    else if (aux2->der == aux)
    {
        if (aux->izq != NULL)
            aux2->der = aux->izq;
        else if (aux->der != NULL)
            aux2->der = aux->der;
    } 
    free(aux);
    return 0;
}
int dos_hijos(){ 
    int sucesor;
    elim->izq;
while(elim->der!=NULL)
{
  (elim->der);
}
rem->value=elim->value;

sucesor=rem->value;

if ((aux->der == NULL) && (aux->izq == NULL))
    {
        sin_hijos();
    }
    else if (((aux->der != NULL) && (aux->izq == NULL)) || ((aux->der == NULL) && (aux->izq != NULL)))
    {
    un_hijos();
    }
    aux->RNT = sucesor;

    return 0;}
int sin_hijos2(){
    if (aux3 != raiz2)
    {
        ubicar_padre2(raiz2);
    } 
    if (aux4->izq == aux3)
    {
        aux4->izq = NULL;
    }
    else if (aux4->der == aux3)
    {
        aux4->der = NULL;
    } 
    free(aux3);
    return 0; }
int un_hijo2(){
    if (aux3 != raiz2)
    {
       ubicar_padre2(raiz2);
      } 
     if (aux4->izq == aux3)
     {
        if (aux3->izq != NULL)
            aux4->izq = aux3->izq;
        else if (aux3->der != NULL)
            aux4->izq = aux3->der;
     }
     else if (aux4->der == aux3)
     {
        if (aux3->izq != NULL)
            aux4->der = aux3->izq;
        else if (aux3->der != NULL)
            aux4->der = aux3->der;
    } 
    free(aux3);
    return 0;
    }
 int dos_hijos2(){
  int Sucesor;
    elim->izq;
while(elim->der!=NULL)
{
  (elim->der);
}
rem->value=elim->value;

Sucesor=rem->value;
if ((aux3->der == NULL) && (aux3->izq == NULL))
    {
        sin_hijos();
    }
    else if (((aux3->der != NULL) && (aux3->izq == NULL)) || ((aux3->der == NULL) && (aux3->izq != NULL)))
    {
    un_hijos();
    }
    aux3->fecha = Sucesor;


    return 0;}

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
int preorden2(empresat *nodo){

cout<< "fecha de vencimiento de la empresa  "<<nodo->fecha<<endl;
if (nodo->izq!=NULL){
 preorden2(nodo->izq);
}
 if (nodo->der!=NULL)
{
 preorden2(nodo->der);   
}

return 0;

}
int posorden2(empresat*nodo){
   
if (nodo->izq!=NULL){
 posorden2(nodo->izq);
}

 if (nodo->der!=NULL)
{
posorden2(nodo->der);   
}
cout<< " fecha de vencimiento de la empresa "<<nodo->fecha<<endl;
return 0;


}
int inorden2(empresat*nodo){
     if (nodo->izq!=NULL){
inorden2(nodo->izq);
}
cout<< " fecha de vencimiento de la empresa  "<<nodo->fecha<<endl;
 if (nodo->der!=NULL)
{
 inorden2(nodo->der); 
}
return 0;
}
void recorrido_arbol1(){
cout<<"RECORRIDO EN PRE-ORDEN"<<endl;
preorden(raiz);
cout<<"RECORRIDO EN POS-ORDEN"<<endl;
posorden(raiz);
cout<<"RECORRIDO EN IN-ORDEN"<<endl;
inorden(raiz);
}
void recorrido_arbol2(){
cout<<"RECORRIDO EN PRE-ORDEN"<<endl;
preorden2(raiz2);
cout<<"RECORRIDO EN POS-ORDEN"<<endl;
posorden2(raiz2);
cout<<"RECORRIDO EN IN-ORDEN"<<endl;
inorden2(raiz2);
}
int ubicar (empresat *recursive,int aguja ){
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
    if (recursive->fecha == aguja){
        aux3 = recursive;
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
int eliminar_arbol1 (){
int valbuscar;
cout<<" digite el valor a buscar"<<endl;
cin>>valbuscar;
ubicar(raiz,valbuscar);
if (aux==NULL){
cout<<" el dato a buscar no se encuentra "<<endl;
}
else 
cout<<" el dato encontrado "<<endl;

    if ((aux->der == NULL) && (aux->izq == NULL))
    {
      sin_hijos();
    }
    else if (((aux->der != NULL) && (aux->izq == NULL)) || ((aux->der == NULL) && (aux->izq != NULL)))
    {
        un_hijos();
    }
    if ((aux->der != NULL) && (aux->izq != NULL))
    {
        dos_hijos();
    }
    return 0;

};
int eliminar_arbol2(){
    int val_buscar;
cout<<" digite el valor a buscar"<<endl;
cin>>val_buscar;
ubicar(raiz2,val_buscar);
if (aux3==NULL){
cout<<" el dato a buscar no se encuentra "<<endl;
}
else 
cout<<" el dato encontrado "<<endl;

    if ((aux3->der == NULL) && (aux3->izq == NULL))
    {
      sin_hijos();
    }
    else if (((aux3->der != NULL) && (aux3->izq == NULL)) || ((aux3->der == NULL) && (aux3->izq != NULL)))
    {
        un_hijos();
    }
    if ((aux3->der != NULL) && (aux3->izq != NULL))
    {
        dos_hijos();
    }
    return 0;
}



main(){
    int opc=0;
    do {
        cout<<"1. Registrar"<<endl;
        cout<<"2.recorrido arbol1"<<endl;
        cout<<"3.recorrido arbol2"<<endl;
         cout<<"------------- "<<endl;
        cout<<"4.eliminar arbol1"<<endl;
        cout<<"5.elimina arbol2r"<<endl;
        cout<<"6.salir  "<<endl;
        cin>>opc;
        switch (opc)
        {
            case 1: registrar();
            break;
         
            case 2:recorrido_arbol1();
            break ;
            case 3:recorrido_arbol2();
            break;
            case 4 :eliminar_arbol1();
            break;
            case 5 :eliminar_arbol2();
        }

    } while(opc!=6);
}
