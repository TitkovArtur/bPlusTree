//
// Project:    bPlusTree
// Filename:   bPlusTree.cpp
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

#include "bPlusTree.hpp"
#include "def.h"



//XXNODE
void Node::addParent(int order, bPlusTree* tree){
    if(this->parent == nullptr){
        InnerNode* newNode = new InnerNode(order);
        newNode->keys[0] = ((LeafNode*)this)->nextLeaf->keys[0];
        newNode->children[0] = *this;
        newNode->children[1] = *((LeafNode*)this)->nextLeaf;
    }
};


//XXINNERNODE

InnerNode::InnerNode(int order){
    this->isLeaf = false;
    this->keys = new int[order];
    children = new Node[order + 1];
}
InnerNode::~InnerNode(){
    println("--> destructor InnerNode");
}




//XXLEAFNODE

LeafNode::LeafNode(int order){
    usedKeys = 0;
    isLeaf = true;
    keys = new int[order];
    pointers = new Record[order];
    nextLeaf = nullptr;
    fill_n(keys, order, -1);
}


LeafNode::~LeafNode(){
    println("--> LeafNode destructor");
    
}



//BPLUSTREE
bPlusTree::bPlusTree(int order){
    this->order = order;
    root = new LeafNode(order);
    
    
}

bPlusTree::~bPlusTree(){
    println("--> bPlusTree destructor");
}


void bPlusTree::insert(int key){
    Node* curNode = root;
    
    while(curNode->isLeaf != true){ // find leaf node
        int pointerNum = 0;
        for(; pointerNum < curNode->usedKeys; pointerNum++){
            if(key > curNode->keys[pointerNum])
                break;
        }
        curNode = &((InnerNode*)curNode)->children[pointerNum];
    }
    if(curNode->usedKeys < order){ // leaf capacity not reached
        int pos = 0;
        fori(curNode->usedKeys){
            if(curNode->keys[pos] > key){
                break;
            }
            pos++;
        }
        for(int i = curNode->usedKeys; i > pos; i--){
            curNode->keys[i] = curNode->keys[i-1];
        }
        curNode->keys[pos] = key;
        curNode->usedKeys++;

        
    }else{ // leaf capacity reached -> split node
        LeafNode* newLeaf = new LeafNode(order);
        int pos = 0;
        fori(order){
            if(curNode->keys[i]<key)
                pos++;
            else
                break;
        }
        int* tmp = new int[order+1];
        fori(order){
            tmp[i] = curNode->keys[i];
        }
        tmp[order] = key;
        sort(tmp, tmp+5);
        fori(order/2){
            curNode->keys[i] = tmp[i];
        }
        inrangei(order/2, order){
            curNode->keys[i] = -1;
        }
        fori(order/2 + 1){
            newLeaf->keys[i] = tmp[i + order/2];
        }
        newLeaf->usedKeys = order/2 +1;
        ((LeafNode*)curNode)->nextLeaf = newLeaf;
        
        if(curNode->parent == nullptr){
            curNode->addParent(order, this);
        }

    }
    
    
    
    
}
