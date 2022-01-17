/*
LeetCode面试题02.07.Intersection_of_TwoLinkedLists_LCCI
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int val;
    ListNode* next;
}ListNode;

ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {     //求出两个链表的相交结点
    typedef struct ListNode ListNode;
    ListNode *curA = headA;
    ListNode *curB = headB;
    ListNode *l = NULL;
    ListNode *s = NULL;
    int lenA = 0, lenB = 0, gap = 0;
    while(curA){    //求A长度
        lenA++;
        curA = curA->next;
    }
    while(curB){    //求B长度
        lenB++;
        curB = curB->next;
    }
    curA = headA;   //让curA,curB重新只想头结点
    curB = headB;

    if(lenA < lenB){    //让最长的链为A
        l = curB, s = curA;
        gap = lenB - lenA;
    }else{
        l = curA, s = curB;
        gap = lenA - lenB;
    }
    while(gap--){     //让A,B链表对齐
        l = l->next;
    }
    while(l){    //两链表cur指针同时向后移动，若curA == curB 则相交，返回结点指针，否则返回NULL
        if(l == s){
            return l;
        }
        l = l->next;
        s = s->next;
    }
    return NULL;
}