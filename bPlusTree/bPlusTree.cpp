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
#include <queue>


//XXNODE
void Node::addParent(int order, bPlusTree* tree){

    if(this->parent == nullptr){ // create new root
        InnerNode* newNode = new InnerNode(order);
        newNode->keys[0] = ((LeafNode*)this)->nextLeaf->keys[0];
        newNode->children[0] = *this;
        newNode->children[1] = *((LeafNode*)this)->nextLeaf;
        tree->root = newNode;
        newNode->usedKeys++;
        newNode->depth = newNode->children[0].depth + 1;
//        this->parent = newNode;
//        ((LeafNode*)this)->nextLeaf->parent = newNode;
        newNode->children[0].parent = newNode;
        newNode->children[1].parent = newNode;
    }else{ //add key to parent
        InnerNode* parent = (InnerNode*)this->parent;
        int ord = tree->order;
        if(parent->usedKeys == ord){ // create new root
            // split node
            int* tmp = new int[ord+1];
//            fori(ord){
//                tmp[i]=
//            }
            
            
            
            // call addParent
        }else{ // add key
            int key = ((LeafNode*)this)->nextLeaf->keys[0];
            int pos = 0;
            fori(parent->usedKeys){
                if(key > parent->keys[i])
                    pos++;
            }
            for(int i = parent->usedKeys; i > pos; i--){
                parent->keys[i] = parent->keys[i-1];
                parent->children[i+1] = parent->children[i];
            }
            parent->keys[pos] = key;
            parent->children[pos+1] = *((LeafNode*)this)->nextLeaf;
            parent->usedKeys++;
        }
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

void bPlusTree::print(){
    queue<Node*> q;
    q.push(root);
    int curDepth = root->depth;
    while (!q.empty()) {
        Node* curNode = q.front();
        if(curNode->depth != curDepth){
            println("");
            curDepth--;
        }
        q.pop();
        Node* tmp;
        
        fori(curNode->usedKeys){
            printin(curNode->keys[i]);
            if(curNode->isLeaf == false){
                tmp = ((InnerNode*)curNode)->children;
                q.push(&tmp[i]);
            }
        }
        if(curNode->isLeaf == false){
            q.push(&tmp[curNode->usedKeys]);
        }
        printin("|");
        
    }
}

void bPlusTree::insert(int key){
    Node* curNode = root;
    
    while(curNode->isLeaf != true){ // find leaf node
        int pointerNum = 0;
        for(; pointerNum < curNode->usedKeys; pointerNum++){
            if(key < curNode->keys[pointerNum])
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
        curNode->usedKeys = order/2;
        newLeaf->usedKeys = order/2 + 1;
        ((LeafNode*)curNode)->nextLeaf = newLeaf;
        
        
        curNode->addParent(order, this);
    }
}
