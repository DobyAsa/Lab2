//
// Created by DobyAsa on 2022/3/23.
//
#ifndef LAB2_LIST_H
#define LAB2_LIST_H

#include "ListNode.h"

template<typename T>
class List {
private:
    ListNode<T> head;
    ListNode<T> tail;
    unsigned int length;
public:
    List();

    List(T *Array, unsigned int size);

    bool Insert(T ddata, unsigned int index);

    bool Delete(unsigned int index);

    bool InsertAsFirst(T ddata);

    bool InsertAsLast(T ddata);

    bool IsEmpty();

    unsigned int Length();

    void Show();

    T GetData(unsigned int index);

    ListNode<T> *GetFirst();

    ListNode<T> *Find(T target);

    ~List();
};

#endif //LAB2_LIST_H
