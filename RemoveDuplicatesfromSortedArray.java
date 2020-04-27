/**
 * LeetCode_数组_删除排序数组中的重复项
 * @author HYT
 */
package leetcode;
import java.util.Arrays;

public class RemoveDuplicatesfromSortedArray {

     static int removeDuplicates(int[] nums){
        if(nums.length == 0) return 0;
        int i = 0;
        for(int j = 1;j<nums.length;j++){
            if(nums[j] != nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }

    public static void main(String[] args){
       //Solution

        int[] nums1 = new int[]{1,1,2};
        removeDuplicates(nums1);
        System.out.println(Arrays.toString(nums1));
    }
}
