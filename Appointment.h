#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
#include <vector>
using namespace std;


 string convertToString(char* a, int size);
class Appointments{
    private :
        struct NewAppt;

    public :
    //functions
        void insert();
        void view();
        void appbinarySearch();
        void updating (double ,int );
        int binarySearch(vector<NewAppt> , int , int , double );
        void updating ();
        void updatieng (double ,int);
        void deleteing ();


    };
#endif
