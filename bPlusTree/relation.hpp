//
// Project:    b_tree
// Filename:   relation.h
// Created on: 26.10.21
//
// Developer(s):
//    I) Artur Titkov
//
// Description:
//
//
//
//

#include <iostream>
#include <set>
#include "def.h"

#ifndef relation_h
#define relation_h

using namespace std;

struct Record{
    int id;
    float x;
    float y;
    int score;
    int price;
    
    Record();
    Record(int a);
    ~Record();
    void print();
    
};

struct Relation{
    int numRecords;
    Record* recs;
    
    
    Relation(int numRecs);
    ~Relation();
    Record& operator[](int i);
    void print();
};







#endif /* relation_h */
