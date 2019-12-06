#include <iostream>
#include "flight.h"
using namespace std;

Flight::Flight(){
    date = "";
    price = 0;
    airplaneModel = "747";
    fromTo = "";
    distance = 0;
    crew = "";
    fuel = 0;
}

//Metodos principales
void Flight::calculateFuel(string tempDestination){
    float consumo;
    consumo = distance * 12;
    if(airplaneModel == "777"){
            consumo = consumo * 1.1;
    }
    else if (airplaneModel == "787"){
        consumo = consumo * 1.2;
    }
    else if (airplaneModel != "747"){
        consumo = consumo * 0.9;
    }
    consumo = consumo / 3.785;
    fuel = consumo;
    cout << "El combustible requerido para viajar a " << tempDestination << " es de: " << consumo << " galones." << endl;
}
void Flight::setPassenger(int fila, int columna){
    fila = fila - 1;
    columna = columna - 1;
    if(seats[fila][columna].getName() == ""){
        string respuesta = "";
        cout << "Quieres agregar infomacion personal? ";
        cin >> respuesta;
        if(respuesta == "si"){
            cout << "Ingresa el nombre que llevara la reservacion: ";
            string cinName = "ocupado";
            cin >> cinName;
            seats[fila][columna].setName(cinName);
            cout << "Ingresa el telefono que llevara la reservacion: ";
            string cinPhone = "(NNN)NNN-NNNN";
            cin >> cinPhone;
            seats[fila][columna].setPhone(cinPhone);
        }
        else{
        seats[fila][columna].setName("Ocupado");
        seats[fila][columna].setPhone("(NNN)NNN-NNNN");
        }
    }
    else{
        cout << "Reservacion incorrecta: Espacio ocupado" << endl;
    }
}
bool Flight::seatIsFree(int fila, int columna){
    if(seats[fila][columna].getName() == ""){
        return true;
    }
    else{
        return false;
    }
}

//Getters
string Flight::getDate(){
    return date;
}
Hora Flight::getHour(){
    return hour;
}
string Flight::getCrew(){
    return crew;
}
string Flight::getAirplaneModel(){
    return airplaneModel;
}
string Flight::getFromTo(){
    return fromTo;
}
float Flight::getDistance(){
    return distance;
}
float Flight::getPrice(){
    return price;
}
float Flight::getFuel(){
    return fuel;
}

//Setters
void Flight::setDate(string tempDate){
    date = tempDate;
}
void Flight::setHour(string formatoMilitar){
    hour.setFormatoMilitar(formatoMilitar);
    hour.ajustaHora();
}
void Flight::setAirplaneModel(string tempAirplaneModel){
    airplaneModel = tempAirplaneModel;
}
void Flight::setFromTo(string tempFromTo){
    fromTo = tempFromTo;
}
void Flight::setCrew(string tempCrew){
    crew = tempCrew;
}
void Flight::setFuel(float tempFuel){
    fuel = tempFuel;
}
void Flight::setPrice(float tempPrice){
    price = tempPrice;
}
void Flight::setDistance(float tempDistance){
    distance = tempDistance;
}
