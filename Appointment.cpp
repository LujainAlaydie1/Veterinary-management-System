#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
#include <vector>

#include "Appointment.h"
using namespace std;
string convertToString(char* a, int size){
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

   struct Appointments::NewAppt{
    char AppointmentNumberr[10];
    double AppointmentNumber;
    char CustomerName [30];
    char CustomerID [10] ;
    char PetName [30];
    char PetID [10];
    };

   void Appointments:: insert(){
   NewAppt newAppt;
   int flag=0;
   ofstream file;
   file.open("Appointments.txt",std::ios_base::app);
   do{
    cout<<"\t\t\t\t||======================================================================||\n";
    cout<<"\t\t\t\t||======================================================================||+\n";
    cout<<"\t\t\t\t||  ||                         V E T E R I N A R Y                  ||  ||\n";
    cout<<"\t\t\t\t||==||                    M A N A G E M E N T S Y T E M             ||==||\n";
    cout<<"\t\t\t\t||  ||                   Enter The New Appointment Number :         ||  ||\n";
   cout<<"\t\t\t\t||   ||                                     ";
       cin>>newAppt.AppointmentNumber;
    cout<<"\t\t\t\t||  ||                      Enter The Customer's Name:              ||  ||\n";
   cout<<"\t\t\t\t||   ||                                     ";
       cin>>newAppt.CustomerName;
    cout<<"\t\t\t\t||  ||                      Enter The Customer's ID:                ||  ||\n";
    cout<<"\t\t\t\t||  ||                                      ";
        cin>>newAppt.CustomerID;
    cout<<"\t\t\t\t||  ||                      Enter The Pet's Name :                  ||  ||\n";
    cout<<"\t\t\t\t||  ||                                      ";
    cin>>newAppt.PetName;
    cout<<"\t\t\t\t||  ||                      Enter The Pet's ID :                    ||  ||\n";
    cout<<"\t\t\t\t||  ||                                      ";
    cin>>newAppt.PetID;
    cout<<"\t\t\t\t||======================================================================||\n";
    cout<<"\t\t\t\t||======================================================================||\n";

     file<<newAppt.AppointmentNumber<<"|"<<newAppt.CustomerName<<"|"<<newAppt.CustomerID<<"|"<<newAppt.PetName<<"|"<<newAppt.PetID<<endl;
    cout<<"	PRESS (0) TO FINISH INSERT DATA OR PRESS ANY KEY TO COUNTINE \n\n";
    cin>>flag;
     }
     while(flag!=0);
 	file.close();
 }

    void Appointments::view(){
        NewAppt newAppt;
        system("cls");
        fstream file;
        file.open("Appointments.txt", ios::in | ios::out | ios::app);
        cout << "||======================|===============|=============|==================|===============||\n";
        cout << "||  Appointment Number  | Customer Name | Customer ID |     Pet Name     |      Pet ID   ||\n";
        while (!file.eof())
        {
        cout << "||----------------------|---------------|-------------|------------------|---------------||\n";

            file.getline(newAppt.AppointmentNumberr , 100 , '|') ;
            file.getline(newAppt.CustomerName, 100 , '|');
            file.getline(newAppt.CustomerID , 100 , '|');
            file.getline(newAppt.PetName , 100 , '|');
            file.getline(newAppt.PetID , 100 , '\n') ;

            cout <<setw(8)<< newAppt.AppointmentNumberr <<setw(24) << newAppt.CustomerName <<setw(20)<< newAppt.CustomerID <<setw(16)<< newAppt.PetName<<setw(15)<<newAppt.PetID<<endl;

        }
        cout << "||============================================================================|||\n";
        file.close();
        cin.ignore();
        cin.ignore();

    }

        int Appointments::binarySearch(vector<NewAppt> p, int l, int r, double x){
        while (l <= r) {
        int m = l + (r - l) / 2;
         if (p[m].AppointmentNumber == x)
            return m;
         if (p[m].AppointmentNumber < x)
            l = m + 1;

        else
            r = m - 1;


    }
    return -1;
    }
    void Appointments::appbinarySearch(){
        fstream file;
        vector <NewAppt> newAppt;
        NewAppt sorttemp;
        NewAppt temp;
        int counter = 0;
        file.open("Appointments.txt" , ios::in);
        while (true)
        {

            file.getline(temp.AppointmentNumberr , 100 , '|') ;
            file.getline(temp.CustomerName, 100 , '|');
            file.getline(temp.CustomerID , 100 , '|');
            file.getline(temp.PetName , 100 , '|');
            file.getline(temp.PetID , 100 , '\n') ;
            temp.AppointmentNumber = atof(temp.AppointmentNumberr);
            newAppt.push_back(temp);


            if (file.eof())
                break;
            else
                counter++;
        }
        file.close();
        int w;

        ///////////////////////// Sorting ///////////////
        int i , j ;
        for(i=0; i<counter+1; ++i)
        {
            for(j=0; j <= counter+1 ; ++j)
                if(newAppt[i].AppointmentNumber <newAppt[j].AppointmentNumber)
                {
                    sorttemp=newAppt[i];
                    newAppt[i]=newAppt[j];
                    newAppt[j]=sorttemp;

                }
        }
for(w=0; w < newAppt.size(); w++)
        cout<<"\t\t\t\t||  ||                         "<<newAppt[w].AppointmentNumberr<<"                                 ||  ||\n"<<endl;
        cout << "Enter the appointment number :" <<endl;
        double number;
        cin >> number ;
        while (true)
        {
            if (cin.fail() ||  number <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "please Enter a Valid Number :" << endl;
                cin >> number ;
            }
            else break;
        }
        int posetion = binarySearch( newAppt, 0 , counter , number);
        if ( posetion != -1 ){

           cout<<"\t\t\t\t||======================================================================||\n";
    cout<<"\t\t\t\t||======================================================================||+\n";
    cout<<"\t\t\t\t||  ||                         V E T E R I N A R Y                  ||  ||\n";
    cout<<"\t\t\t\t||==||                    M A N A G E M E N T S Y T E M             ||==||\n";
    cout<<"\t\t\t\t||  ||                   Appointment Number:"<<newAppt[posetion].AppointmentNumberr<<endl;;
    cout<<"\t\t\t\t||  ||                      Customer Name: "<< newAppt[posetion].CustomerName << endl;
    cout<<"\t\t\t\t||  ||                      Customer ID: " << newAppt[posetion].CustomerID << endl;
    cout<<"\t\t\t\t||  ||                      Pet Name: " << newAppt[posetion].PetName << endl;
    cout<<"\t\t\t\t||  ||                      Pet ID : "<< newAppt[posetion].PetID << endl;
    cout<<"\t\t\t\t||======================================================================||\n";
    cout<<"\t\t\t\t||======================================================================||\n";
        }else cout << "=====================Not Found====================="<<endl;
        cin.ignore();
        cin.ignore();
        return;

    }

    void Appointments::updatieng (double number ,int x){
        fstream file;
        system("cls");
        fstream file1;
        file.open("Appointments.txt" , ios::in | ios::out | ios::app);
        file1.open("Update.txt" ,  ios::out);
        int flag = 0;

        NewAppt newAppt;
        while (!file.eof())
        {
            file.getline(newAppt.AppointmentNumberr , 100 , '|') ;
            file.getline(newAppt.CustomerName, 100 , '|');
            file.getline(newAppt.CustomerID , 100 , '|');
            file.getline(newAppt.PetName , 100 , '|');
            file.getline(newAppt.PetID , 100 , '\n') ;
            file1.seekg(0 , ios::end);

            if (strtod(newAppt.AppointmentNumberr,NULL) != number && strlen(newAppt.AppointmentNumberr)!=0)
            {
                if(file1.tellp() == 0)
                    file1  << newAppt.AppointmentNumberr<< "|" <<newAppt.CustomerName<< "|" << newAppt.CustomerID << "|" << newAppt.PetName << "|" << newAppt.PetID;
                else
                    file1  << newAppt.AppointmentNumberr<< "|" <<newAppt.CustomerName<< "|" << newAppt.CustomerID << "|" << newAppt.PetName << "|" << newAppt.PetID;

            }
            else if (strlen(newAppt.AppointmentNumberr)==0){}
            else
            {


                fstream file;
                file.open( "Appointments.txt" , ios::in | ios::out | ios::app );

                if(file1.tellp() == 0)

                file1  << newAppt.AppointmentNumberr<< "|" <<newAppt.CustomerName<< "|" << newAppt.CustomerID << "|" << newAppt.PetName << "|" << newAppt.PetID;
                else
                    file1  << newAppt.AppointmentNumberr<< "|" <<newAppt.CustomerName<< "|" << newAppt.CustomerID << "|" << newAppt.PetName << "|" << newAppt.PetID;




            }

        }
        file.close();
        file1.close();
        remove("Appointments.txt");
        rename("Update.txt" , "Appointments.txt");
cin.ignore();

        }

        void Appointments::updating (){
        string temp;
        fstream file;
        system("cls");
        fstream file1;
        file.open("Appointments.txt" , ios::in | ios::out | ios::app);
        file1.open("Update.txt" ,  ios::out);
        int flag = 0;
        cout << "Enter Appointment Number You Want To Update :"<<endl;
        double number ;
        cin >> number ;

        while (true){
            if (cin.fail() ||  number <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "please Enter a Valid Number :" << endl;
                cin >> number ;
            }
            else break;
        }
        NewAppt newAppt;
        while (!file.eof())
        {
            file.getline(newAppt.AppointmentNumberr , 100 , '|') ;
            file.getline(newAppt.CustomerName, 100 , '|');
            file.getline(newAppt.CustomerID , 100 , '|');
            file.getline(newAppt.PetName , 100 , '|');
            file.getline(newAppt.PetID , 100 , '\n') ;

            if (strtod(newAppt.AppointmentNumberr,NULL) != number && strlen(newAppt.AppointmentNumberr)!=0)
            {
                if(file1.tellp() == 0)
                file1  << newAppt.AppointmentNumberr<< "|" <<newAppt.CustomerName<< "|" << newAppt.CustomerID << "|" << newAppt.PetName << "|" << newAppt.PetID;
                else
                file1  << newAppt.AppointmentNumberr<< "|" <<newAppt.CustomerName<< "|" << newAppt.CustomerID << "|" << newAppt.PetName << "|" << newAppt.PetID;

            }
            else if (strlen(newAppt.AppointmentNumberr)==0){}
            else
            {
                cout << "==> Found <==" << endl;
                cout << "NewAppt Number : " << newAppt.AppointmentNumberr<<endl;
                cout << "Customer Name : " << newAppt.CustomerName<<endl;
                cout << "Customer ID : " << newAppt.CustomerID<<endl;
                cout << "Pet Name : " << newAppt.PetName<<endl;
                cout << "Pet ID : " << newAppt.PetID<<endl;
                cout << " Now you will Update this Data"<<endl;
                NewAppt previous;
tt :
                previous.AppointmentNumber = strtod(previous.AppointmentNumberr,NULL);
                fstream file;
                file.open( "Appointments.txt" , ios::in | ios::out | ios::app );
                int i = 0 ;
                while (true)
                {
                    cout << "Enter a new NewAppt number :"<<endl;
                    cin >> previous.AppointmentNumberr;
                    while (true)
                    {
                        if (cin.fail() ||  previous.AppointmentNumberr<= 0)
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout << "please Enter a Valid number :" << endl;
                            cin >> previous.AppointmentNumberr ;
                        }
                        else break;
                    }
                     if (previous.AppointmentNumber == newAppt.AppointmentNumber){
                    NewAppt newAppt;

                    while (!file.eof())
                    {
            file.getline(newAppt.AppointmentNumberr , 100 , '|') ;
            file.getline(newAppt.CustomerName, 100 , '|');
            file.getline(newAppt.CustomerID , 100 , '|');
            file.getline(newAppt.PetName , 100 , '|');
            file.getline(newAppt.PetID , 100 , '\n') ;
                        if (previous.AppointmentNumber == newAppt.AppointmentNumber)
                            i = 1;

                    }

                    }
                    if (i == 1 )
                    {
                        cout <<"This Number Already Exists .... \n";
                        goto tt;
                    }
                    else break;

                }
                cin.ignore();

        cout << "Enter NEW Customer Name : ";
        cin>>previous.CustomerName;
        fflush(stdin);
        cout << "Enter NEW CUSTOMER ID : ";
        cin>>previous.CustomerID;
        fflush(stdin);
        cout << "Enter NEW PET NAME : ";
        cin>>previous.PetName;
        fflush(stdin);
        cout << "Enter NEW PET ID : ";
        cin >> previous.PetID;

                if(file1.tellp() == 0)
                {
                file1  << previous.AppointmentNumberr<< "|" <<previous.CustomerName<< "|" << previous.CustomerID << "|" << previous.PetName << "|" << previous.PetID;
                }
                else
                {
                file1  << previous.AppointmentNumberr<< "|" <<previous.CustomerName<< "|" << previous.CustomerID << "|" << previous.PetName << "|" << previous.PetID;
                }
                system("cls");
                cout << "==> Updated Successfully <=="<<endl;
                flag = 1;
            }
        }
        file.close();
        file1.close();
        remove("Appointments.txt");
        rename("Update.txt" , "Appointments.txt");
        if (!flag)
            cout <<" ==> Not Found <== " <<endl;
        cout << "\n \n \n \n \n "<<endl;
        cout << "press (Y/y) if you want to update another aspect \ any thing else if you want to continue.   ";
                char ch;
                fflush(stdin);
                cin >> ch;
                if (ch == 'y' || ch == 'Y')
                    updating();

    }

    void Appointments::deleteing (){
        fstream file;
        system("cls");
        fstream file1;
        file.open("Appointments.txt" , ios::in | ios::out | ios::app);
        file1.open("delete.txt" ,  ios::out);
        int flag = 0;
        int deleted = 0;
        cout << "Enter The Appointment Number For The Appointment You Want To Delete :"<<endl;
        double number;
        cin >> number;
        while (true)
        {
            if (cin.fail() ||  number <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "please Enter a Valid Appointment Number :" << endl;
                cin >> number;
            }
            else break;
        }
        NewAppt newAppt;
        while (!file.eof())
        {

            file.getline(newAppt.AppointmentNumberr , 100 , '|') ;
            file.getline(newAppt.CustomerName, 100 , '|');
            file.getline(newAppt.CustomerID , 100 , '|');
            file.getline(newAppt.PetName , 100 , '|');
            file.getline(newAppt.PetID , 100 , '\n') ;;
            file1.seekg(0 , ios::end);
            if (strtod(newAppt.AppointmentNumberr,NULL) != number)
            {
                if(file1.tellp() == 0)
                    file1  << newAppt.AppointmentNumberr<< "|" <<newAppt.CustomerName<< "|" << newAppt.CustomerID << "|" << newAppt.PetName << "|" << newAppt.PetID;
                else
                    file1 <<"\n"<< newAppt.AppointmentNumberr<< "|" <<newAppt.CustomerName<< "|" << newAppt.CustomerID << "|" << newAppt.PetName << "|" << newAppt.PetID;
            }
            else
            {
                flag = 1;
                deleted = 1;
            }
        }
        file.close();
        file1.close();
        remove("Appointments.txt");
        rename("delete.txt" , "Appointments.txt" );
        if (flag)
            cout << "==> Deleted <==" <<endl;
        else cout <<" ==> Not Found <==" <<endl;

    };
