#include "ListNode.hpp"
#include <iostream>

using std::cout; using std::endl;

int start = 2;
int end = 4;

ListNode* varified_data(){
    ListNode* head = new ListNode();
    for(int i = 5; i >= 1; i--){
        ListNode* node = new ListNode(i);
        node->next = head->next;
        head->next = node;
    }
    return head->next;
}


ListNode* reverseBetween(ListNode *head, int left, int right) {
    // 设置 dummyNode 是这一类问题的一般做法
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;
    ListNode *pre = dummyNode;
    for (int i = 0; i < left - 1; i++) {
        pre = pre->next;
    }
    ListNode *cur = pre->next;
    ListNode *next;
    for (int i = 0; i < right - left; i++) {
        next = cur->next;
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }
    return dummyNode->next;
}

ListNode* target_data(ListNode* vari){
    ListNode* targ = reverseBetween(vari, start, end);
    return targ;
}

bool varify(ListNode* test){
    ListNode* local_test = test;
    ListNode* target = target_data(varified_data());
    while(local_test!=NULL && target!=NULL && local_test->val==target->val){
        local_test = local_test->next;
        target = target->next;
    }
    bool result = (target == local_test);
    cout << std::boolalpha << result << endl;
    return result;
}
