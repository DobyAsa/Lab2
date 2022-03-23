
#include <iostream>
#include "List.h"
#include "List.cpp"
#include "ListNode.h"
#include "ListNode.cpp"

void CharacterDivision(List<char> L);

int main() {
    char input[] = "na4xjac5GsGAsya613F8dA5Hs4uD55hfaD4bjhk1";
    List<char> L(input, 40);
    L.Show();
    CharacterDivision(L);

    return 0;
}


void CharacterDivision(List<char> L) {
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
    printf("L1:");
    L1.Show();
    printf("L2:");
    L2.Show();
    printf("L3:");
    L3.Show();
};