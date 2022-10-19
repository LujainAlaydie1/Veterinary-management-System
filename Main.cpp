#include <windows.h> // Beep function
#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>
#include <string>
#include <cstring>
#include "Appointment.h"
#include "Customer.h"

#include <stdlib.h>
#include <iomanip>
#include <vector>
using namespace std;


void titleCustmoer(){
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl ;
    cout<<"\t\t\t\t+=====================================================================+\n";
    cout<<"\t\t\t\t|                           C U S T O M E R                           |\n";
    cout<<"\t\t\t\t+=====================================================================+\n";
}

void titleAppt(){
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl ;
    cout<<"\t\t\t\t+=====================================================================+\n";
    cout<<"\t\t\t\t|                          A P P O I N T M E N T                      |\n";
    cout<<"\t\t\t\t+=====================================================================+\n";
}

void Welcome(){
    system ("Color 0F");
    Beep(261.626,250);
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl ;
    cout<<"\t\t\t\t||======================================================================||\n";
    cout<<"\t\t\t\t||======================================================================||+\n";
    cout<<"\t\t\t\t||  ||                         V E T E R I N A R Y                  ||  ||\n";
    cout<<"\t\t\t\t||==||                    M A N A G E M E N T S Y T E M             ||==||\n";
    cout<<"\t\t\t\t||  ||                           1. Appointments                    ||  ||\n";
    cout<<"\t\t\t\t||  ||                           2. Customers                       ||  ||\n";
    cout<<"\t\t\t\t||  ||                           3. Exit                            ||  ||\n";
    cout<<"\t\t\t\t||======================================================================||\n";
    cout<<"\t\t\t\t||======================================================================||\n";
    cout << "\n\t\t\t\t\t\t\tTo start";
    cout << "\n\n\t\t\t\t\tPlease Choose one : ";
}

void menuAppt(){
    Appointments app1;

apptAgain:
    char uname[30];

    system("cls");
    titleAppt();

    int choice = -1;
    int choice2 = -1;
    system ("Color 0F");
     cout<<"\t\t\t\t|======================================================================||\n";
    cout<<"\t\t\t\t|======================================================================||+\n";
    cout<<"\t\t\t\t|  ||                        1. Add Appointment                    ||  |\n";
    cout<<"\t\t\t\t|  ||                        2. Edit Appointment                   ||  |\n";
    cout<<"\t\t\t\t|  ||                        3. Delete Appointment                 ||  |\n";
    cout<<"\t\t\t\t|  ||                        4. View All Appointments              ||  |\n";
    cout<<"\t\t\t\t|  ||                        5. View by Appointment ID             ||  |\n";
    cout<<"\t\t\t\t|  ||                        6. Exit                               ||  |\n";
    cout<<"\t\t\t\t+=====================================================================+\n";
    cout<<"\t\t\t\t=======================================================================\n";
    cout << "\n\n\t\t\t\t\tSelect one : ";


    while(choice != 6){

        cin>>choice;
        //Add appt
        if(choice == 1){
            app1.insert();
            system("cls");
            titleAppt();
            system("PAUSE");
            goto apptAgain;
        }
        //Edit appt
        else if(choice == 2){
            char Mid[20];
            system("cls");
            titleAppt();
            app1.updating();
            goto apptAgain;
        }
        //Delete appt
        else if(choice == 3){
            char Mid[20];
            system("cls");
            titleAppt();
            app1.deleteing();
            system("PAUSE");
            goto apptAgain;
        }
        //View appt List
        else if(choice == 4){
            system("cls");
            titleAppt();
            app1.view();
            system("PAUSE");
            goto apptAgain;

        }
        //View appt List
        else if(choice == 5){
            system("cls");
            titleAppt();
            app1.appbinarySearch();
            system("pause");
            goto apptAgain;
        }
        //Exit
        else if(choice > 6 || choice <= 0){
            cout<<"\n\n\t\t\t\t\t\t\tThis selection does not exist.\n\n\t\t\t\t\t\t\t";
            system("pause");
            goto apptAgain;
        }
    }
}

void menuCust(){
    Customer cust;

CustAgain:
    char uname[30];

    system("cls");
    titleCustmoer();
    int customer_ID;

    int choice = -1;
    int choice2 = -1;
    system ("Color 0F");
     cout<<"\t\t\t\t|======================================================================||\n";
    cout<<"\t\t\t\t|======================================================================||+\n";
    cout<<"\t\t\t\t|  ||                        1. New Customer                       ||  ||\n";
    cout<<"\t\t\t\t|  ||                        2. Edit Customer                      ||  ||\n";
    cout<<"\t\t\t\t|  ||                        3. Delete Customer                    ||  ||\n";
    cout<<"\t\t\t\t|  ||                        4. View All Customer                  ||  ||\n";
    cout<<"\t\t\t\t|  ||                        5. View by Customer ID                ||  |\n";
    cout<<"\t\t\t\t|  ||                        6. Exit                               ||  |\n";
    cout<<"\t\t\t\t+=====================================================================+\n";
    cout<<"\t\t\t\t=======================================================================\n";
    cout << "\n\n\t\t\t\t\tSelect one : ";


    while(choice != 6){

        cin>>choice;

        //New cust
        if(choice == 1){
            system("cls");
            titleCustmoer();
            cust.insert();
            system("PAUSE");
            cust.saveFile();
            goto CustAgain;
        }
        //Edit cust
        else if(choice == 2){
            char Mid[20];
            system("cls");
            titleCustmoer();
            cust.edit();
                        cust.saveFile();

            goto CustAgain;
        }
        //Delete cust
        else if(choice == 3){
            char Mid[20];
            system("cls");
            titleCustmoer();
            cout << "Enter Customer ID of Customer whose "
                "record you want to Edit\n";
            cin >>customer_ID;
            cust.Delete_Record(customer_ID);
             cust.saveFile();

            system("PAUSE");
            goto CustAgain;
        }
        //View cust List
        else if(choice == 4){
            system("cls");
            titleCustmoer();
            cust.displayRecord();
            system("PAUSE");
            cust.saveFile();

            goto CustAgain;

        }
        //search cust List
        else if(choice == 5){
            system("cls");
            titleCustmoer();
            cout << "Enter Customer ID of Customer whose "
                    "record you want to Search\n";
            cin >> customer_ID;
            cust.Search_Record(customer_ID);
            system("pause");
            cust.saveFile();
            goto CustAgain;
        }
        //Exit
        else if(choice > 6 || choice <= 0){
            cout<<"\n\n\t\t\t\t\t\t\tThis selection does not exist.\n\n\t\t\t\t\t\t\t";
            system("pause");
            cust.saveFile();

            goto CustAgain;
        }
    }
}


void MainMenu(){

again:
    int choice = -1;
    system("cls");
    Welcome();

    while(choice != 3)
    {
        cin>>choice;
        //Appt
        if(choice == 1){
            system("cls");
            titleAppt();
            menuAppt();
            goto again;
        }
        //Customer
        else if(choice == 2){
            menuCust();
            goto again;

        }
        else if(choice >3 || choice <= 0){
            cout<<"\n\n\t\t\t\t\t\t\tThis selection does not exist.\n\n\t\t\t\t\t\t\t";
            system("pause");
            goto again;
        }
    }
    system("cls");
    system("Color 03");
    Beep(1200,200);
    Beep(1000,200);
    Beep(800,200);
    Beep(600,200);;
    Sleep(1000);
    cout<<"\n\n\t\t\t\t\t\tExit this Vet Management System.\n\n\t\t\t\t\t\t\t"<<endl;


}

int main(){
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1000,800 ,TRUE);
    Beep(600,200);
    Beep(800,200);
    Beep(1000,200);
    Beep(1200,200);
    MainMenu();
return 0;
}
