//
// Created by DobyAsa on 2022/3/23.
//
#ifndef LAB2_LIST_H
#define LAB2_LIST_H
#include <iostream>
#include "ListNode.h"

template<typename T>
class List {
private:
    ListNode<T> head;
    ListNode<T> tail;
    unsigned int length;
public:
    List():tail(0, NULL), head(0, &tail), length(0) {}

    List(T *Array, unsigned int size):tail(0, NULL), head(0, &tail), length(0){
        ListNode<T> *p = &head;
        for (int i = 0; i < size; i++) {
            p->SetNext(new ListNode<T>(Array[i], p->GetNext()));
            p = p->GetNext();
        }
        length = size;
    }

    bool Insert(T ddata, unsigned int index){
        if (index > length) return false;

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

    bool Delete(unsigned int index){
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

    bool InsertAsFirst(T ddata){return Insert(ddata, 0);}

    bool InsertAsLast(T ddata){return Insert(ddata, length - 1);}

    bool IsEmpty(){
        return length == 0;
    }

    unsigned int Length(){
        return length;
    }

    void Show(){
        ListNode<T> *p = head.GetNext();
        for (int i = 0; i < length; i++) {
            std::cout<<p->GetData()<<"| ";
            p = p->GetNext();
        }
        printf("size: %d \n", length);
    }

    T GetData(unsigned int index){
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

    ListNode<T> *GetFirst(){
        return head.GetNext();
    }

    ListNode<T> *Find(T target){
        ListNode<T> *p = head.GetNext();
        while (p != &tail) {
            if (p->GetData() == target) return p;
            else p = p->GetNext();
        }
        return NULL;
    }

    ~List(){
        while(length){
            Delete(0);
        }
    }
};


template <typename T>
class CircleList {
private:
    ListNode<T>* head;
    ListNode<T>* last;
    unsigned int size;
public:
    CircleList():head(NULL), size(0), last(NULL){}

    CircleList(T* Array, unsigned int ssize):head(NULL), size(0), last(NULL){
        if (ssize > 0){
            head = new ListNode<T>(Array[0], NULL);
            ListNode<T> *p = head;
            for (int i = 1; i < ssize; i++) {
                p->SetNext(new ListNode<T>(Array[i], p->GetNext()));
                p = p->GetNext();
                last = p;
                size++;
            }
            p->SetNext(head);
        }
    }

    void Insert(T ddata, unsigned int index){
        if (size == 0) {
            head = new ListNode<T>(ddata, NULL);
            head->SetNext(head);
            last = head;
        }else{
            if (index == 0){
                last->SetNext(new ListNode<T>(ddata, head));
                head = last->GetNext();
            }else {
                ListNode<T>* p = head;
                ListNode<T>* q = last;
                while (index > 0) {

                    q = p;
                    p = p->GetNext();
                    index--;
                }
                q->SetNext(new ListNode<T>(ddata, p));
            }
        }
        size++;
    }

    void Delete(unsigned int index){
        ListNode<T>* p = head;
        ListNode<T>* q = last;
        while(index > 0){
            q = p;
            p = p->GetNext();
            index--;
        }
        q->SetNext(p->GetNext());
        delete(q);
        size--;
    }

    void Show(){
        ListNode<T>* p = head;
        for (int i = 0; i < size; i++){
            std::cout<<p->GetData()<<"| ";
            p = p->GetNext();
        }
    }

    ListNode<T>* FindNode(T ddata){
        ListNode<T>* p = head;
        while(p->GetNext() != head){
            if (p->GetData() == ddata){
                return p;
            }else{
                p = p->GetNext();
            }
        }
        if (p->GetData() == ddata)  return p;
        return NULL;
    }

    void DeleteNode(ListNode<T>* node){
        ListNode<T>* p = head;
        ListNode<T>* q = last;
        while(p != node){
            q = p;
            p = p->GetNext();
        }
        q->SetNext(p->GetNext());
        if (p == last)  last = q;
        if (p == head)  head = q->GetNext();
        delete(p);
        size--;
    }

    unsigned int Size(){
        return size;
    }

    ~CircleList(){
        while(size){
            Delete(0);
        }
    }

};
#endif //LAB2_LIST_H
