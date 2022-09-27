#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void push_back(ListNode** head_ref, int val) {
    auto *newNode = new ListNode(val);
    if (*head_ref == nullptr) {
        *head_ref = newNode;
        return;
    }
    ListNode *tmp = *head_ref;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    //delete tmp;
}
void merge(ListNode* list1, ListNode* list2) {
    ListNode* tmp = list1;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = list2;
}
void delete_node(ListNode* node) {
    ListNode* tmp = node->next->next;
    delete node->next;
    node->next = tmp;
}
ListNode* partition(ListNode* head, int x) {
    ListNode* tmp = head;
    ListNode* lower = nullptr;
    ListNode* higher = nullptr;
    while (tmp != nullptr) {
        if (tmp->val < x) {
            push_back(&lower, tmp->val);
            tmp = tmp->next;
        } else {
            push_back(&higher, tmp->val);
            tmp = tmp->next;
        }
    }
    merge(lower, higher);
    //delete tmp;
    return lower;
}
void print(ListNode* head) {
    ListNode *tmp = head;
    while (tmp != nullptr) {
        cout << tmp->val << "->";
        tmp = tmp->next;
    }
    cout << endl;
    delete tmp;
}
int main() {
    ListNode *h = nullptr;
    push_back(&h, 1);
    push_back(&h, 4);
    push_back(&h, 3);
    push_back(&h, 2);
    push_back(&h, 5);
    push_back(&h, 2);
    ListNode *e = partition(h, 3);
    print(e);
    return 0;
}
