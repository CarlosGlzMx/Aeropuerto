#include <iostream>
#include "airline.h"
using namespace std;

Airline::Airline(){
    boardingCity = "";
    shortName = "";
    name = "";
    incomes = 0;
}

//Metodos principales
int Airline::countsSeats(Flight tempFlight){
    int freeSeats = 0;
    for(int i = 0; i < NUMBER_OF_ROWS; i++){
        for(int j = 0; j < NUMBER_OF_COLUMNS; j++){
            if(tempFlight.seatIsFree(i,j)){
                freeSeats = freeSeats + 1;
            }
        }
    }
    return freeSeats;
}
void Airline::printSeating(Flight tempFlight){
    cout << "0  1  2  3  4" << endl;
    for(int i = 0; i < NUMBER_OF_ROWS; i++){
        if(i + 1 < 10){
            cout << i + 1 << "  ";
        }
        else{
            cout << i + 1 << " ";
        }
        for(int j = 0; j < NUMBER_OF_COLUMNS; j++){
            if(tempFlight.seatIsFree(i,j)){
                cout << "[O]";
            }
            else{
                cout << "[X]";
            }
        }
        cout << "\n";
    }
}
void Airline::updateAirline(){
    cout << "Ingresa el nombre completo de la aerolinea: " << endl;
    cin >> name;
    cout << "Ingresa el nombre acortado de la aerolinea: " << endl;
    cin >> shortName;
}
void Airline::scheduleFlight(){
    int posVueloDisponible = -1;
    for(int i = NUMBER_OF_FLIGHTS - 1; i >= 0; i--){
        if(flights[i].getFromTo() == ""){
            posVueloDisponible = i;
        }
    }
    if(posVueloDisponible == -1){
        cout << "Vuelos de la linea aerea: " << name << " saturados, imposible programar." << endl;
    }
    else{
        cout << "La aerolinea tiene vuelos disponibles, inicia reservacion de vuelo..." << endl;
        cout << "Ingresa la hora de despegue en formato 23:59 : ";
        string cinHour = "";
        cin >> cinHour;
        flights[posVueloDisponible].setHour(cinHour);
        if(flights[posVueloDisponible].getHour().horaAdecuada() == false){
            cout << "La reservacion no se puede llevar a cabo, hora inadecuada o en periodo saturado" << endl;
        }
        else{
            cout << "Ingresa el modelo de avion a utilizar: ";
            string cinAirplaneModel = "";
            cin >> cinAirplaneModel;
            flights[posVueloDisponible].setAirplaneModel(cinAirplaneModel);
            cout << "Ingresa el destino del vuelo: ";
            string destination = "";
            cin >> destination;
            flights[posVueloDisponible].setFromTo(boardingCity + "-" + destination);
            cout << "Ingresa la distancia de la ruta: ";
            float cinDistance = 0;
            cin >> cinDistance;
            flights[posVueloDisponible].setDistance(cinDistance);
            flights[posVueloDisponible].calculateFuel(destination);
            cout << "Ingresa la clave numerica de la tripulacion: ";
            string cinCrew = "";
            cin >> cinCrew;
            flights[posVueloDisponible].setCrew(cinCrew);
            cout << "Ingresa el precio de un boleto: ";
            float cinPrice = 0;
            cin >> cinPrice;
            flights[posVueloDisponible].setPrice(cinPrice);
            cout << "----------------------------------" << endl;
            cout << "El vuelo ha sido programado, continue por reservar asientos" << endl;
            int freeSeats = countsSeats(flights[posVueloDisponible]);
            int fila = 0;
            int columna = 0;
            string continuar = "";
            while(freeSeats > 0 && (continuar != "no" && continuar != "NO")){
                printSeating(flights[posVueloDisponible]);
                fila = 0;
                columna = 0;
                while(fila < 1 || fila > 30){
                    cout << "Ingresa la fila del asiento que quieres: ";
                    cin >> fila;
                }
                while(columna < 1 || columna > 4){
                    cout << "Ingresa la columna del asiento que quieres: ";
                    cin >> columna;
                }
                flights[posVueloDisponible].setPassenger(fila,columna);
                cout << "Desea reservar mas asientos? ";
                cin >> continuar;
                freeSeats = countsSeats(flights[posVueloDisponible]);
            }
            cout << "Fin de la reservacion" << endl;
            currentIncome();
        }
    }
}
void Airline::currentIncome(){
    incomes = 0;
    for(int i = 0; i < NUMBER_OF_FLIGHTS; i++){
        incomes = incomes + (NUMBER_OF_COLUMNS * NUMBER_OF_ROWS - countsSeats(flights[i])) * flights[i].getPrice();
    }
    cout << "Las ganancias de la aerolinea son: " << incomes << endl;
}
void Airline::closeOperation(){
    cout << "Cierre de operaciones, la ganancia de: " << name << " el dia de hoy fue: " << incomes;
}


//Getters
string Airline::getBoardingCity(){
    return boardingCity;
}
string Airline::getShortName(){
    return shortName;
}
string Airline::getName(){
    return name;
}
float Airline::getIncomes(){
    return incomes;
}
Flight Airline::getFlightByIndex(int index){
    return flights[index];
}

//Setters
void Airline::setBoardingCity(string tempBoardingCity){
    boardingCity = tempBoardingCity;
}
void Airline::setShortName(string tempShortName){
    shortName = tempShortName;
}
void Airline::setIncomes(float tempIncomes){
    incomes = tempIncomes;
}
void Airline::setName(string tempName){
    name = tempName;
}
