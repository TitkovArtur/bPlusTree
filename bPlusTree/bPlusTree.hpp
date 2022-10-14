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



#ifndef BPlusTree_h
#define BPlusTree_h

struct Node;
struct InnerNode;
struct LeafNode;







struct Node{
public:
    int usedKeys;
    bool isLeaf;
    int* keys;
};


struct InnerNode : public Node{
    Node* children;
    
    InnerNode(int order){
        this->usedKeys = 0;
        this->isLeaf = false;
        this->keys = new int[order];
        children = new Node[order + 1];
    }
};

struct LeafNode : public  Node{
    Record* pointers;
    LeafNode* nextLeaf;
    
    LeafNode(int order){
        usedKeys = 0;
        isLeaf = true;
        keys = new int[order];
        pointers = new Record[order];
        nextLeaf = nullptr;
    }
};


struct BPlusTree{
    int order; // i.e. num keys per node
    Node* root;
    
    BPlusTree(int d){
        order = d;
        root = new LeafNode(order);
    }
    
    

        
        
        
        
        
        
        
        
        
};




#endif /* BPlusTree_h */
