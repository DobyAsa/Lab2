
#include <iostream>
#include "List.h"
#include "ListNode.cpp"
void CharacterDivision(char* input, unsigned int size);
void JosephusCircle(int n, int k, int m);

int main() {
    char input[] = "na4xjac5GsGAsya613F8dA5Hs4uD55hfaD4bjhk1";
    CharacterDivision(input, 40);

//    JosephusCircle(41, 1, 3);

    return 0;
}




void CharacterDivision(char* input, unsigned int size) {
    List<char> L(input, size);
    printf(" L: ");
    L.Show();
    List<char> L1, L2, L3;
    unsigned length = L.Length();
    for (int i = 0; i < length; i++) {
        char data = L.GetFirst()->GetData();
        if (data <= '9' && data >= '0') {
            L1.InsertAsFirst(data);
        } else if (data <= 'z' && data >= 'a') {
            L2.InsertAsFirst(data);
        } else {
            L3.InsertAsFirst(data);
        }
        L.Delete(0);
    }
    printf("L1: ");
    L1.Show();
    printf("L2: ");
    L2.Show();
    printf("L3: ");
    L3.Show();
};

void JosephusCircle(int n, int k, int m){
    CircleList<int> L;
    for (int i = n; i > 0; i--){
        L.Insert(i, 0);
    }
    ListNode<int>* begin = L.FindNode(k);
    while(L.Size()){
        int count = m-1;
        while(count){
            begin = begin->GetNext();
            count--;
        }
        std::cout<<begin->GetData()<<std::endl;
        ListNode<int>* a = begin;
        begin = begin->GetNext();
        L.DeleteNode(a);
    }
};