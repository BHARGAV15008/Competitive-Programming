/*
16. 3Sum Closest

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104
*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// BruteForse Approach

class ThreeSumClosest {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minClosest = INT_MAX;
        int findClosest = INT_MAX;
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i+1; j < nums.size() - 1; j++) {
                for (int k = j+1; k < nums.size(); k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    int distance = abs(sum - target);
                    if (distance < findClosest)
                        findClosest = distance, minClosest = sum;
                }
            }
        }
        return minClosest;
    }
};

int main () {
    ThreeSumClosest tsc;
    vector<int> nums = {10,20,30,40,50,60,70,80,90};
    int target = 1;
    cout << tsc.threeSumClosest(nums, target);
    return 0;
}