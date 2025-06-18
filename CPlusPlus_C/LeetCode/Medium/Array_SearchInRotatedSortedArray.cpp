/*
33. Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2]. Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
*/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class SearchInSortedRotatedArray {
public:
    // bool binarySearch (vector<int> nums, int target, int startPoint, int endPoint) {
    //     if (startPoint == endPoint && nums[startPoint] != target) return false; 
    //     int mid = abs((startPoint + endPoint)/2);
    //     if (nums[mid] == target) return true;
    //     else if (nums[mid] > target) return binarySearch(nums, target, startPoint, mid);
    //     else return binarySearch(nums, target, mid, endPoint);
    //     return false;
    // }

    int search(vector<int>& nums, int target) {
        vector<int> sortNums = nums;
        sort(sortNums.begin(), sortNums.end());\
        for (int a: sortNums) cout << a << " ";
        cout << endl;
        if (binary_search(sortNums.begin(), sortNums.end(), target)) {
            for (int i = 0; i < nums.size(); i++)
                if (nums[i] == target) return i;
        }
        return -1;
    }
};

int main() {
    SearchInSortedRotatedArray sisra;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << sisra.search(nums, target);

    return 0;
}