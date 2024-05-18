#include <iostream>
#include <malloc.h>
using namespace std;

struct nodo {
    int matricula;
    char nombre[60];
    int movimientos;
    nodo *sig;
};

struct nodo *top, *aux, *aux2, *topaux, *top2;

void registrar() {
    int opc = 0;

    cout << "Tipo de vehiculo" << endl;
    cout << "1. Moto" << endl;
    cout << "2. Carro" << endl;
    cin >> opc;

    if (opc == 1) {
        aux = ((struct nodo *) malloc(sizeof(struct nodo)));
        cout << "Ingrese su matricula" << endl;
        cin >> aux->matricula;
        aux->movimientos = 0;

        if (top == NULL) {
            top = aux;
            aux->sig = NULL;
        } else {
            aux->sig = top;
            top = aux;
        }
    }

    if (opc == 2) {
        aux2 = ((struct nodo *) malloc(sizeof(struct nodo)));
        cout << "Ingrese su matricula" << endl;
        cin >> aux2->matricula;
        aux2->movimientos = 0;

        if (top2 == NULL) {
            top2 = aux2;
            aux2->sig = NULL;
        } else {
            aux2->sig = top2;
            top2 = aux2;
        }
    }
}

void mostrar() {
    cout << "MOTOS" << endl;
    cout << "Vehiculos registrados" << endl;
    for (aux = top; aux != NULL; aux = aux->sig) {
        cout << "Placa " << aux->matricula << " - Movimientos: " << aux->movimientos << endl;
    }

    cout << "CARROS" << endl;
    for (aux2 = top2; aux2 != NULL; aux2 = aux2->sig) {
        cout << "Placa " << aux2->matricula << " - Movimientos: " << aux2->movimientos << endl;
    }
}

void buscar() {
    int placa;
    cout << "Placa a buscar: " << endl;
    cin >> placa;

    bool placa_encontrada = false;

    for (aux = top; aux != NULL; aux = aux->sig) {
        if (aux->matricula == placa) {
            cout << "Placa encontrada: " << placa << endl;
            cout << "Movimientos realizados: " << aux->movimientos << endl;
            placa_encontrada = true;
            break;
        }
    }

    for (aux2 = top2; aux2 != NULL; aux2 = aux2->sig) {
        if (aux2->matricula == placa) {
            cout << "Placa encontrada: " << placa << endl;
            cout << "Movimientos realizados: " << aux2->movimientos << endl;
            placa_encontrada = true;
            break;
        }
    }

    if (!placa_encontrada) {
        cout << "Su placa no se encontro en el parqueadero" << endl;
    }
}

void movimiento_m() {
    int placa;
    cout << "Ingrese la placa de la moto: ";
    cin >> placa;

    for (aux = top; aux != NULL; aux = aux->sig) {
        if (aux->matricula == placa) {
            aux->movimientos++;
            int costoTotal = aux->movimientos * 500;
            cout << "El costo total del movimiento de la moto es: " << costoTotal << endl;
            return;
        }
    }

    cout << "La placa de la moto no se encontró en el parqueadero" << endl;
}

void movimiento_c() {
    int placa;
    cout << "Ingrese la placa del carro: ";
    cin >> placa;

    for (aux2 = top2; aux2 != NULL; aux2 = aux2->sig) {
        if (aux2->matricula == placa) {
            aux2->movimientos++;
            int costoTotal = aux2->movimientos * 1000;
            cout << "El costo total del movimiento del carro es: " << costoTotal << endl;
            return;
        }
    }

    cout << "La placa del carro no se encontró en el parqueadero" << endl;
}

void eliminar() {
    int matricula;

    cout << "Valor a eliminar: " << endl;
    cin >> matricula;
    while (top->matricula != matricula) {
        if (topaux == NULL) {
            aux = top;
            top = top->sig;
            aux->sig = NULL;
            topaux = aux;
        } else {
            aux = top;
            top = top->sig;
            aux->sig = topaux;
            topaux = aux;
        }
    }
    aux = top;
    top = top->sig;
    free(aux);
    while (topaux != NULL) {
        aux = topaux;
        topaux = topaux->sig;
        aux->sig = top;
        top = aux;
    }
    aux = NULL;
    free(aux);
}

int main() {
    int opc = 0;
    do {
        cout << "BIENVENIDO AL PARQUEADERO LULU :)" << endl;
        cout << "1. Ingreso de vehiculos" << endl;
        cout << "2. Mostrar vehiculos" << endl;
        cout << "3. Salida de vehiculos" << endl;
        cout << "4. Buscar" << endl;
        cout << "5. Movimiento de motos" << endl;
        cout << "6. Movimiento de carros" << endl;
        cout << "7. Salir" << endl;
        cin >>opc;
                switch (opc) {
            case 1:
                registrar();
                break;
            case 2:
                mostrar();
                break;
            case 3:
                eliminar();
                break;
            case 4:
                buscar();
                break;
            case 5:
                movimiento_m();
                break;
            case 6:
                movimiento_c();
                break;
            default:
                cout << "Gracias por usar el programa" << endl;
                break;
        }

    } while (opc != 7);

    return 0;
}

