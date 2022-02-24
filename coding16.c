/*
LeetCode28. implement strStr()  模式串匹配
*/

#include <stdio.h>
#include <stdlib.h>

void getNext(int next[], char* s){  //构造next数组
    int sLen = strlen(s);
    next[0] = 0;    //下标从0开始
    for(int i = 1, j = 0; i < sLen; i++){   //i为后缀末尾，j为前缀末尾
        while(j > 0 && s[i] != s[j]){   //若s[i]与s[j]不同则代表前后缀末尾不同则持续向前回退
            j = next[j - 1];    //next[j - 1]记录了当前s[j]最大相等前后缀长度,即回退位置下标
        }
        if(s[i] == s[j]){   //如果 s[i] 与 s[j] 相同，那么就同时向后移动i 和j 说明找到了相同的前后缀，同时还要将j（前缀的长度）赋给next[i], 因为next[i]要记录相同前后缀的长度。
            j++;
        }
        next[i] = j;
    }
}

int strStr(char* haystack, char* needle){
    int sLen = strlen(needle);
    int tLen = strlen(haystack);
    if(sLen == 0){  //若模式串长度为0，则返回0
        return 0;
    }
    int next[sLen]; //初始化next数组
    getNext(next, needle);
    for(int i = 0, j = 0; i < tLen; i++){   //主串与模式串循环匹配
        while(j > 0 && haystack[i] != needle[j]){   
            j = next[j - 1];    //不等时模式串回退
        }
        if(haystack[i] == needle[j]){   //相等时j+1
            j++;
        }
        if(j == sLen){  //当模式串匹配完成则返回子串所在下标
            return i - sLen + 1;    //下标从0开始，减掉长度后要多加上1
        }
    }
    return -1;
}