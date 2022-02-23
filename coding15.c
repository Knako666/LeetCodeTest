/*
LeetCode剑指offer 58-2. reverseLeftWords
*/

#include <stdio.h>
#include <stdlib.h>

void reverse(char* s, int start, int end){ //反转字符串[star, end]之间
    while(start < end){
        char tmp = s[start];
        s[start++] = s[end];
        s[end--] = tmp;
    }
}

char* reverseLeftWords(char* s, int n){ //将字符串左侧n个字符左旋到字符串右侧
    int len = strlen(s);
    //反转前n个字符
    reverse(s, 0, n - 1);
    //反转剩余字符
    reverse(s, n, len - 1);
    //反转整个字符串
    reverse(s, 0, len - 1);
    return s;
}