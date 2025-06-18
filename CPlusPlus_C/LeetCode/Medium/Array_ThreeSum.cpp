/*
15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets. 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

// BruteFroce Approaches;

// class ThreeSum {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>> setResults;
//         vector<vector<int>> results;
//         vector<int> phaseI;
//         for (int i = 0; i < nums.size(); i++) {
//             for (int j = i+1; j < nums.size(); j++) {
//                 for (int k = j+1; k < nums.size(); k++) {
//                     phaseI.clear();
//                     if (nums[i] + nums[j] + nums[k] == 0) {
//                         phaseI.push_back(nums[i]);
//                         phaseI.push_back(nums[j]);
//                         phaseI.push_back(nums[k]);
//                         sort(phaseI.begin(), phaseI.end());
//                         setResults.insert(phaseI);
//                     } else {
//                         continue;
//                     }
//                 }
//             }
//         }
//         results.reserve(setResults.size()); // Optional: reserve space to avoid reallocations
//         for (const auto& vec : setResults) {
//             results.push_back(vec);
//         }

//         return results;
//     }
// };

// int main () {
//     ThreeSum ts;
//     vector<int> nums = {-1,0,1,2,-1,-4};
//     vector<vector<int>> results = ts.threeSum(nums);
//     // cout << results.size();
//     for (vector c : results){
//         for (int i : c)
//             cout << i << " ";
//         cout << endl;
//     }

//     return 0;
// }


// Optimized problem


class ThreeSum {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        set<vector<int>> setResults;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++){
            int startPoint = i + 1, endPoint  = nums.size() - 1;
            do {
                if (nums[startPoint] + nums[i] + nums[endPoint] == 0) {
                    setResults.insert({nums[i], nums[startPoint], nums[endPoint]});
                    startPoint++;
                    endPoint--;
                }
                else if (nums[startPoint] + nums[i] + nums[endPoint] > 0){
                    endPoint--; 
                    continue;
                }
                else {
                    startPoint++;
                    continue;
                }
            } while (startPoint < endPoint);
        }

        results.reserve(setResults.size());
        for (const auto& vec : setResults) {
            results.push_back(vec);
        }
        
        return results;
    }
};

int main () {
    ThreeSum ts;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> results = ts.threeSum(nums);
    // cout << results.size();
    for (vector c : results){
        for (int i : c)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}