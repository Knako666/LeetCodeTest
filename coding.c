/*
LeetCode_203 removeLinkListElem
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkNode{
    int val;
    LinkNode *next;
}Linklist,LinkNode;

Linklist *removeElements(Linklist* head, int val){      //�Ƴ�����Ԫ��
    LinkNode *tHead = (LinkNode*)malloc(sizeof(LinkNode));
    tHead->next = head;
    while(tHead->next != NULL){
        if(tHead->next->val == val){
            LinkNode *temp = tHead->next;
            tHead->next = temp->next;
            free(temp);
        }
        else{
            tHead = tHead->next;
        }
    }
    head = tHead->next;
    free(tHead);
    return head;
}

void InitLinkList(Linklist *head,int val){     //��ʼ������
    head = (LinkNode*)malloc(sizeof(LinkNode));
    head->val = val;
    head->next = NULL;
}

void InsertLinkList(Linklist *head, int val){       //β�巨��������   
    LinkNode *t = (LinkNode*)malloc(sizeof(LinkNode));
    t->val = val;
    LinkNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = t;
    t->next = NULL;
}

int main(){
    int arr[7] = {1,2,6,3,4,5,6};   //����һ������ʵ��
    Linklist *head;
    InitLinkList(head,1);
    for(int i = 0;i < 7; ++i){      //������Ԫ�ش�������
        InsertLinkList(head,arr[i]);
    }
    removeElements(head,6);
    for(LinkNode *t = head; t != NULL; t = t->next){
        printf("%d",t->val);
    }
    system("pause");
    return 0;
}