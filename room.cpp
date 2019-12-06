#include "room.h"
#include <iostream>
using namespace std;

Room::Room(){
    guestName = "";
    guestPassword = "";
}
void Room::setGuestName(string tempGN){
    guestName = tempGN;
}
void Room::setGuestPassword(string tempGP){
    guestPassword = tempGP;
}
string Room::getGuestName(){
    return guestName;
}
string Room::getGuestPassword(){
    return guestPassword;
}
