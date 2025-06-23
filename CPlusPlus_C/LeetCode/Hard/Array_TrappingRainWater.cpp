/*
42. Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

#include <algorithm>
#include <iostream>
#include <vector>

class TrappingRainWater {
public:
    int trap(std::vector<int>& height) {
        if (height.size() <= 2) return 0;
        
        int startPoint = 0, endPoint = height.size() - 1, lMax = 0, rMax = 0, trappedWater = 0;
        
        while (startPoint < endPoint) {
            lMax = std::max(lMax, height.at(startPoint));
            rMax = std::max(rMax, height.at(endPoint));
            
            if (lMax <= rMax) {
                trappedWater += lMax - height.at(startPoint);
                startPoint++;
            } else {
                trappedWater += rMax - height.at(endPoint);
                endPoint--;
            }
        }
        
        return trappedWater;       
    }
};

int main () {
    TrappingRainWater trw;
    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << trw.trap(height);
    
    return 0;
}