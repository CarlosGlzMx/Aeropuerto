#ifndef AIRLINE_H_INCLUDED
#define AIRLINE_H_INCLUDED
#include <iostream>
#include "flight.h"
#include "passnger.h"
using namespace std;

const int NUMBER_OF_FLIGHTS = 5;

class Airline{
    private:
        string boardingCity;
        string shortName;
        string name;
        float incomes;
        /*Dado que el programa solo agrega a flights los vuelos en horario permitido,
        este arreglo flights es el equivalente al arreglo calendario del documento. En el menu
        hey funciones para imprimirlos*/
        Flight flights[NUMBER_OF_FLIGHTS];
    public:
        Airline();
        //Métodos principales
        void updateAirline();
        void scheduleFlight();
        void currentIncome();
        void closeOperation();
        void printSeating(Flight);
        int countsSeats(Flight);
        //Getters
        string getBoardingCity();
        string getShortName();
        string getName();
        float getIncomes();
        Flight getFlightByIndex(int);
        //Setters
        void setBoardingCity(string);
        void setShortName(string);
        void setIncomes(float);
        void setName(string);
};

#endif // AIRLINE_H_INCLUDED
