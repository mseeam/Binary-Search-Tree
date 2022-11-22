/********************************************************************************
 * File  :   bintree.h                                                          *
 * Author: Mohammad Seeam                                                       *
 * Assignment 8: Binary Search Tree                                             *
 * Fully functional Binary Search Tree                                          *
 * This header structure for all cpp and h files.                               *
 * This file, bintree.h, includes data.h                                        *
 *******************************************************************************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H
#include "data.h"

class BinTree {
public:

    BinTree();   // this is the constructor
    ~BinTree();   // this is the destructor
    bool isEmpty(); 
    int getCount();
    bool getRootData(Data*);
    void displayTree();

    void clear();
    bool addNode(int, const string*);
    bool removeNode(int);
    bool getNode(Data*, int);
    bool contains(int);
    int getHeight();
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();

private:

    DataNode *root;
    int count;

    void clear(DataNode*);
    bool addNode(DataNode*, DataNode**);
    DataNode* removeNode(int, DataNode*);
    bool getNode(Data*, int, DataNode*);
    bool contains(int, DataNode*);
    int getHeight(DataNode*);
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);

};

#endif /* BINTREE_BINTREE_H */

