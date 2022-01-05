/*
LeetCode_203 removeLinkListElem
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode{
    int val;
    LinkNode *next;
}LinkNode;

LinkNode* removeElements(LinkNode* head, int val){      //移除数组元素
    LinkNode *tHead = (LinkNode*)malloc(sizeof(LinkNode));
    tHead->next = head;
    LinkNode *cur = tHead;
    while(cur->next != NULL){
        if(cur->next->val == val){
            LinkNode *temp = cur->next;
            cur->next = temp->next;
            free(temp);
        }
        else{
            cur = cur->next;
        }
    }
    head = tHead->next;
    free(tHead);
    return head;
}

// LinkNode* InitLinkList(LinkNode* head,int val){     //初始化数组
//     head = (LinkNode*)malloc(sizeof(LinkNode));
//     head->val = val;
//     head->next = NULL;
//     return head;
// }

LinkNode* InsertLinkList(LinkNode* head, int val){       //尾插法插入数组   
    LinkNode *t = (LinkNode*)malloc(sizeof(LinkNode));
    t->val = val;
    t->next = NULL;
    LinkNode *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = t;
    return head;
}

int main(){
    int arr[7] = {1,2,6,3,4,5,6};   //创建一个数组实例
    LinkNode *head = (LinkNode*)malloc(sizeof(LinkNode));                 //头指针
    // InitLinkList(head,1);
    head->val = 1;
    head->next = NULL;
    for(int i = 1;i < 7; ++i){      //将数组元素存入链表
        InsertLinkList(head,arr[i]);
    }
    removeElements(head,6);
    for(LinkNode *t = head; t != NULL; t = t->next){
        printf("%d",t->val);
    }
    system("pause");
    return 0;
}