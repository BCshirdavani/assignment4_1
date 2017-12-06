//****************************************************************
//
//  Author:         fatma.serce
//  Date:           12-5-2017
//  Title:          Assignment 04 - part 1
//  File:           BinarySearchTree.h
//  Purpose:        
//
//****************************************************************


#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <iostream>
#include "stack.h"
using namespace std;

//****************************************************************
//                                                      node
template <class T>
struct node{
    T data;
    node<T>* left;
    node<T>* right;
};

//****************************************************************
//                                                      tree
template <class T>
class BinarySearchTree{
private:
    node<T>* root;
    void inOrderT(node<T>*);
//    void inOrderF(node<T>* p, T& item);        // new filter traverse
    void preOrderT(node<T>*);
    void postOrderT(node<T>*);
    void destroy(node<T>*);
    int treeHeight(node<T>*);
    int max(int, int);
    int treeNodeCount(node<T>*);
    int treeLeaveCount(node<T>*);
    void treeInsert(node<T>*&, T&);
    bool treeSearch(node<T>*, T&);
    T treeSearchNEW(node<T>*, T&);       // NEW search, returns T data
    node<T>* findMax(node<T>*);
    void deleteNode(node<T>*&, T&);
    
public:
    BinarySearchTree();
    void inOrder(){inOrderT(root);}
//    void inOrderFILTER( T& item ){inOrderF(root, item);}    // new filter traverse
    void inOrderFILTER( T& item );                          // new filter traverse
    void preOrder(){preOrderT(root);}
    void postOrder(){postOrderT(root);}
    int height(){return treeHeight(root);}
    int nodeCount(){return treeNodeCount(root);}
    int leaveCount(){return treeLeaveCount(root);}
    void insert(T& item){treeInsert(root, item);}
    bool search(T& item){return treeSearch(root,item);}
    T searchNEW(T& item){return treeSearchNEW(root,item);}       // NEW search, returns T data
    //    void insert(T&); //non-recursive function call
    node<T>* findMax(){return findMax(root);}
    void deleteNode(T& item){deletenode(root, item);}
    ~BinarySearchTree(){destroy(root);}
    
};

//****************************************************************
//                                                      constructor
template <class T>
BinarySearchTree<T>::BinarySearchTree(){
    root = NULL;
}

//****************************************************************
//                                                      inOrder Traversal
//                                                      recursive
template <class T>
void BinarySearchTree<T>::inOrderT(node<T>* p){
    if(p!=NULL){
        inOrderT(p->left);
        cout<<p->data;
        inOrderT(p->right);
    }
}

//****************************************************************
//                                                      inOrder FILTER
//                                                      while loop
//inorder traversal without recursion
//template <class T>
//void BinarySearchTree<T>::inOrderF(node<T>* p, T& item){
//    Stack< node<T>* > s;
//    while( ( p!= NULL || !s.isEmpty() ) && ( p->data != item ) ){
//        if( p!= NULL ){
//            s.push(p);
//            p = p->left;
//        }else{
//            p = s.pop();
//            cout<<p->data;
//            p = p->right;
//        }
//    }
//}

template <class T>
void BinarySearchTree<T>::inOrderFILTER( T& item ){
    node<T>* p = root;
    Stack< node<T>* > s;
    while( ( p!= NULL || !s.isEmpty() ) /*&& !( p->data == item )*/ ){
//        cout << "loop...." << endl;
        if( p!= NULL ){
//            cout << "not NULL" << endl;
            if ( p->data != item ){
                s.push(p);
                p = p->left;
            }
            else if ( p->data == item ){
//                cout << "break" << endl;
                break;
            }

        }else{
            p = s.pop();
            cout<<p->data;
            p = p->right;
        }
    }
}

//****************************************************************
//                                                      preOrder Traversal
template <class T>
void BinarySearchTree<T>::preOrderT(node<T>* p){
    if(p!=NULL){
        cout<<p->data;
        preOrderT(p->left);
        preOrderT(p->right);
    }
}


//****************************************************************
//                                                      postOrder Traversal
template <class T>
void BinarySearchTree<T>::postOrderT(node<T>* p){
    if(p!=NULL){
        postOrderT(p->left);
        postOrderT(p->right);
        cout<<p->data;
    }
}

//****************************************************************
//                                                      max(int, int)
template <class T>
int BinarySearchTree<T>::max(int x, int y){
    if (x>y)
        return x;
    return y;
}

//****************************************************************
//                                                      treeHeight()
//                                                      recursive
template <class T>
int BinarySearchTree<T>::treeHeight(node<T>* p){
    if(p!=NULL){
        return 1 + max(height(p->left, p->right));
    }
    return 0;
}

//****************************************************************
//                                                      treeNodeCount()
//                                                      recursive
template <class T>
int BinarySearchTree<T>::treeNodeCount(node<T>* p){
    if(p==NULL)
        return 0;
    else
        return 1 + treeNodeCount(p->left) + treeNodeCount(p->right);
}
template <class T>
int BinarySearchTree<T>::treeLeaveCount(node<T>* p){
    if(p==NULL)
        return 0;
    else if(p->left==NULL && p->right==NULL)
        return 1;
    else
        return treeLeaveCount(p->left) + treeLeaveCount(p->right);
}
template <class T>
void BinarySearchTree<T>::destroy(node<T>* p){
    if(p!= NULL){
        destroy(p->left);
        destroy(p->right);
        delete p;
        p= NULL;
    }
}

//non recursive insert function
//template <class T>
//void BinarySearchTree<T>::insert(T& item){
//    node<T>* newnode = new node<T>();
//    newnode->data = item;
//    newnode->left = newnode->right = NULL;
//    if(root == NULL){
//        root = newnode;
//    }
//    else{
//        node<T>* p = root;
//        node<T>* q;
//        while(p!=NULL){
//            q = p;
//            if(item==p->data){
//                cout<<p->data;
//                cout<<"error"<<endl;
//                return;
//            }
//            else if (item<p->data)
//                p = p->left;
//            else
//                p = p->right;
//        }
//        if(item<q->data)
//            q->left = newnode;
//        else
//            q->right = newnode;
//    }
//
//}

//****************************************************************
//                                                      treeInsert
//                                                      recursive
// Must define override for < operator so I can compare Contacts
template <class T>
void BinarySearchTree<T>::treeInsert(node<T>*& p, T& item){
    if(p == NULL){
        p = new node<T>;
        p->data = item;
        p->left = p->right = NULL;
    }
    else if( item < p->data ){
        treeInsert(p->left, item);
    }else{
        treeInsert(p->right, item);
    }
}

//****************************************************************
//                                                      treeSearch()
//                                                      recursive
template <class T>
bool BinarySearchTree<T>::treeSearch(node<T>* p, T& item){
    if(p == NULL)
        return false;
    else if( item < p->data )
        return treeSearch(p->left, item);
    else if( item > p->data )
        return treeSearch(p->right, item);
    return true;
}

//****************************************************************
//                                                      treeSearch() NEW
//                                                      return type T
template <class T>
T BinarySearchTree<T>::treeSearchNEW(node<T>* p, T& item){
    if(p == NULL)
        cout << "could not find this person";
    else if( item < p->data )
        return treeSearchNEW(p->left, item);
    else if( item > p->data )
        return treeSearchNEW(p->right, item);
    return p->data;
}

//****************************************************************
//                                                      findMax()
//                                                      recursive
template <class T>
node<T>* BinarySearchTree<T>::findMax(node<T>* p){
    if ( p == NULL )
        return NULL;
    else if( p->right == NULL )
        return p;
    else
        return findMax(p->right);
}

//****************************************************************
//                                                      deleteNode()
//                                                      recursive
// Must define override for > operator so I can compare Contacts
template <class T>
void BinarySearchTree<T>::deleteNode(node<T>*& p, T& item){
    //item not found, do nothing
    if(p == NULL)
        return;
    else if ( item < p->data )    //item is on the left subtree
        deleteNode(p->left, item);
    else if ( item > p->data )    //item is on the right subtree
        deleteNode(p->right, item);
    else{//item is equal to data,  it is found
        if( p->left!= NULL && p->right != NULL ){    //if it is with two children
            p->data = findMax(p->left)->data;
            deleteNode(p->left, p->data);
        }else{
            node<T>* old = p;
            if(p->left != NULL)
                p = p->left;
            else
                p = p->right;
            delete old;
        }
    }
}



#endif /* BINARYSEARCHTREE_H_ */
