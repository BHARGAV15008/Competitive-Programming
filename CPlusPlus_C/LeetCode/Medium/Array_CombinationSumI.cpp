/*
39. Combination Sum

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class CombinationSum {
public:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& results) {
        if (target == 0) {
            results.push_back(current);
            return;
        }
        if (target < 0) return;
        
        for (int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, current, results);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, current, results);
        return results;
    }
};

int main() {
    CombinationSum cs;
    vector<int> nums = {2, 3, 5};
    int target = 8;
    vector<vector<int>> results = cs.combinationSum(nums, target);
    for (const auto& c : results) {
        for (int i : c) cout << i << " ";
        cout << endl;
    }
    return 0;
}