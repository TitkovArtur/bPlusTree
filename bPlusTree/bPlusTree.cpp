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


//Node::~Node(){
//    println("---> Node Destructor");
//    
//}
////    if(!isLeaf){
////        InnerNode* tmp = (InnerNode*)this;
////        fori(usedKeys){
////            tmp->children[i].~Node();
////        }
////        tmp->~InnerNode();
////    }else{
////        LeafNode* tmp = (LeafNode*)this;
////        tmp->~LeafNode();
////    }
////    delete [] keys;
//}

void bPlusTree::split(Node& left, Node& right, int key, bool leafSplit){
    

    if(left.parent == nullptr){ // create new root
        InnerNode* newNode = new InnerNode(order);
        newNode->keys[0] = right.keys[0];
        newNode->children[0] = left;
        newNode->children[1] = right;
        this->root = newNode;
        newNode->usedKeys++;
        newNode->depth = left.depth + 1;
        left.parent = newNode; // Not WORKING WHY ??? TODO
        right.parent = newNode;
        newNode->children[0].parent = newNode;
        newNode->children[1].parent = newNode;
        
    }else{ //add key to parent
        InnerNode* parent = (InnerNode*)left.parent;
        
        if(parent->usedKeys == order){ // create new root
            // split node
            int counter = 0;
//            fori(ord){
//                if()
//            }
//
            
            
            

            // call addParent
        }else{ // add key
            int key = right.keys[0];
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
            parent->children[pos+1] = right;
            parent->usedKeys++;
            fori(parent->usedKeys + 1){
                parent->children[i].parent = parent;
            }
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
    println("----> destructor InnerNode");
//    LeafNode* c = (LeafNode*)children;
//    fori(usedKeys + 1){
//        delete &c[i];
////        ((LeafNode*)&(children[i]))->~LeafNode();
//    }
//    delete [] keys;
//    delete [] children;
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
    println("-->Leaf destructor");
//    delete [] pointers;
//    delete [] keys;
}



//BPLUSTREE
bPlusTree::bPlusTree(int order){
    this->order = order;
    root = new LeafNode(order);
    
    
}
void bPlusTree::clean(Node *curNode){

    if(!curNode->isLeaf){
        InnerNode* curInner = (InnerNode*)curNode;
        fori(curInner->usedKeys){
            clean(&curInner->children[i]);
        }
        delete [] curInner->children;
    }
    delete [] curNode->keys;
        
}
bPlusTree::~bPlusTree(){
    println("--> bPlusTree destructor");
    if(root!=nullptr){
        delete root;
    }
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
    println("");
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

        //---------------------
        inrangei(order/2, order){
            curNode->keys[i] = -1;
        }

        //---------------------

        fori(order/2 + 1){
            newLeaf->keys[i] = tmp[i + order/2];
        }

        curNode->usedKeys = order/2;
        newLeaf->usedKeys = order/2 + 1;
        LeafNode* curLeaf = (LeafNode*)curNode;
        
        if(curLeaf->nextLeaf != nullptr)
            newLeaf->nextLeaf = curLeaf->nextLeaf;
        curLeaf->nextLeaf = newLeaf;

        if(key == 80){
            InnerNode* pp = (InnerNode*)curNode->parent;
            LeafNode* leaf = (LeafNode*)&(pp->children[0]);
            while(leaf != nullptr){
                println("SIZE");
                println(leaf->usedKeys);
                fori(leaf->usedKeys){
                    printin(leaf->keys[i]);
                    printin("");
                }
                leaf = leaf->nextLeaf;
                if(leaf == nullptr)
                    println("NULL");
                
                println("loop");
            }

        }
        if(key == 80){
            println("RETURN");
            return;
        }
        this->split(*curLeaf, *newLeaf, 0, true);
    }
}
