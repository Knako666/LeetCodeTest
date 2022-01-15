/*
LeetCode19.RemoveNthNodeFromEndofList
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int val;
    ListNode* next;
}ListNode;

ListNode* removeNthFromEnd(struct ListNode* head, int n){   //删除倒数第N个结点
    typedef struct ListNode ListNode;
    ListNode *FakeNode = (ListNode*)malloc(sizeof(ListNode));
    FakeNode->next = head;
    ListNode *fast = FakeNode, *slow = FakeNode;
    for(int i = 0; i < n; i++){
        fast = fast->next;
    }
    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    ListNode *tmp = slow->next;
    slow->next = slow->next->next;
    free(tmp);
    return FakeNode->next;
}

void printMyLinkList(ListNode* obj){    //打印链表
    ListNode *cur = obj;
    while(cur){
        printf("%d ",cur->val);
        cur = cur->next;
    }
}

void myLinkedListAddAtTail(ListNode* obj, int val) {    //在链表尾部插入元素
    ListNode *cur = obj;
    while(cur->next !=NULL){
        cur = cur->next;
    }
    ListNode *tmp = (ListNode*)malloc(sizeof(ListNode));
    tmp->val = val;
    tmp->next = NULL;
    cur->next = tmp;
}

int main(){
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));   //创建头节点
    head->val = 1;
    head->next = NULL;
    int x = 3;  //创建链表
    int arr[] = {2,3,4};
    int i = 0;
    while(x-- > 0){
        myLinkedListAddAtTail(head,arr[i++]);
    }
    printMyLinkList(head);
    printf("\n");
    printMyLinkList(removeNthFromEnd(head,2));  //删除倒数第n个元素
    system("pause");
    return 0;
}