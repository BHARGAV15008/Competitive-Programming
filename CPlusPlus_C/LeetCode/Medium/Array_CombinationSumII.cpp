/*
40. Combination Sum II
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
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
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            current.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, current, results);
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