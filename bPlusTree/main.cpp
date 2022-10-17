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
#include "bPlusTree.hpp"
#include <iostream>
#include <format>
#include <chrono>
#include <iostream>


#include "def.h"


int main(int argc, const char * argv[]) {
    
    
    Relation r = Relation(10);
    

    
    
    bPlusTree tree(4);
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(25);
    
//    LeafNode* leaf = (LeafNode*)tree.root;
    LeafNode* tmp = (LeafNode*)tree.root;

//    fori(tmp->usedKeys){
//        println(tmp->keys[i]);
//    }
    

    println("\n\n\n\n");
    return 0;
}
