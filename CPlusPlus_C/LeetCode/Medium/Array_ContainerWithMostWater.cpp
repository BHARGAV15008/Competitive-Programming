/*

11. Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1


Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/

#include <iostream>
#include <vector>
using namespace std;

// // Brute Force Approach

// class ContainerWithMostWater {
// public:
//     int maxArea(vector<int>& height) {
//         int maxCapacity = 0;
//         for (int i = 0; i < height.size(); i++) {
//             for (int j = i+1; j < height.size(); j++) {
//                 int posHeight;
//                 posHeight = min(height[i], height[j]);
//                 // cout << posHeight << endl;
//                 maxCapacity = max(maxCapacity, ((j-i) * (posHeight)));
//             }
//         }
//         return maxCapacity;
//     }
// };

// int main () {
//     vector<int> height = {1,8,6,2,5,4,8,3,7};
//     ContainerWithMostWater cwmw;
//     cout << cwmw.maxArea(height);
//     return 0;
// }

// OPtimized Aproach

class ContainerWithMostWater {
public:
    int maxArea(vector<int>& height) {
        int startPoint = 0, endPoint = height.size() - 1;
        int maxCapacity = 0;
        do {
            maxCapacity = max(maxCapacity,(endPoint - startPoint) * min(height[startPoint], height[endPoint]));
            height[startPoint] < height[endPoint] ? startPoint++ : endPoint--;
        } while (startPoint < endPoint);

        return maxCapacity;
    }
};

int main () {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    ContainerWithMostWater cwmw;
    cout << cwmw.maxArea(height);
    return 0;
}
