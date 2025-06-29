/*
41. First Missing Positive

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums. You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space. 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
*/
#include <algorithm>
#include <iostream>
#include <vector>

// Simple View
// class FirstMissingPositive {
// public:
//     int firstMissingPositive(std::vector<int>& nums) {
//         std::sort(nums.begin(), nums.end());
//         for (int i = 0; i < nums.size(); i++)
//             if (nums[i] < 1) nums.erase(nums.begin() + i);
//             else break;
        
//         std::sort(nums.begin(), nums.end());
//         for (int i = 0; i < nums.size(); i++)
//             if (nums[i] != i+1)
//                 return i+1;

//         return 1 + *std::max_element(nums.begin(), nums.end());
//     }
// };

class FirstMissingPositive {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};

int main () {
    FirstMissingPositive fmp;
    std::vector<int> nums = {1, 2, 0};
    std::cout << fmp.firstMissingPositive(nums);
    return 0;
}