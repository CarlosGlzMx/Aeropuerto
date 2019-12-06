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
    while(menu != "5"){
        cout << "Que deseas hacer con el sistema de aeropuertos?" << endl;
        cout << "1.Programar vuelos y reservar pasajeros" << endl;
        cout << "2.Mostrar todos los vuelos programados" << endl;
        cout << "3.Mostrar los ingresos de las aerolineas" << endl;
        cout << "4.Actualizar informacion de aerolinea" << endl;
        cout << "5.Cerrar sistema" << endl;
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
            AICM.closeOperations();
        }
        else{
            cout << "Introduce una opcion valida" << endl;
        }
        cout << "----------------------------------" << endl;
    }
    return 0;
}
