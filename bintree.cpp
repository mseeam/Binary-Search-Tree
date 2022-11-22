/********************************************************************************
 * File  :   bintree.cpp                                                        *
 * Author: Mohammad Seeam                                                       *
 * Assignment 8: Binary Search Tree                                             *
 * Fully functional Binary Search Tree                                          *
 * This header structure for all cpp and h files.                               *
 * This file, bintree.cpp, includes bintree.h                                   *
 *******************************************************************************/

#include "bintree.h"
#include <string>
#include <iostream>

/***************************************
*            CONSTRUCTOR               *
***************************************/

BinTree::BinTree(){

    root = NULL;
    count = 0;                                       

}

/***************************************
*            DESTRUCTOR                *
***************************************/

BinTree::~BinTree(){

    clear();                                         

}

/***************************************
*            isEmpty                   *
***************************************/

bool BinTree::isEmpty(){
    bool empty=false;
    if(root==NULL){                                    
        empty=true;
    }
    return empty;
}


/***************************************
*            getCount                  *
***************************************/

int BinTree::getCount(){
    return count;                                       
}

/***************************************
*            getRootData               *
***************************************/

bool BinTree::getRootData(Data* passed_data){   
    bool success=true; 
    if(root!=NULL){
        (*passed_data).id=root->data.id;                
        (*passed_data).information=root->data.information;
    }else{
        (*passed_data).id=-1;
        (*passed_data).information="";
        success=false;
    }
    return success;
}

/***************************************
*            displayTree               *
***************************************/

void BinTree::displayTree(){

    std::cout<<"DISPLAY TREE"<<std::endl;
    std::cout<<"=============================================="<<std::endl;

    if(isEmpty()==true){
        std::cout<<"Tree is empty"<<std::endl;
    }

    if(isEmpty()==false){
        std::cout<<"Tree is NOT empty"<<std::endl;
    }

    std::cout<<"Height "<<getHeight()<<std::endl;

    std::cout<<"Node count "<< count<<std::endl;

    std::cout<<std::endl;

    std::cout<<"Pre-Order Traversal"<<std::endl;
    displayPreOrder();

    std::cout<<std::endl;

    std::cout<<"In-Order Traversal"<<std::endl;
    displayInOrder();

    std::cout<<std::endl;

    std::cout<<"Post-Order Traversal"<<std::endl;
    displayPostOrder();

    std::cout<<std::endl;


}

/***************************************
*               clear                  *
***************************************/

void BinTree::clear(){
    clear(root);  
    delete root;
    root = NULL;                                       
    count=0;     

}

void BinTree::clear(DataNode* root){
    if(root!=NULL){
        clear(root->left);
        clear(root->right);
        delete root->left;                                 
        delete root->right;
        root->left=NULL;
        root->right=NULL;
    }else{
        return;
    }
}

/***************************************
*               addNode                *
***************************************/

bool BinTree::addNode(int id_passed, const string* info_passed){
    bool success = false;
    DataNode* new_node= new DataNode;
    Data data;
    if(id_passed>0 && *info_passed!=""){
        new_node->left=NULL;                              
        new_node->right=NULL;
        data.id=id_passed;
        data.information=*(info_passed);
        new_node->data=data;
        success=addNode(new_node, &root);
    }

    if(!success){
        delete new_node;
    }else{
        count++;
    }


    return success;
}

bool BinTree::addNode(DataNode* new_node, DataNode** temproot){

    bool success=true;

    if((*temproot)!=NULL){                 
        if(new_node->data.id<((*temproot)->data.id)){
            addNode(new_node, &(*temproot)->left);
        }else if(new_node->data.id>=((*temproot)->data.id)){        
            addNode(new_node, &(*temproot)->right);
        }        
    }else{               
        (*temproot)=new_node;
    }
    return success;
}


/***************************************
*             removeNode               *
***************************************/

bool BinTree::removeNode(int id){
    bool answer=true;
    int tempcount = count;
    root = removeNode(id, root);
    if(count<tempcount){
        answer=true;
    }else{
        answer=false;
    }       
    return answer;                                
}

DataNode* BinTree::removeNode(int id, DataNode* temproot){
    if(temproot==NULL){
        return temproot;
    }
    
    if(temproot->data.id>id){
        temproot->left=removeNode(id,temproot->left);
    }

    else if (temproot->data.id < id) {
        temproot->right = removeNode(id,temproot->right);
    }
    
    else{

        if(temproot->left == NULL && temproot->right == NULL){
            free(temproot);
            count--;
            return NULL;
        }

        else if(temproot->left != NULL && temproot->right != NULL){
            DataNode* succParent = temproot;
            DataNode* succ = temproot->right;
            while (succ->left != NULL) {
                succParent = succ;
                succ = succ->left;
            }   
            if (succParent != temproot)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;
            temproot->data.id = succ->data.id;
            count--;
            delete succ;
            return temproot;
        }

        else if (temproot->left == NULL) {
            DataNode* temp = temproot->right;
            free(temproot);
            count--;
            return temp;
        }

        else if (temproot->right == NULL) {
            DataNode* temp = temproot->left;
            free(temproot);
            count--;
            return temp;
            
        }
       
    }
    return temproot;

}


/***************************************
*             getNode                  *
***************************************/

bool BinTree::getNode(Data* data, int id){                      
    bool success=true;
    if(id>0){
        success=getNode(data, id, root);                     
    }else{
        success=false;
    }                                   
    return success;
}

bool BinTree::getNode(Data* data, int id, DataNode* temproot){
    bool success = false;
    if(temproot==NULL){
        success=false;
    }else if(temproot!=NULL){
        if(id==temproot->data.id){                          
            success= true;
            data->id=temproot->data.id;
            data->information=temproot->data.information;
        }else if(id < temproot->data.id){
            success=getNode(data, id, temproot->left);
        }else if(id >= temproot->data.id){
            success=getNode(data, id, temproot->right);
        }
    }
    return success;                                       

}


/***************************************
*             contains                 *
***************************************/


bool BinTree::contains(int id){
    bool success=true;
    if(id>0){
        success=contains(id, root);                     
    }else{
        success=false;
    }                                    
    return success;
}

bool BinTree::contains(int id, DataNode* temproot){
    
    bool success=false;
    if(temproot==NULL){
        success=false;
    }else if(temproot!=NULL){
        if(id==temproot->data.id){                          
            success= true;
        }else if(id < temproot->data.id){
            success=contains(id, temproot->left);
        }else if(id >= temproot->data.id){
            success=contains(id, temproot->right);
        }
    }

    return success;
                                                 
}


/***************************************
*             getHeight                *
***************************************/

int BinTree::getHeight(){
    
    return getHeight(root);                                      
}


int BinTree::getHeight(DataNode* root){

    int height = 0;

    if(root != NULL)
    {
        int left_Height = getHeight(root->left);
        int right_Height = getHeight(root->right);

        if (left_Height > right_Height){                        
            return (left_Height + 1);
        }
        else{
            return (right_Height + 1);
        }
             
    }

    if(root==NULL){height=0;}

    return height;

}

/***************************************
*           displayPreOrder            *
***************************************/

void BinTree::displayPreOrder(){
    displayPreOrder(root);                                       
}

void BinTree::displayPreOrder(DataNode *temproot){
    if (temproot == NULL){
        return;
    }
 
    std::cout << temproot->data.id << " " << temproot->data.information << std::endl;
 
    displayPreOrder(temproot->left);                             
 
    displayPreOrder(temproot->right);
}

/***************************************
*           displayPostOrder           *
***************************************/



void BinTree::displayPostOrder(){
    displayPostOrder(root);                                       
}                           

void BinTree::displayPostOrder(DataNode* temproot){

    if (temproot == NULL){
        return;
    }
    
    displayPostOrder(temproot->left);
                                                                      
    displayPostOrder(temproot->right);
 
    std::cout << temproot->data.id << " " << temproot->data.information << std::endl;

}


/***************************************
*           displayInOrder             *
***************************************/




void BinTree::displayInOrder(){
    displayInOrder(root);                                           
}

void BinTree::displayInOrder(DataNode* temproot){
    if (temproot == NULL)
        return;

    if (temproot!=NULL) {
        if (temproot->left) {
            displayInOrder(temproot->left);                           
        }
        std::cout << temproot->data.id << " " << temproot->data.information << std::endl;

        if (temproot->right) {
            displayInOrder(temproot->right);
        }
    }

    return;

}
