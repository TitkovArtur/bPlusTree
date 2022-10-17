//
// Project:    bPlusTree
// Filename:   relation.cpp
// Created on: 14.10.22
//
// Developer(s):
//	I) Artur Titkov
//	   ArturTitkov@icloud.com
//	   https://github.com/TitkovArtur
//
// Description:
//
//
// 
//

#include "relation.hpp"
#include "def.h"


Record::Record(){
    id = -1;
    x = -1;
    y = -1;
    score = -1;
    price = -1;
};

Record::Record(int a){
    id = a;
    x = -1;
    y = -1;
    score = -1;
    price = -1;
};

Record::~Record(){
//    println("---> Rec destructor");
}


inline void Record::print() {
    printf("%6i|(%8f,%8f)|%6i|%6i|\n", id, x,y,score,price);
};

Relation::Relation(int numRecs){ // generates numRecs random records
    numRecords = numRecs;
    recs = new Record[numRecs];
    int counter = 0;
    int minKey = numRecs*100;
    int keyRange = numRecs*1000 - minKey;
    set<int> s;
    
    while(s.size() != numRecs){
        int newKey = (rand() % keyRange) + minKey;
        if(s.find(newKey) != s.end()) continue;
        s.insert(newKey);
        
        recs[counter].id    = newKey;
        recs[counter].x     = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        recs[counter].y     = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        recs[counter].score = (rand() % 10) + 1;
        recs[counter].price = (rand() % 1901) + 100;

        counter++;
        
    }
};
Relation::~Relation(){
    println("--> Relation destructor");
    delete[] recs;
}

Record& Relation::operator[](int i) {
    if(i >= numRecords){
        println("out of range");
        return recs[0];
    }
    else
        return recs[i];
}

void Relation::print(){
    printf("%6s|(%8s,%8s)|%6s|%6s|\n", "id", "x","y","score","price");
    fori(numRecords){
        recs[i].print();
    }
}



