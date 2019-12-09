#include <iostream>
#include "passnger.h"
using namespace std;

//Constructor
Passenger::Passenger(){
    name = "";
    phone = "";
}

//Getters
string Passenger::getName(){
    return name;
}
string Passenger::getPhone(){
    return phone;
}

//Setters
void Passenger::setName(string tempName){
    name = tempName;
}
void Passenger::setPhone(string tempPhone){
    phone = tempPhone;
}
