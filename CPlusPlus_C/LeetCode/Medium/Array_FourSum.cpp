/*
18. 4Sum

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 
Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Oneway 

// class FourSum {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         vector<vector<int>> results;
//         set<vector<int>> setResults;
//         sort(nums.begin(), nums.end());
        
//         for (int j = 0; j < nums.size() - 3; j++) {
//             for (int i = j + 1; i < nums.size() - 2; i++) {
//                 int startPoint = i + 1, endPoint = nums.size() - 1;
//                 do {
//                     if (startPoint >= nums.size() || endPoint < 0) break;
//                     if (nums[startPoint] + nums[i] + nums[j] + nums[endPoint] == target) {
//                         setResults.insert({nums[j], nums[i], nums[startPoint], nums[endPoint]});
//                         startPoint++;
//                         endPoint--;
//                     }
//                     else if (nums[startPoint] + nums[i] + nums[j] + nums[endPoint] > target){
//                         endPoint--; 
//                         continue;
//                     }
//                     else {
//                         startPoint++;
//                         continue;
//                     }
//                 } while (startPoint < endPoint);
//             }
//         }

//         results.reserve(setResults.size());
//         for (const auto& vec : setResults) {
//             results.push_back(vec);
//         }
        
//         return results;
//     }
// };


// // Secondway

// class FourSum {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         vector<vector<int>> results;
//         set<vector<int>> setResults;
//         sort(nums.begin(), nums.end());
        
//         for (int j = 0; j < nums.size() - 3; j++) {
//             for (int i = j + 1; i < nums.size() - 2; i++){
//                 int startPoint = i + 1, endPoint = nums.size() - 1;
//                 do {
//                     if (startPoint >= endPoint || startPoint >= nums.size() || endPoint < 0) break;
//                     if (nums[startPoint] + nums[i] + nums[j] + nums[endPoint] == target) {
//                         setResults.insert({nums[j], nums[i], nums[startPoint], nums[endPoint]});
//                         startPoint++;
//                         endPoint--;
//                     }
//                     else if (nums[startPoint] + nums[i] + nums[j] + nums[endPoint] > target){
//                         endPoint--; 
//                         continue;
//                     }
//                     else {
//                         startPoint++;
//                         continue;
//                     }
//                 } while (true);
//             }
//         }

//         results.reserve(setResults.size());
//         for (const auto& vec : setResults) {
//             results.push_back(vec);
//         }
        
//         return results;
//     }
// };


// ThirdWay

class FourSum {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        set<vector<int>> setResults;
        if (nums.size() < 4) return results;
        sort(nums.begin(), nums.end());
        
        for (int j = 0; j < nums.size() - 3; j++) {
            if (j > 0 && nums[j] == nums[j - 1]) continue;
            for (int i = j + 1; i < nums.size() - 2; i++) {
                if (i > j + 1 && nums[i] == nums[i - 1]) continue;
                int startPoint = i + 1, endPoint = nums.size() - 1;
                do {
                    if (startPoint >= endPoint || startPoint >= nums.size() || endPoint < 0) break;
                    long long sum = (long long)nums[startPoint] + nums[i] + nums[j] + nums[endPoint];
                    if (sum == target) {
                        setResults.insert({nums[j], nums[i], nums[startPoint], nums[endPoint]});
                        startPoint++;
                        endPoint--;
                    }
                    else if (sum > target) {
                        endPoint--; 
                        continue;
                    }
                    else {
                        startPoint++;
                        continue;
                    }
                } while (true);
            }
        }

        results.reserve(setResults.size());
        for (const auto& vec : setResults) {
            results.push_back(vec);
        }
        
        return results;
    }
};

int main () {
    FourSum fs;
    vector<int> nums = {2,2,2,2,2};
    int target = 8;
    vector<vector<int>> results = fs.fourSum(nums, target);
    // cout << results.size();
    for (vector c : results){
        for (int i : c)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}