#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <cstdio>
#include<string>
#include<algorithm>
#include<iomanip>
#include<conio.h>
#include<cstdlib>
#include<windows.h>
#include<stdio.h>
#include<fstream>
#include <cstring>
#include <limits>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include "Node.h"
using namespace std;
class Customer{
    public:
bool check(int x);

void Add_Customer( string Customer_Name, int Customer_ID,
    string Breed, string Details_of_Pet, string Remarks, string Records);

void editmenu( string Customer_Name, int Customer_ID,
    string Breed, string Details_of_Pet, string Remarks, string Records, Node* p);

void editRecord ( string Customer_Name, int Customer_ID,
    string Breed, string Details_of_Pet, string Remarks, string Records);

void saveFile();

void readFile();

void Search_Record(int Customer_ID);

int Delete_Record(int Customer_ID);

void displayRecord();
void insert();
void edit();
};
#endif
