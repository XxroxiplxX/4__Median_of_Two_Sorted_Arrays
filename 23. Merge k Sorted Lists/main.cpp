#include <iostream>
#include "vector"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

void push_back(ListNode* head, int val) {
    ListNode *tmp = head;
    if (head == nullptr) {
        head = new ListNode(val);
        delete tmp;
        return;
    }
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = new ListNode(val);
    return;
}
ListNode* push_back(ListNode* head, ListNode* node_to_add) {
    ListNode *tmp = head;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = node_to_add;
    node_to_add->next = nullptr;
    delete tmp;
    return node_to_add;
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
ListNode* merge(ListNode* a, ListNode* b) {
    if (a == nullptr) {
        return b;
    }
    if (b == nullptr) {
        return a;
    }
    ListNode* newList = nullptr;
    ListNode* tmp = a;
    ListNode* help = b;
    if (tmp->val < help->val) {
        newList = new ListNode(tmp->val);
        tmp = tmp->next;
    } else {
        newList = new ListNode(help->val);
        help = help->next;
    }
    while (tmp != nullptr or help != nullptr) {
        if (help == nullptr) {
            push_back(newList, tmp->val);
            tmp = tmp->next;
        } else if (tmp == nullptr) {
            push_back(newList, help->val);
            help = help->next;
        } else if (tmp->val < help->val) {
            push_back(newList, tmp->val);
            tmp = tmp->next;
        } else {
            push_back(newList, help->val);
            help = help->next;
        }
    }
    delete tmp;
    delete help;
    return newList;
}
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {
        return nullptr;
    }
    while (lists.size() != 1) {
        lists.push_back(merge(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
}
void delete_list(ListNode* head) {
    if (head->next == nullptr) {
        delete head;
    } else {
        delete_list(head->next);
    }
}
int main() {

    ListNode *head = new ListNode(3);
    push_back(head, 5);
    push_back(head, 7);
    push_back(head, 8);
    ListNode *head2 = new ListNode(2);
    push_back(head2, 3);
    push_back(head2, 3);
    push_back(head2, 3);
    push_back(head2, 3);
    push_back(head2, 3);
    push_back(head2, 3);
    ListNode *list = new ListNode(15);
    push_back(list, 32);
    push_back(head2, 35);
    push_back(head2, 38);
    push_back(head2, 39);
    push_back(head2, 43);
    push_back(head2, 63);
    ListNode* list2 = new ListNode(0);
    push_back(list2,1);
    push_back(list2,2);
    push_back(list2,4);
    push_back(list2,5);
    push_back(list2,6);
    push_back(list2,7);
    push_back(list2,8);
    push_back(list2,9);
    push_back(list2,10);
    push_back(list2,11);
    push_back(list2,12);
    push_back(list2,13);
    print(head);
    print(head2);
    print(list);
    vector<ListNode*> vec = {head, head2, list, list2};
    ListNode* merged = mergeKLists(vec);
    print(merged);
    //delete_list(head2);
    //delete_list(head3);
    //delete_list(head);
    return 0;
}
