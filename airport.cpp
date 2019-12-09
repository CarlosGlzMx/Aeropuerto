#include <iostream>
#include <sstream>
#include "airport.h"
using namespace std;

//Constructores
Airport::Airport(){
    string fecha = "XX/XX/XXXX";
    startOperations(fecha);
    totalTransactions = 0;
    totalDailyIncome = 0;
}

Airport::Airport(string fecha){
    startOperations(fecha);
    totalTransactions = 0;
    totalDailyIncome = 0;
}

//Metodos del menu
//Inicia operaciones del aeropuerto
void Airport::startOperations(string tempFecha){
    date = tempFecha;
    cout << "Ingresa el identificador del aeropuerto: ";
    cin >> ident;
    cout << "Ingresa la ciudad de operacion del aeropuerto: ";
    cin.ignore();
    getline(cin, city);
    cout << "Ingresa el pais de operacion del aeropuerto: ";
    cin >> country;
    for(int i = 0; i < NUMBER_OF_AIRLINES; i++){
        airlines[i].setBoardingCity(city);
        for(int j = 0; j < NUMBER_OF_FLIGHTS; j++){
            airlines[i].getFlightByIndex(j).setDate(tempFecha);
        }
    }
    lineaFormato();
}
//Selecciona una aerolinea antes de pedirle programar un vuelo
void Airport::programFlightFromAirline(){
    string airlineAnswer;
    int chosenAirline;
    cout << "Iniciando sistema de vuelos y pasajeros" << endl;
    while(chosenAirline != 0 && chosenAirline != 1 && chosenAirline != 2){
        cout << "Ingresa la aerolinea con la que quieres trabajar:" << endl;
        for(int i = 0; i < NUMBER_OF_AIRLINES; i++){
            if(airlines[i].getName() == ""){
                cout << i + 1 << ".Registrar nueva aerolinea" << endl;
            }
            else{
                cout << i + 1 << "." << airlines[i].getName() << endl;
            }
        }
        cin >> airlineAnswer;
        stringstream data(airlineAnswer);
        data >> chosenAirline;
        chosenAirline = chosenAirline - 1;
        if(chosenAirline != 0 && chosenAirline != 1 && chosenAirline != 2){
            cout << "Por favor escoge una opcion valida" << endl;
        }
    }
    lineaFormato();
    if(airlines[chosenAirline].getName() == ""){
        cout << "Creando nueva aerolinea" << endl;
        airlines[chosenAirline].updateAirline();
        lineaFormato();
    }
    airlines[chosenAirline].scheduleFlight();
}
//Muestra los ingresos de todas las aerolineas
void Airport::showAllIncomes(){
    cout << "Los ingresos de las aerolineas el " << date << " han sido:" << endl;
    bool faltanAerolineas = true;
    for(int i = 0; i < NUMBER_OF_AIRLINES; i++){
        if(airlines[i].getName() != ""){
            faltanAerolineas = false;
            cout << airlines[i].getName() << ": " << airlines[i].getIncomes() << endl;
        }
    }
    if(faltanAerolineas){
        cout << "No se presentaron aerolineas" << endl;
    }
}
//Actualiza la informacion de una aerolinea
void Airport::updateAnAirline(){
    int numAirline;
    cout << "Escoge el nombre de la aerolinea a actualizar" << endl;
    for(int i = 0; i < NUMBER_OF_AIRLINES; i++){
        if(airlines[i].getName() != ""){
            cout << i + 1 << "." << airlines[i].getName() << endl;
        }
        else{
            cout << i + 1 << "." << "Aerolinea sin nombre" << endl;
        }
    }
    cin >> numAirline;
    while(numAirline > 3 || numAirline < 1){
        cout << "Ingresa una opcion valida" << endl;
        cin >> numAirline;
    }
    numAirline = numAirline - 1;
    airlines[numAirline].updateAirline();
    cout << "Actualizacion exitosa" << endl;
}
//Imprime para cada aerolinea todos los vuelos programados
void Airport::printAllFilghts(){
    cout << "Los vuelos programados para: " << date << " son:" << endl;
    bool faltaDeVuelos = true;
    bool faltaDeAerolinea = true;
    for(int i = 0; i < NUMBER_OF_AIRLINES; i++){
        if(airlines[i].getName() != ""){
            faltaDeAerolinea = false;
            cout << airlines[i].getName() << ":" << endl;
            for(int j = 0; j < NUMBER_OF_FLIGHTS; j++){
                if(airlines[i].getFlightByIndex(j).getFromTo() != ""){
                    faltaDeVuelos = false;
                    cout << "Vuelo " << j+1 << endl;
                    cout << "Ruta: " << airlines[i].getFlightByIndex(j).getFromTo() << endl;
                    cout << "Hora: " << airlines[i].getFlightByIndex(j).getHour().getFormatoMilitar() << endl;
                    cout << "Modelo del avion: " << airlines[i].getFlightByIndex(j).getAirplaneModel() << endl;
                    cout << "Tripulacion a cargo: " << airlines[i].getFlightByIndex(j).getCrew() << endl;
                    cout << "Distancia de vuelo: " << airlines[i].getFlightByIndex(j).getDistance() << endl;
                    cout << "Galones de combustible requeridos: " << airlines[i].getFlightByIndex(j).getFuel() << endl;
                    cout << "Precio por boleto: " << airlines[i].getFlightByIndex(j).getPrice() << endl;
                    cout << "Distribucion de asientos: " << endl;
                    airlines[i].printSeating(airlines[i].getFlightByIndex(j));
                }
            }
        }
    }
    if(faltaDeVuelos && faltaDeAerolinea){
        cout << "No se programaron vuelos durante el dia" << endl;
    }
    else if(faltaDeVuelos || faltaDeAerolinea){
        cout << "Se presento esta aerolinea, mas no programo vuelos" << endl;
    }
}
//Termina el funcionamiento del aeropuerto para terminar el programa
void Airport::closeOperations(){
    cout << "Sistema finalizado" << endl;
    totalTransactions = 0;
    totalDailyIncome = 0;
    for(int i = 0; i < NUMBER_OF_AIRLINES; i++){
        for(int j = 0; j < NUMBER_OF_FLIGHTS; j++){
            if(airlines[i].getFlightByIndex(j).getFromTo() != ""){
                totalTransactions = totalTransactions + 1;
            }
        }
        totalDailyIncome = totalDailyIncome + airlines[i].getIncomes();
    }
    cout << "Durante el dia hubieron un total de: " << totalTransactions << " vuelos." << endl;
    cout << "Generando un ingreso total a las aerolineas de: " << totalDailyIncome << endl;
}
//Sistema de reservaciones
void Airport::nightSystem(){
    string respuestaHabitaciones;
    cout << "Sistema de habitaciones del aeropuerto" << endl;
    cout << "Selecciona una opcion: " << endl;
    cout << "1.Reservar habitacion" << endl;
    cout << "2.Cancelar habitacion" << endl;
    cin >> respuestaHabitaciones;
    while(respuestaHabitaciones != "1" && respuestaHabitaciones != "2"){
        cout << "Ingresa una opcion valida:" << endl;
        cin >> respuestaHabitaciones;
    }
    if(respuestaHabitaciones == "1"){
        bool habitacionLibre = false;
        int iHabitacionLibre;
        for(int i = 0; i < NUMBER_OF_ROOMS; i++){
            if(rooms[i].getGuestName() == ""){
                habitacionLibre = true;
                iHabitacionLibre = i;
            }
        }
        if(habitacionLibre){
                cout << "Hay una habitacion libre" << endl;
                cout << "Ingrese el nombre a registrar en la reservacion: ";
                string tempGN;
                cin >> tempGN;
                cout << "Ingrese una contrasena para accesar a la reservacion: ";
                string tempGP;
                cin >> tempGP;
                rooms[iHabitacionLibre].setGuestName(tempGN);
                rooms[iHabitacionLibre].setGuestPassword(tempGP);
                cout << "Reservacion exitosa" << endl;
        }
        else{
            cout << "No hay habitaciones disponibles" << endl;
        }
    }
    else{
        cout << "Cancelacion de habitaciones" << endl;
        cout << "Ingrese el nombre exacto de la reservacion a cancelar: ";
        string tempNameCancel;
        cin >> tempNameCancel;
        bool coincidencia = false;
        int cuartoBuscado;
        for(int i = 0; i < NUMBER_OF_ROOMS; i++){
            if(rooms[i].getGuestName() == tempNameCancel){
                coincidencia = true;
                cuartoBuscado = i;

            }
        }
        if(coincidencia){
            cout << "Usuario encontrado, ingrese su contrasena: ";
            string tempPassCancel;
            cin >> tempPassCancel;
            if(rooms[cuartoBuscado].getGuestPassword() == tempPassCancel){
                cout << "Cancelacion exitosa" << endl;
                rooms[cuartoBuscado].setGuestName("");
                rooms[cuartoBuscado].setGuestPassword("");
            }
            else{
                cout << "Contrasena incorrecta, cancelacion abortada" << endl;
            }
        }
        else{
            cout << "No hay informacion que coincida, no se puede cancelar" << endl;
        }
    }
}

//Getters
string Airport::getId(){
    return ident;
}
string Airport::getDate(){
    return date;
}
string Airport::getCity(){
    return city;
}
string Airport::getCountry(){
    return country;
}
Airline Airport::getAirlineByIndex(int index){
    return airlines[index];
}

//Setters
void Airport::setId(string tempId){
    ident = tempId;
}
void Airport::setDate(string tempDate){
    date = tempDate;
}
void Airport::setCity(string tempCity){
    city = tempCity;
}
void Airport::setCountry(string tempCountry){
    country = tempCountry;
}

//Imprime la linea de formato
void Airport::lineaFormato(){
    cout << "----------------------------------" << endl;
}
