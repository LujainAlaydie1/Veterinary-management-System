#ifndef NODE_H
#define NODE_H
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
class Node{
public:
    std::string Customer_Name;
    int Customer_ID;
    std::string Breed;
    std::string Details_of_Pet;
    std::string Remarks;
    std::string Records;
    Node* next;
};


#endif
