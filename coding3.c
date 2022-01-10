/*
LeetCode206.reverseLinkList
LeetCode24.swapPairs_LinkList
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int val;
    ListNode* next;
}ListNode;

/*
ListNode* reverseList(struct ListNode* head){   //反转链表
    ListNode *pre = NULL;
    ListNode *tmp;
    while(head){
        tmp = head->next;
        head->next = pre;
        pre = head;
        head = tmp;
    }
    return pre;
}
*/
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

ListNode* swapPairs(struct ListNode* head){     //两两交换链表中的结点
    ListNode *fakeHead = (ListNode*)malloc(sizeof(ListNode));   //设置虚拟头结点
    fakeHead->next = head;
    ListNode *cur = fakeHead;
    while(cur->next && cur->next->next){    //当头结点和头结点的next存在时执行循环
        ListNode *tmp = cur->next;  //储存临时结点
        ListNode *tmp1 = cur->next->next->next;
        cur->next = cur->next->next;    //虚拟节点的next连接到第二个节点（让第二节点提前）
        cur->next->next = tmp;      //第二节点的next连接到第一节点（换位）
        cur->next->next->next = tmp1;   //第一节点的next连接到原来的第三节点
        cur = cur->next->next;      //cur向前移动两个结点，再次循环判断
    }
    return fakeHead->next;  //返回头结点
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
    // printMyLinkList(reverseList(head));      //反转链表
    printMyLinkList(swapPairs(head));       //交换链表元素
    system("pause");
    return 0;
}