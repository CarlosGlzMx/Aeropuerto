#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED
#include <iostream>
#include "passnger.h"
#include "hora.h"
using namespace std;

const int NUMBER_OF_ROWS = 30;
const int NUMBER_OF_COLUMNS = 4;

class Flight{
    private:
        string date;
        Hora hour;
        string crew;
        string airplaneModel;
        string fromTo;
        float distance;
        float price;
        float fuel;
        Passenger seats[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
    public:
        Flight();
        //Métodos principales
        void calculateFuel(string);
        void setPassenger(int fila, int columna);
        bool seatIsFree(int fila, int columna);
        //Getters
        string getDate();
        Hora getHour();
        string getAirplaneModel();
        string getFromTo();
        string getCrew();
        float getDistance();
        float getPrice();
        float getFuel();
        //Setters
        void setDate(string);
        void setHour(string);
        void setAirplaneModel(string);
        void setFromTo(string);
        void setCrew(string);
        void setPrice(float);
        void setFuel(float);
        void setDistance(float);
};

#endif // FLIGHT_H_INCLUDED
