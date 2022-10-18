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
    int depth = 0;
    Node* parent = nullptr;
    virtual ~Node(){
        println("-->Node destructor");
    };
    
};


struct InnerNode : public Node{
    Node* children;
    
    InnerNode(int order);
    ~InnerNode();
};

struct LeafNode : public  Node{
    Record* pointers;
    LeafNode* nextLeaf = nullptr;
    
    LeafNode(int order);
    ~LeafNode();
};


struct bPlusTree{
    int order; // i.e. num keys per node
    Node* root;
    
    bPlusTree(int order);
    ~bPlusTree();
    
    void insert(int key);
    void print();
    void split(Node& left, Node& right, int key, bool leafSplit);
    void clean(Node* curNode);
};




#endif /* BPlusTree_h */
