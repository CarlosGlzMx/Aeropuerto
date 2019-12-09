#include <iostream>
#include <sstream>
#include "hora.h"
#include <cstdlib>
using namespace std;

//Constructor
Hora::Hora(){
    horas = -1;
    minutos = -1;
    formatoMilitar = "";
}

//Constructor con informacion inicial
Hora::Hora(string tempFormatoMilitar){
    formatoMilitar = tempFormatoMilitar;
    ajustaHora();
}

//Getters
int Hora::getHoras(){
    return horas;
}
int Hora::getMinutos(){
    return minutos;
}
string Hora::getFormatoMilitar(){
    return formatoMilitar;
}

//Setters
void Hora::setHoras(int tempHoras){
    horas = tempHoras;
}
void Hora::setMinutos(int tempMinutos){
    minutos = tempMinutos;
}
void Hora::setFormatoMilitar(string tempFormatoMilitar){
    formatoMilitar = tempFormatoMilitar;
}

//Cambia el formato militar de la hora a minutos y horas numericos
void Hora::ajustaHora(){
    string cadenaTemporal = "";
    if(string(1,formatoMilitar[1]) == ":" || string(1,formatoMilitar[2]) == ":"){
        if(string(1,formatoMilitar[1]) == ":"){
            cadenaTemporal = string(1,formatoMilitar[0]);
            stringstream dato1(cadenaTemporal);
            dato1 >> horas;
            cadenaTemporal = string(1,formatoMilitar[2]) + formatoMilitar[3];
            stringstream dato2(cadenaTemporal);
            dato2 >> minutos;
            if(horas < 0 || horas > 24 || minutos < 0 || minutos > 60){
                horas = -1;
                minutos = -1;
            }
        }
        else{
            cadenaTemporal = string(1,formatoMilitar[0]) + formatoMilitar[1];
            stringstream dato1(cadenaTemporal);
            dato1 >> horas;
            cadenaTemporal = string(1,formatoMilitar[3]) + formatoMilitar[4];
            stringstream dato2(cadenaTemporal);
            dato2 >> minutos;
            if(horas < 0 || horas > 24 || minutos < 0 || minutos > 60){
                horas = -1;
                minutos = -1;
            }
        }
    }
    else{
        horas = -1;
        minutos = -1;
    }
}

//Verifica si la hora es adecuada para un vuelo
bool Hora::horaAdecuada(){
    if(minutos != -1 && horas != -1){
        if(horas >= 23 || horas < 7){
            return true;
        }
        else if(horas == 7 && minutos == 0){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
