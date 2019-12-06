#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED
#include <iostream>
using namespace std;

class Hora{
    private:
        int horas;
        int minutos;
        string formatoMilitar;
    public:
        Hora();
        Hora(string tempFormatoMilitar);
        int getHoras();
        int getMinutos();
        string getFormatoMilitar();
        void setHoras(int tempHoras);
        void setMinutos(int tempMinutos);
        void setFormatoMilitar(string tempFormatoMilitar);
        bool horaAdecuada();
        void ajustaHora();
};

#endif // HORA_H_INCLUDED
