/*
LeetCode383. Ransom Note
*/

#include <stdio.h>
#include <stdlib.h>

bool canConstruct(char * ransomNote, char * magazine){
    int ranLen = strlen(ransomNote), magLen = strlen(magazine);
    int arr[26] = {0};
    for(int i = 0; i < magLen; i++){
        arr[magazine[i] - 'a']++;
    }
    for(int j = 0; j < ranLen; j++){
        arr[ransomNote[j] - 'a']--;
        if(arr[ransomNote[j] - 'a'] < 0){
            return false;
        }
    }
    return true;
}