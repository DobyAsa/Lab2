//
// Created by DobyAsa on 2022/3/23.
// 单链表

#ifndef LAB2_LISTNODE_H
#define LAB2_LISTNODE_H

template<typename T>
class ListNode {
private:
    T data;
    ListNode<T> *next;
public:
    ListNode(T ddata, ListNode<T> *nnext);

    T GetData();

    void SetData(T ddata);

    ListNode<T> *GetNext();

    void SetNext(ListNode<T> *nnext);
};

#endif //LAB2_LISTNODE_H
