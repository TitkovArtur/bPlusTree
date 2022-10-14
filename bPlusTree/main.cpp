//
// Project:    b_tree
// Filename:   main.cpp
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
#include "relation.hpp"
#include "BPlusTree.hpp"
#include <iostream>
#include "def.h"

int main(int argc, const char * argv[]) {
    
    
    Relation r = Relation(10);
    r.printRelation();
    
    
    Record* a = new Record(10);
    Record* b = new Record(20);
    Record* c = new Record(15);
    Record* d = new Record(5);
    
    BPlusTree tree(4);
    LeafNode* leaf = (LeafNode*)tree.root;
    
    
    
    return 0;
}
