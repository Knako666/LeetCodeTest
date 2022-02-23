/*
LeetCode剑指offer 05. replaceSpace
*/

#include <stdio.h>
#include <stdlib.h>

char* replaceSpace(char* s){
    int oldLen = strlen(s); 
    int count = 0;  //统计空格数量
    for(int i = 0; i < oldLen; i++){
        if(s[i] == ' '){
            count++;
        }
    }
    int newLen = oldLen + count * 2;    //新建字符串长度相比原长度多出count个'2'和'0'即2*count
    char* result = malloc(sizeof(char) * newLen + 1);   //最后有个结束符
    for(int i = oldLen - 1, j = newLen - 1; i >= 0; i--, j--){  //将原字符串填充到result字符串并替换空格为'%20'
        if(s[i] != ' '){
            result[j] = s[i];
        }else{
            result[j--] = '0';
            result[j--] = '2';
            result[j] = '%';
        }
    }
    result[newLen] = '\0';  //最后加上字符串结束符
    return result;
}