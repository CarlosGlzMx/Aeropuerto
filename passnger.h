#ifndef PASSNGER_H_INCLUDED
#define PASSNGER_H_INCLUDED
#include <iostream>
using namespace std;

class Passenger{
    private:
        string name;
        string phone;
    public:
        Passenger();
        //Getters
        string getName();
        string getPhone();
        //Setters
        void setName(string);
        void setPhone(string);
};

#endif // PASSNGER_H_INCLUDED
