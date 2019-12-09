#include "room.h"
#include <iostream>
using namespace std;

//Constructor
Room::Room(){
    guestName = "";
    guestPassword = "";
}

//Setters
void Room::setGuestName(string tempGN){
    guestName = tempGN;
}
void Room::setGuestPassword(string tempGP){
    guestPassword = tempGP;
}
//Getters
string Room::getGuestName(){
    return guestName;
}
string Room::getGuestPassword(){
    return guestPassword;
}
