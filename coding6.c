/*
LeetCode142. Linked List Cycle II
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int val;
    ListNode* next;
}ListNode;

ListNode *detectCycle(struct ListNode *head) {  //环形链表，找环的入口
    ListNode *fast = head;      //用快慢指针找环
    ListNode *slow = head;

    while(fast != NULL && fast->next != NULL){  //如果快指针不为空，且能向next走两步，则进入循环，否则表示无环，直接返回NULL
        fast = fast->next->next;    //快指针走两步
        slow = slow->next;      //慢指针走一步
        if(fast == slow){       //如果快指针和慢指针相遇，则表示有环
            ListNode *tmp1 = fast;      //以快慢指针相遇结点和头结点为起点，当tmp1和tmp2相遇时即为环的入口
            ListNode *tmp2 = head;
            while(tmp1 != tmp2){    //当tmp1 != tmp2时，tmp1和tmp2各走一步
                tmp1 = tmp1->next;
                tmp2 = tmp2->next;
            }
            return tmp2;    //此时tmp1 == tmp2 ，该节点为环的入口
        }
    }
    return NULL;
    
}