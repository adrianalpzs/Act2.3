/*
Act 2.3 - Actividad Integral estructura de datos lineales

Adriana López A01656937
Mariana Muñoz A01653166

Este programa ordena dependiendo de la dirección IP, selecciona fechas para tener un archivo nuevo con esas limitaciones.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Bitacora.h"

using namespace std;

vector<Bitacora> cargaBitacora(string arch);

void Guarda(vector<Bitacora>vect, string arch, int inicio, int fin) {
    ofstream f;
    f.open(arch);
    for(int i = inicio; i <= fin; i++) {
        f << vect[i] << endl;
    }
    f.close();
}

int binarySearch(vector<Bitacora>&lista, int q, int w, unsigned int e)  {
    if (w >= q) {
        int mid = q + (w - q)/2;
        if (lista[mid].getIP() == e) return mid;
        if (lista[mid].getIP() > e) return binarySearch(lista, q, mid-1, e);
        return binarySearch(lista, mid+1, w, e);
    }
    return -1;
}

unsigned int gatito(int ip_3,int ip_2,int ip_1,int ip_0){
    int ip3 = ip_3 * 255 * 255 * 255;
    int ip2 = ip_2 * 255 * 255;
    int ip1 = ip_1 * 255;
    int ip0 = ip_0;
    unsigned int ip = ip3 + ip2 + ip1 + ip0;
    return ip;
}

void ordenaBurbuja(vector<Bitacora>&lista) {
    bool swap = true;
    int pares = lista.size();

    while (swap) {
        pares--;
        swap = false;
        for (int i = 0; i < pares; i++) {
            if (lista.at(i).getIP() > lista.at(i + 1).getIP()) {
                Bitacora tmp = lista.at(i);
                lista.at(i) = lista.at(i + 1);
                lista.at(i + 1) = tmp;
                swap = true;
            }
        }
    }
}


int main () {
    // Se carga la bitácora
    vector<Bitacora>bitacora = cargaBitacora("bitacora2.txt");
    cout << "Bitácora sin ordenar" << endl;
    for (auto b : bitacora) {
        cout << b << endl;
    }

    cout << "Bitácora ordenada " << endl;
    ordenaBurbuja(bitacora);
    for (auto b : bitacora) {
        cout << b << endl;
    }

    cout << " Búsqueda bitácora " << endl;

    int inicio = binarySearch(bitacora, 0, bitacora.size(), gatito(141,122,59,186));
    cout << "Índice valor inicial: " + to_string(inicio) << endl;

    int final = binarySearch(bitacora, 0, bitacora.size(), gatito(251,173,196,129));
    cout << "Índice valor final: " + to_string(final) << endl;

    if(inicio < 0 || final < 0) {
        cout << " No ha sido guardada la bitácora " << endl;
        cout << "Rangos incorrectos, favor de verificarlos. " << endl;
    }
    else {
        cout << "Datos encontrados" << endl;
        for(int i = inicio; i <= final; i++) {
            cout << bitacora[i] << endl;
        }
        cout << "Guardado con éxito " << endl;
        Guarda(bitacora, "bitacoraYei.txt", inicio, final);
    }

    return 0;
}

