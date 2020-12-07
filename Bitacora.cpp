//
//  Bitacora.cpp
//  Actividad2.3
//

#include "Bitacora.h"
#include <sstream>
#include <iomanip>
#include <iostream>

Bitacora::Bitacora(time_t dHour, unsigned int ip, string mot) {
    this->dHour = dHour;
    this->ip = ip;
    this->mot = mot;
}

void Bitacora::setDHour(time_t fh) { dHour = fh; }

time_t Bitacora::getDHour() { return dHour; }

unsigned int Bitacora::getIP() { return ip; }

void Bitacora::setMot(string mot) { this->mot = mot; }

ostream& operator<<(ostream &os, const Bitacora &b) {
    tm ts = *std::localtime(&b.dHour);
    std::stringstream ss;
    os << "fecha hora: " << b.dHour << " " << std::put_time(&ts,"%F %T") << " ip: " << b.ip << " razón: " << b.mot<< " ";
    return os;
}

bool operator<(const Bitacora &b1, const Bitacora &b2) { return b1.dHour < b2.dHour; }

bool operator>(const Bitacora &b1, const Bitacora &b2) { return b1.dHour > b2.dHour; }

bool operator==(const Bitacora &b1, const Bitacora &b2) { return b1.dHour == b2.dHour; }

Bitacora::~Bitacora() { }
