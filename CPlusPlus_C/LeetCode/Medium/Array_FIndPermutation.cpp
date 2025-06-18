#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FindPermutation {
public:

    void permutation(vector<int>& nums, vector<vector<int>>& permutations, int start) {
        if (start == nums.size()) {
            permutations.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            permutation(nums, permutations, start + 1);
            swap(nums[start], nums[i]);
        }
    }


    vector<vector<int>> findPermutation(vector<int>& nums) {
        vector<vector<int>> permutations;
        sort(nums.begin(), nums.end());
        permutation(nums, permutations, 0);
        return permutations;
    }
};

int main() {
    FindPermutation np;
    vector<int> nums = {1, 2, 3, 6, 4};
    vector<vector<int>> result = np.findPermutation(nums);
    

    for (const auto& perm : result)
        for (int num : perm)
            cout << num << " ";

    return 0;
}