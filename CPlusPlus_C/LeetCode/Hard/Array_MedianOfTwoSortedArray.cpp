/*
4. Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class MedianOfTwoSortedArray {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mergeNum (nums1.size() + nums2.size());
        double result;
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), mergeNum.begin());
        if (mergeNum.size()%2 == 0){
            result =  double(mergeNum[mergeNum.size()/2 - 1] + mergeNum[mergeNum.size()/2])/2;
        }
        else
            result =  double(mergeNum[(mergeNum.size() - 1)/2]);
        
        return result;
    }
};

int main () {
    MedianOfTwoSortedArray motsa;
    vector<int> nums1 = {1, 3}, nums2 = {2, 6};
    cout << motsa.findMedianSortedArrays(nums1, nums2);
    return 0;
}