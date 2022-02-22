/*
LeetCode344. Reverse String
*/

#include <stdio.h>
#include <stdlib.h>

void reverseString(char* s, int sSize){ //反转字符串
    int left = 0;
    int right = sSize - 1;
    while(left < right){
        char temp = s[left];
        s[left++] = s[right];   //双指针法，left>=right时反转完成
        s[right--] = temp;
    }
}