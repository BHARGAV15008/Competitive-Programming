/*
34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 
Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

#include <algorithm>
#include <iostream>
#include <vector>

class SearchRange {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> output = {-1, -1};
        if (nums.empty()) return output;
        
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                output[0] = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                output[1] = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (output[0] > output[1]) return {-1, -1};
        return output;
    }
};

int main () {
    SearchRange sr;
    std::vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    std::vector<int> output;
    output = sr.searchRange(nums, target);
    std::cout << output.size();
    for (int cc : output)
        std::cout << cc << " ";

    return 0;
}