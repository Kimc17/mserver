/*
#ifndef MSERVER_LISTNODE_H
#define MSERVER_LISTNODE_H
#ifndef PRUEBAS_LISTNODE_H
#define PRUEBAS_LISTNODE_H
#include <iostream>
using namespace std;
//----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- CLASS DEFINITION ---------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

template <class Type>
class ListNode {

private:
    Type _data;
    ListNode<Type>* _next;

public:
    ListNode(Type);
    ListNode(Type, ListNode<Type>*);
    ~ListNode();

    Type getData() const;
    void setData(Type);

    ListNode<Type>* getNext() const;
    void setNext(ListNode<Type>*);

};

//----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------ END CLASS DEFINITION ------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------ CLASS IMPLEMENTATION ------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

template <class Type>
ListNode<Type>::ListNode(Type pData) {
    this->setData(pData);
    this->setNext(nullptr);
}

template <class Type>
ListNode<Type>::ListNode(Type pData, ListNode<Type>* pNode) {
    this->setData(pData);
    this->setNext(pNode);
}

template <class Type>
ListNode<Type>::~ListNode() {
    //?????
}

template <class Type>
Type ListNode<Type>::getData() const {
    return this->_data;
}

template <class Type>
void ListNode<Type>::setData(Type pData) {
    this->_data = pData;
}

template <class Type>
ListNode<Type>* ListNode<Type>::getNext() const {
    return this->_next;
}

template <class Type>
void ListNode<Type>::setNext(ListNode* pNext) {
    this->_next = pNext;
}

//----------------------------------------------------------------------------------------------------------------------
//---------------------------------------------- END CLASS IMPLEMENTATION ----------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

#endif //PRUEBAS_LISTNODE_H

#endif //MSERVER_LISTNODE_H
*/