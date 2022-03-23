//
// Created by DobyAsa on 2022/3/23.
// 单链表

#ifndef LAB2_LISTNODE_H
#define LAB2_LISTNODE_H
template <typename T>
class ListNode {
private:
    T data;
    ListNode<T>* next;
public:
    ListNode(T ddata, ListNode<T>* nnext);
    T Get();
    void Set(T ddata, ListNode<T>* node);
};
#endif //LAB2_LISTNODE_H
