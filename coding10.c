/*
LeetCode454. 4Sum Ⅱ
*/

#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"

struct hashTable{
    int key;
    int value;
    UT_hash_handle hh;
};

int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize){
    struct hashTable* hashtable = NULL;
    for(int i = 0; i < ASize; ++i){
        for(int j = 0; j < BSize; ++j){
            int ikey = A[i] + B[j];
            struct hashTable* tmp;
            HASH_FIND_INT(hashtable, &ikey, tmp);
            if(tmp == NULL){
                struct hastTable* tmp = malloc(sizeof(struct hashTable));
                tmp->key = ikey, tmp->val = 1;
                HASH_ADD_INT(hashtable, key, tmp);
            }else{
                tmp->val++;
            }
        }
    }
    int count = 0;
    for(int i = 0; i < CSize; ++i){
        for(int j = 0; j < DSize; ++j){
            int ikey = (0- (C[i] + D[j]));
            struct hashTable* tmp;
            HASH_FIND_INT(hashtable, &ikey, tmp);
            if(tmp != NULL){
                count += tmp->val;
            }
        }
    }
    return count;
}
