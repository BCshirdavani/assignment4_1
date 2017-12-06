//
//  stack.h
//  ass04_1
//
//  Created by Shy on 12/5/17.
//  Copyright © 2017 Shy. All rights reserved.
//


#ifndef STACK_H_
#define STACK_H_
#include <iostream>
using namespace std;

//array-based implementation of Stack
template <class T>
class Stack{
    T* array;
    int size;
    int top;
public:
    Stack(int=100);
    bool isFull();
    bool isEmpty();
    void push(T&);
    T pop();
    T stop();
    void destroy();
    void copy(Stack<T>&);
    ~Stack();
    template <class U>
    friend ostream& operator<<(ostream& os, Stack<U>& stack);
};
template <class T>
Stack<T>::Stack(int size){
    array = new T[size];
    this->size = size;
    top = 0;
}
template <class T>
bool Stack<T>::isEmpty(){
    return top==0;
}
template <class T>
bool Stack<T>::isFull(){
    return top==size;
}

template <class T>
void Stack<T>::push(T& item){
    if(!isFull()){
        array[top++] = item;
    }else
        cout<<"Stack is full.";
}

template <class T>
T Stack<T>::pop(){
    if(!isEmpty()){
        return array[--top];
    }
    else return 0;
}

template <class T>
T Stack<T>::stop(){
    if(!isEmpty()){
        return array[top-1];
    }
}

template <class T>
void Stack<T>::destroy(){
    top = 0;
}

template <class T>
Stack<T>::~Stack(){
    delete[] array;
}

template <class T>
void Stack<T>::copy(Stack<T>& other){
    delete[] array;
    top = other.top;
    size = other.size;
    array = new T[size];
    for(int i=0;i<top;i++){
        array[i] = other.array[i];
    }
}
template <class T>
ostream& operator<<(ostream& os, Stack<T>& stack){
    for(int i=0;i<stack.top;i++){
        os<<stack.array[i]<<" ";
    }
}
#endif /* STACK_H_ */



