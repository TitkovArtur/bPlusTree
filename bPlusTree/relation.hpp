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
    
    Record(){
        id = -1;
        x = -1;
        y = -1;
        score = -1;
        price = -1;
    }
    Record(int a){
        id = a;
        x = -1;
        y = -1;
        score = -1;
        price = -1;
    }
};

struct Relation{
    int numRecords;
    Record* recs;
    
    
    Relation(int numRecs){ // generates numRecs random records
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
    }
    
    void printRelation(){
        for(int i = 0; i < numRecords; i++){
            Record* r = &recs[i];
            cout << "ID: " << r->id
                << " (" << r->x << ", " << r->y << ") "
                << " Score " << r->score
                << " Price " << r->price
                << endl;
        }
    }
    
    
    
};







#endif /* relation_h */
