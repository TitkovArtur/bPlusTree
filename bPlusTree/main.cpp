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
    tree.insert(50);
    tree.insert(60);
//    tree.insert(11);
//    tree.insert(12);
//    tree.insert(13);
    
    tree.print();
//
    LeafNode* leaf;
    InnerNode* tmp = (InnerNode*)tree.root;
//    println(tmp->keys[0]);
    leaf = (LeafNode*)&(tmp->children[1]);
    if(leaf->parent == nullptr)
        println("NULL");
//
//    fori(leaf->usedKeys){
//        println(leaf->keys[i]);
//    }
//

    println("\n\n\n\n");
    return 0;
}
