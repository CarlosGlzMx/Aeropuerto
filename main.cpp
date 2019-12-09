/*
Programa que simula el funcionamiento de un dia de un aeropuerto con 3 aerolineas,
cada una con un máximo de 5 vuelos. Restringe los vuelos por horarios y permite
reservar habitaciones para dormir ahi, con un maximo posible de 10 habitaciones.
Autor: Carlos Gonzalez del Rosal
Fecha: 7 de diciembre de 2019
*/

#include <iostream>
#include "airline.h"
#include "airport.h"
#include "flight.h"
#include "passnger.h"
using namespace std;

int main()
{
    cout << "Inicio del sistema del aeropuerto" << endl;
    cout << "----------------------------------" << endl;
    cout << "Ingresa la fecha en formato dd/mm/aaaa: ";
    string fecha;
    cin >> fecha;
    Airport AICM(fecha);
    string menu = "";
    while(menu != "6"){
        cout << "Que deseas hacer con el sistema de aeropuertos?" << endl;
        cout << "1.Programar vuelos y reservar pasajeros" << endl;
        cout << "2.Mostrar todos los vuelos programados" << endl;
        cout << "3.Mostrar los ingresos de las aerolineas" << endl;
        cout << "4.Actualizar informacion de aerolinea" << endl;
        cout << "5.Ingresar al sistema de habitaciones" << endl;
        cout << "6.Cerrar sistema" << endl;
        cin >> menu;
        cout << "----------------------------------" << endl;
        if(menu == "1"){
            AICM.programFlightFromAirline();
        }
        else if(menu == "2"){
            AICM.printAllFilghts();
        }
        else if(menu == "3"){
            AICM.showAllIncomes();
        }
        else if(menu == "4"){
            AICM.updateAnAirline();
        }
        else if(menu == "5"){
            AICM.nightSystem();
        }
        else if(menu == "6"){
            AICM.closeOperations();
        }
        else{
            cout << "Introduce una opcion valida" << endl;
        }
        cout << "----------------------------------" << endl;
    }
    return 0;
}
