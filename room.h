#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED
#include <iostream>
using namespace std;

class Room{
    private:
        string guestName;
        string guestPassword;
    public:
        Room();
        void setGuestName(string);
        void setGuestPassword(string);
        string getGuestName();
        string getGuestPassword();
};


#endif // ROOM_H_INCLUDED
