//
// Created by 63111 on 2022/3/23.
//

#include "ListNode.h"

template<typename T>
ListNode<T>::ListNode(T ddata, ListNode<T> *nnext) {
    data = ddata;
    next = nnext;
}

template<typename T>
T ListNode<T>::GetData() {
    return data;
}

template<typename T>
void ListNode<T>::SetData(T ddata) {
    data = ddata;
}

template<typename T>
ListNode<T> *ListNode<T>::GetNext() {
    return next;
}

template<typename T>
void ListNode<T>::SetNext(ListNode<T> *nnext) {
    next = nnext;
}