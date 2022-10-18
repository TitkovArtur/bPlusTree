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

class base {
  public:
    base()
    { cout << "Constructing base\n"; }
    virtual ~base()
    { cout << "Destructing base\n"; }
};
 
class derived : public base {
  public:
    derived()
    { cout << "Constructing derived\n"; }
    virtual ~derived()
    { cout << "Destructing derived\n"; }
};


int main(int argc, const char * argv[]) {
    
    
//    base *b = new derived();
//    delete b;
//
    
    
    
    


    Relation r = Relation(10);




    bPlusTree tree(4);
    InnerNode* n = (InnerNode*)tree.root;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(25);
    tree.insert(50);
    tree.insert(60);
    tree.insert(11);
    tree.insert(12);
    tree.insert(70);
    tree.insert(80);
    tree.print();
    tree.insert(33);
    tree.insert(35);
    tree.insert(36);
    tree.print();

    



    
//    tree.print();
    InnerNode* tmp = (InnerNode*)tree.root;
    LeafNode* leaf = (LeafNode*)(&tmp->children[0]);
//    Node* leaf =(&tmp->children[0]);

    
    
    
    println("");
//    leaf->~LeafNode();
//    delete leaf;
//    Node* l = new LeafNode(4);
//    l->~Node();
//    delete l;
    
    
    

    
    
    
    println("\n\n\n\n");
    return 0;
}
