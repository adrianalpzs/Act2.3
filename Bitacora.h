//
//  Bitacora.h
//  Actividad2.3
//
//


#ifndef Bitacora_h
#define Bitacora_h

#include <ctime>
#include <string>

using namespace std;

class Bitacora {
    private:
        time_t dHour;
        unsigned int ip;
        string mot;
        
    public:
        Bitacora(time_t dHour, unsigned int ip, string mot);
        
        void setDHour(time_t fh);
        void setMot(string mot);
        time_t getDHour();
        unsigned int getIP();
        friend ostream& operator<<(ostream &strm, const Bitacora &b);
        friend bool operator<(const Bitacora &b1, const Bitacora &b2);
        friend bool operator>(const Bitacora &b1, const Bitacora &b2);
        friend bool operator==(const Bitacora &b1, const Bitacora &b2);
        ~Bitacora();
};

#endif /* Bitacora_h */
