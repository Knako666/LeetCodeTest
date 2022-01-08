/*
LeetCode_707 DesignLinkList
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct MyLinkedList{
    int val;
    MyLinkedList* next;
}MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList *Head = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    Head->next = NULL;
    return Head;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList *cur = obj->next;
    for(int i = 0; cur !=NULL; i++){
        if(i == index){
            return cur->val;
        }
        else{
            cur = cur->next;
        }
    }
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *cur = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    cur->val = val;
    cur->next = obj->next;
    obj->next = cur;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *cur = obj;
    while(cur->next !=NULL){
        cur = cur->next;
    }
    MyLinkedList *tmp = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    tmp->val = val;
    tmp->next = NULL;
    cur->next = tmp;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if(index <= 0){
        myLinkedListAddAtHead(obj, val);
        return;
    }
    MyLinkedList *cur = obj->next;
    for(int i = 1; cur != NULL; i++){
        if(index == i){
            MyLinkedList *tmp = (MyLinkedList*)malloc(sizeof(MyLinkedList));
            tmp->val = val;
            tmp->next = cur->next;
            cur->next = tmp;
        }
        else{
            cur = cur->next;
        }
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if(index < 0){
        return;
    }
    else if(index == 0){
        MyLinkedList *tmp = obj->next;
        if(tmp != NULL){
            obj->next = tmp->next;
            free(tmp);
        }
        return;
    }
    MyLinkedList *cur = obj->next;
    for(int i = 1; cur != NULL && cur->next != NULL; i++){
        if(index == i){
            MyLinkedList *tmp = cur->next;
            cur->next = tmp->next;
            free(tmp);
        }
        else{
            cur = cur->next;
        }
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    while(obj){
        MyLinkedList *tmp = obj;
        obj = obj->next;
        free(tmp);
    }
}

void printMyLinkList(MyLinkedList* obj){
    MyLinkedList *cur = obj->next;
    while(cur){
        printf("%d ",cur->val);
        cur = cur->next;
    }
}

int main(){
    MyLinkedList *obj = myLinkedListCreate();
    myLinkedListAddAtHead(obj, 2);
    // printMyLinkList(obj);
    myLinkedListAddAtTail(obj, 3);
    myLinkedListAddAtIndex(obj, 1, 4);
    printMyLinkList(obj);
    system("pause");
    return 0;
}