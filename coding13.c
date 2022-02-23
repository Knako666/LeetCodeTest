/*
LeetCode541. Reverse String2
*/

#include <stdio.h>
#include <stdlib.h>

void swap(char* a, char* b){    //定义交换函数
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(char* l, char* k){ //定义反转函数,将l到k-1之间的字符串两两交换
    while(l < k){
        swap(l++, --k); //k的初始位置下标要-1
    }
}

int min(int a, int b){  //判断下标大小
    return a < b ? a : b;
}

char *reverseStr(char* s, int k){   //主函数,反转字符串中每隔2k个字符的前k个字符
    int n = strlen(s);              //若剩余字符少于k则剩余全部反转
    for(int i = 0; i < n; i += k * 2){  //每次以2k进行指针前移
        reverse(&s[i], &s[min(i + k, n)]);  //用min判断剩余的字符串是否<=k个
    }
    return s;
}