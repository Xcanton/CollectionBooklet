
/*
* 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
* 请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。

* Given the head of a singly linked list and two integers left and right 
* where left <= right, reverse the nodes of the list from position left 
* to position right, and return the reversed list.

* Constraints:
* The number of nodes in the list is n.
* 1 <= n <= 500
* -500 <= Node.val <= 500
* 1 <= left <= right <= n
*/

#include "ListNode.hpp"
#include "CodeVerified.cpp"
#include <iostream>

using std::cout; using std::endl;

ListNode* solution(ListNode* head, int left, int right){
    // write your code here
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

int main(){
    ListNode* raw_input = varified_data();
    ListNode* test_node = solution(raw_input, start, end);
    varify(test_node);
}