/*
LeetCode242. Valid Anagram
*/

#include <stdio.h>
#include <stdlib.h>

bool isAnagram(char * s, char * t){     //判断两字符串是否为有效的字母异位词
    int len_s = strlen(s), len_t = strlen(t);   //获取两个字符串的长度
    if(len_s != len_t){     //如果两个字符串长度不等则代表不是有效的字母异位词
        return false;
    }
    int tmp[26] = {0};  //用哈希法，先建立一个长度为26的数组（可称字母表），对应26个英文字母，每个位置的初始值设为0
    for(int i = 0; i < len_s; ++i){ //遍历字符串，将字符串各字母映射到字母表对应位置，并让该字母对应index+1
        tmp[s[i] - 'a']++;
    }
    for(int i = 0; i < len_t; ++i){ //遍历字符串，将字符串各字母映射到字母表对应位置，并让该字母对应index-1
        tmp[t[i] - 'a']--;
    }
    for(int i = 0; i < 26; ++i){
        if(tmp[i] != 0){    //如果tmp数组中(即字母表中)的Index不全为0，则代表出错
            return false;
        }
    }
    //tmp中所有Index都为0即s和t是字母异位词
    return true;
}