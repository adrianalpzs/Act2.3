//
//  cargaBitacora.cpp
//  Actividad2.3
//


#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

#include "Bitacora.h"

vector<Bitacora> cargaBitacora(string archivo) {
    vector<Bitacora> bitacora;
    ifstream f;
    string mes, dia, tiempo;
    f.open(archivo);
    
    for(int i = 0; i < 15; i++) {
        getline(f, mes, ' ');
        getline(f, dia, ' ');
        getline(f, tiempo, ' ');
        tm ts;
        ts.tm_isdst = 1;
        string tss = "2019 " + mes + " " + dia + " " + tiempo;
        strptime(tss.c_str(),"%Y %b %d %H:%M:%S", &ts);
        time_t dHour = mktime(&ts);
        string ip_3, ip_2, ip_1, ip_0, puerto;
        getline(f, ip_3, '.');
        getline(f, ip_2, '.');
        getline(f, ip_1, '.');
        getline(f, ip_0, ':');
        int ip3 = stoi(ip_3) * 255 * 255 * 255;
        int ip2 = stoi(ip_2) * 255 * 255;
        int ip1 = stoi(ip_1) * 255;
        int ip0 = stoi(ip_0);
        unsigned int ip = ip3 + ip2 + ip1 + ip0;
        getline(f, puerto, ' ');
        string mot;
        getline(f, mot);
        Bitacora b(dHour, ip, mot);
        bitacora.push_back(b);
    }
    return bitacora;
}
