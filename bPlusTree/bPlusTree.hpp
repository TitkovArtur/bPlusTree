//
// Project:    b_tree
// Filename:   BPlusTree.h
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
#include <stack>
#include "relation.hpp"
#include "def.h"



#ifndef BPlusTree_h
#define BPlusTree_h

struct Node;
struct InnerNode;
struct LeafNode;
struct bPlusTree;






struct Node{
    int usedKeys = 0;
    bool isLeaf;
    int* keys;
    Node* parent = nullptr;
    
    void addParent(int order, bPlusTree* tree);
};


struct InnerNode : public Node{
    Node* children;
    
    InnerNode(int order);
    ~InnerNode();
};

struct LeafNode : public  Node{
    Record* pointers;
    LeafNode* nextLeaf;
    
    LeafNode(int order);
    ~LeafNode();
};


struct bPlusTree{
    int order; // i.e. num keys per node
    Node* root;
    
    bPlusTree(int order);
    ~bPlusTree();
    
    void insert(int key);

};




#endif /* BPlusTree_h */
