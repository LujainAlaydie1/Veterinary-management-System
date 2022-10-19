#include <iostream>
#include <cstdio>
#include<algorithm>
#include<iomanip>
#include<conio.h>
#include<cstdlib>
#include<windows.h>
#include<stdio.h>
#include<fstream>
#include <limits>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include "Customer.h"
#include "Node.h"

// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;


// Stores the head of the Linked List
Node* head = new Node();

// Check Function to check that if
// Record Already Exist or Not
bool Customer::check(int x)
{
    // Base Case
    if (head == NULL)
        return false;

    Node* t = new Node;
    t = head;

    // Traverse the Linked List
    while (t != NULL) {
        if (t->Customer_ID == x)
            return true;
        t = t->next;
    }

    return false;
}

// Function to insert the record
void Customer::Add_Customer( string Customer_Name, int Customer_ID,
    string Breed, string Details_of_Pet, string Remarks, string Records)
{
    // if Record Already Exist
    if (check(Customer_ID)) {
        cout << "This Customer Record Already Exists\n";
        return;
    }

    // Create new Node to Insert Record
    Node* t = new Node();
    t->Customer_Name = Customer_Name;
    t->Customer_ID = Customer_ID;
    t->Breed = Breed;
    t->Details_of_Pet = Details_of_Pet;
    t->Remarks = Remarks;
    t->Records = Records;
    t->next = NULL;

    // Insert at Begin
    if (head == NULL
        || (head-> Customer_ID >= t-> Customer_ID)) {
        t->next = head;
        head = t;
    }

    // Insert at middle or End
    else {
        Node* c = head;
        while (c->next != NULL
               && c->next->Customer_ID < t->Customer_ID) {
            c = c->next;
        }
        t->next = c->next;
        c->next = t;
    }

    cout << "Record Inserted "
         << "Successfully\n";
         saveFile();
}

void Customer::editmenu( string Customer_Name, int Customer_ID,
    string Breed, string Details_of_Pet, string Remarks, string Records, Node* p)
		{
			system("cls");
			cout<<"\nWhat do you want to edit";
		   	cout<<"\n1. Customer Name ";
		   	cout<<"\n2. Customer ID ";
		   	cout<<"\n3. Pet's 'Breed ";
		   	cout<<"\n4. Pet's Details' ";
		   	cout<<"\n5. Comment ";
		   	cout<<"\n6. Quit ";
		   	cout<<"\nChoose your options here ---->>>  ";
	       int Option;

	cin >> Option;
	    if( Option ==1){

		cout<<"\nCurrent Customer's Name is "<<Customer_Name;
		fflush(stdin);
		cout<<"\nEnter New Customer's Name : ";
		getline(cin, Customer_Name);
        p->Customer_Name = Customer_Name;
            saveFile();

}
 else if (Option ==2){
	   cout<<"\nCurrent Customer ID is "<<Customer_ID;
	   fflush(stdin);
	   cout<<"\nEnter New Customer ID : ";
	   cin>>Customer_ID;
       p->Customer_ID = Customer_ID;
     saveFile();

}
	else if (Option ==3){
		cout<<"\nCurrent Pet's Breed is "<<Breed;
		fflush(stdin);
		cout<<"\nEnter New Pet's Breed : ";
		cin>>Breed;
        p->Breed = Breed;
        saveFile();

}
else if (Option ==4){
		cout<<"\nCurrent Details Of Pet is "<<Details_of_Pet;
		fflush(stdin);
		cout<<"\nEnter New Details Of Pet : ";
		getline(cin,Details_of_Pet);
        p->Details_of_Pet = Details_of_Pet;
    saveFile();

}
else if (Option ==5){
		 fflush(stdin);
		cout<<"\nCurrent Comments From The Vet is "<<Remarks;
		cout<<"\nEnter New Comments From The Vet : ";
		getline(cin,Remarks);
        p->Remarks = Remarks;
    saveFile();

}
					}


 void Customer::editRecord ( string Customer_Name, int Customer_ID,string Breed, string Details_of_Pet, string Remarks, string Records)
 {
        int edited = 0;
    // if head is NULL
    if (!head) {
        cout << "No such Record "
             << "Available\n";
        return;
    }
    else {
    Node* p = head;
        while (p) {
            if (p->Customer_ID == Customer_ID) {

			cout<<"\n			   EDIT			        	";
			cout<<"\n---------------------------------------";
			cout<<"\n";
			fflush(stdin);
			cout<<"\nEnter Customer ID : ";
			cin>> Customer_ID; {
			    editmenu( Customer_Name, Customer_ID, Breed, Details_of_Pet, Remarks, Records, p);
                edited = 1;
			}
			} else{
				cout<<"Please try again"<<endl;
			}
           p = p->next;
        }

        if (edited == 0)
            cout << "No such Record "
                 << "Available\n";
    }
		}

 void Customer::saveFile()
 {
    Node* p = head;
    ofstream myfile ("save.txt");

    while (p) {
        if (myfile.is_open())
        {
            myfile << p->Customer_Name << "\n";
            myfile << p->Customer_ID << "\n";
            myfile << p->Breed << "\n";
            myfile << p->Details_of_Pet << "\n";
            myfile << p->Remarks << "\n";
            myfile << p->Records << "\n";
        }
        else cout << "Unable to open file";
        p = p->next;
    }
    myfile.close();

    return;
}
void Customer::readFile()
{
    Node* p = head;
    ifstream MyReadFile("save.txt");
    int column = 0;
    string myText;
    while (getline (MyReadFile, myText)) {
        if (column == 0)
        {
            p->Customer_Name = myText;
            cout << "a";
            column++;
        }
        else if (column == 1)
        {
            p->Customer_ID = stoi(myText);
            cout << "b";
            column++;
        }
        else if (column == 2)
        {
            p->Breed = myText;
            cout << "c";
            column++;
        }
        else if (column == 3)
        {
            p->Details_of_Pet = myText;
            cout << "d";
            column++;
        }
        else if (column == 4)
        {
            p->Remarks = myText;
            cout << "e";
            column++;
        }
        else if (column == 5)
        {
            p->Records = myText;
            cout << "f";
            column = 0;
            p = p->next;
        }

    }
    MyReadFile.close();
return;
}



// Function to search record for any
// customer Record with contact number
void Customer::Search_Record(int Customer_ID)
{
    // if head is NULL
    if (!head) {
        cout << "No such Record "
             << "Available\n";
        return;
    }

    // Otherwise
    else {
        Node* p = head;
        while (p) {
            if (p->Customer_ID == Customer_ID) {

                cout << "Customer Name              : \t"
                     << p-> Customer_Name  << endl;
                cout << "Customer ID                : \t"
                     << p-> Customer_ID    << endl;
                cout << "Pet's Breed                : \t"
                     << p-> Breed          << endl;
                cout << "Pet's details              : \t"
                     << p-> Details_of_Pet << endl;
                cout << "Comments from the Vet      : \t"
                     << p-> Remarks        << endl;
                cout << "Last Visit Of The Customer : \t"
                     << p-> Records        << endl;
                return;
            }
            p = p->next;
        }

        if (p == NULL)
            cout << "No such Record "
                 << "Available\n";
    }
}

// Function to delete customer record
// record with given contact number
// if it exist
int Customer::Delete_Record(int Customer_ID)
{
    Node* t = head;
    Node* p = NULL;

    // Deletion at Begin
    if (t != NULL
        && t->Customer_ID == Customer_ID)
		{
        head = t->next;
        delete t;

        cout << "Details Deleted "
             << "Successfully\n";
            saveFile();
        return 0;
    }

    // Deletion Other than Begin
    while (t != NULL && t->Customer_ID != Customer_ID) {
        p = t;
        t = t->next;
    }
    if (t == NULL) {
        cout << "Record does not Exist\n";
        return -1;
        p->next = t->next;

        delete t;
        cout << "Details Deleted "
             << "Successfully\n";

        return 0;
    }
    saveFile();
}

// Function to display the Customer's
// Record
void Customer::displayRecord()

{
    Node* p = head;
    if (p == NULL) {
        cout << "No Record "
             << "Available\n";
    }

    else {

    	system("cls");
 cout << "||======================|===============|=============|==================|===============| ===================|\n";
        cout << "||  Customer Name  | Customer ID | Pet's Breed |     Pet Name     |      Commets   |     Last Visit    |\n";
        // Until p is not NULL
        while (p != NULL) {
          cout  << p -> Customer_Name  << " | \t"
                << p -> Customer_ID    << " | \t"
                << p -> Breed          << " | \t"
                << p -> Details_of_Pet << " | \t"
                << p -> Remarks        << " | \t"
                << p -> Records        << endl;
            p = p ->next;


        }
    }
}
void Customer::insert(){
    Customer c;
        string Customer_Name, Breed, Details_of_Pet, Remarks, Records;
    int Customer_ID;



             cout<<"\t\t\t\t||======================================================================||\n";
    cout<<"\t\t\t\t||======================================================================||+\n";
    cout<<"\t\t\t\t||  ||                         V E T E R I N A R Y                  ||  ||\n";
    cout<<"\t\t\t\t||==||                    M A N A G E M E N T S Y T E M             ||==||\n";
    cout<<"\t\t\t\t||  ||                           Enter Customer's Name:             ||  ||\n";
   cout<<"\t\t\t\t||   ||                                     ";
            cin >> Customer_Name;
                        fflush(stdin);

    cout<<"\t\t\t\t||  ||                      Enter Customer ID :                     ||  ||\n";
   cout<<"\t\t\t\t||   ||                                     ";
            cin>>Customer_ID;
                        fflush(stdin);

    cout<<"\t\t\t\t||  ||                      Pet's Breed :                           ||  ||\n";
    cout<<"\t\t\t\t||  ||                                      ";
            cin>> Breed;
                        fflush(stdin);

    cout<<"\t\t\t\t||  ||                      Pet's Name:                             ||  ||\n";
    cout<<"\t\t\t\t||  ||                                      ";
            getline(cin,Details_of_Pet);
                fflush(stdin);

    cout<<"\t\t\t\t||  ||                      Comments From The Vet:                  ||  ||\n";
    cout<<"\t\t\t\t||  ||                                      ";
            getline(cin,Remarks);
                fflush(stdin);
    cout<<"\t\t\t\t||  ||          Last Visit Of The Customer (dd/mm/yyyy) :           ||  ||\n";
    cout<<"\t\t\t\t||  ||                                      ";
                cin>> Records;
                fflush(stdin);
    cout<<"\t\t\t\t||======================================================================||\n";
    cout<<"\t\t\t\t||======================================================================||\n";


            c.Add_Customer(Customer_Name, Customer_ID, Breed, Details_of_Pet, Remarks, Records);
}

void Customer::edit(){
    Customer c;
     head = NULL;
    string Customer_Name, Breed, Details_of_Pet, Remarks, Records;
    int Customer_ID;
    c.displayRecord();
      cout << "Enter Customer ID of Customer whose "
                "record you want to Edit\n";
                cin >>Customer_ID;


             cout<<"\t\t\t\t||======================================================================||\n";
    cout<<"\t\t\t\t||======================================================================||+\n";
    cout<<"\t\t\t\t||  ||                         V E T E R I N A R Y                  ||  ||\n";
    cout<<"\t\t\t\t||==||                    M A N A G E M E N T S Y T E M             ||==||\n";
    cout<<"\t\t\t\t||  ||                           Enter Customer's Name:             ||  ||\n";
   cout<<"\t\t\t\t||   ||                                     ";
            cin >> Customer_Name;
                        fflush(stdin);

    cout<<"\t\t\t\t||  ||                      Enter Customer ID :                     ||  ||\n";
   cout<<"\t\t\t\t||   ||                                     ";
            cin>>Customer_ID;
                        fflush(stdin);

    cout<<"\t\t\t\t||  ||                      Pet's Breed :                           ||  ||\n";
    cout<<"\t\t\t\t||  ||                                      ";
            cin>> Breed;
                        fflush(stdin);

    cout<<"\t\t\t\t||  ||                      Pet's Name:                             ||  ||\n";
    cout<<"\t\t\t\t||  ||                                      ";
            getline(cin,Details_of_Pet);
                fflush(stdin);

    cout<<"\t\t\t\t||  ||                      Comments From The Vet:                  ||  ||\n";
    cout<<"\t\t\t\t||  ||                                      ";
            getline(cin,Remarks);
                fflush(stdin);
    cout<<"\t\t\t\t||  ||          Last Visit Of The Customer (dd/mm/yyyy) :           ||  ||\n";
    cout<<"\t\t\t\t||  ||                                      ";
                cin>> Records;
                fflush(stdin);
    cout<<"\t\t\t\t||======================================================================||\n";
    cout<<"\t\t\t\t||======================================================================||\n";

      c.editRecord(Customer_Name, Customer_ID, Breed, Details_of_Pet, Remarks, Records);
    
}

