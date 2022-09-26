#include <iostream>


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum1 = 0;

    int mn = 1;

    while (l1 != nullptr) {
        sum1 += l1->val*mn;
        l1 = l1->next;
        mn *= 10;
    }

    int sum2 = 0;
    mn = 1;
    while (l2 != nullptr) {
        sum2 += l2->val*mn;
        l2 = l2->next;
        mn *= 10;
    }

    int s = sum1 + sum2;
    ListNode *neww = new ListNode(s%10);
    s /= 10;
    ListNode *tmp = neww;
    while (s != 0) {
        ListNode* newnode = new ListNode(s%10);
        tmp->next = newnode;
        tmp = tmp->next;
        s /= 10;
    }
    return neww;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
