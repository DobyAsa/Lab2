//
// Created by DobyAsa on 2022/3/23.
//
#include "List.h"
#include <iostream>

template<typename T>
List<T>::List():tail(NULL, NULL), head(NULL, &tail), length(0) {}

template<typename T>
List<T>::List(T *Array, unsigned int size):tail(NULL, NULL), head(NULL, &tail), length(0) {
    ListNode<T> *p = head;
    for (int i = 0; i < size; i++) {
        p->SetNext(new ListNode<T>(Array[i], p->GetNext()));
        p = p->GetNext();
    }
}
template<typename T>
bool List<T>::InsertAsFirst(T ddata) {
    return Insert(ddata, 0);
}

template<typename T>
bool List<T>::InsertAsLast(T ddata) {
    return Insert(ddata, length - 1);
}

template<typename T>
bool List<T>::Insert(T ddata, unsigned int index) {
    if (index >= length) return false;

    ListNode<T> *p = &head;
    // 移动位置到要插入的地方
    while (index > 0) {
        p = p->GetNext();
        index--;
    }
    p->SetNext(new ListNode<T>(ddata, p->GetNext()));
    length++;
    return true;
}


template<typename T>
bool List<T>::Delete(unsigned int index) {
    if (index >= length) return false;

    ListNode<T> *p = &head;
    // 移动位置到要删除的地方
    while (index > 0) {
        p = p->GetNext();
        index--;
    }
    ListNode<T> *q = p->GetNext();
    p->SetNext(p->GetNext()->GetNext());
    delete (q);
    length--;
    return true;
}

template<typename T>
bool List<T>::IsEmpty() {
    return length == 0;
}

template<typename T>
unsigned int List<T>::Length() {
    return length;
}

template<typename T>
void List<T>::Show() {
    ListNode<T> *p = head.GetNext();
    for (int i = 0; i < length; i++) {
        printf(" %d|", p->GetData());
        p = p->GetNext();
    }
    printf("\n");
}

template<typename T>
T List<T>::GetData(unsigned int index) {
    if (index >= length) {
        printf("Index out of range!");
        return -1;
    }

    ListNode<T> *p = head.GetNext();
    while (index > 0) {
        p = p->GetNext();
        index--;
    }
    return p->GetData();
}

template<typename T>
ListNode<T> *List<T>::Find(T target) {
    ListNode<T> *p = head.GetNext();
    while (p != &tail) {
        if (p->GetData() == target) return p;
        else p = p->GetNext();
    }
    return NULL;
}

template<typename T>
List<T>::~List<T>() {
    ListNode<T> *p = head.GetNext();
    ListNode<T> *q;
    while (p != &tail) {
        q = p;
        p = p->GetNext();
        delete (q);
    }
}

template<typename T>
ListNode<T> *List<T>::GetFirst() {
    return head.GetNext();
}