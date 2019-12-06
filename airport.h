#ifndef AIRPORT_H_INCLUDED
#define AIRPORT_H_INCLUDED
#include <iostream>
#include "airline.h"
#include "flight.h"
#include "passnger.h"
#include "room.h"
using namespace std;

const int NUMBER_OF_AIRLINES = 3;
const int NUMBER_OF_ROOMS = 10;

class Airport{
    private:
        string ident;
        string date;
        string city;
        string country;
        int totalTransactions;
        float totalDailyIncome;
        Airline airlines[NUMBER_OF_AIRLINES];
        Room rooms[NUMBER_OF_ROOMS];
    public:
        Airport();
        Airport(string);
        //Metodos principales
        void startOperations(string);
        void printAllFilghts();
        void closeOperations();
        void programFlightFromAirline();
        void showAllIncomes();
        void updateAnAirline();
        void nightSystem();
        //Getters
        string getId();
        string getDate();
        string getCity();
        string getCountry();
        Airline getAirlineByIndex(int);
        //Setters
        void setId(string);
        void setDate(string);
        void setCity(string);
        void setCountry(string);
        //Utileria
        void lineaFormato();
};

#endif // AIRPORT_H_INCLUDED
