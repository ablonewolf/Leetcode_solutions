#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int left = 0, right = size - 1;
        int leftMax = 0, rightMax = 0;

        int reservedWater = 0;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] < leftMax) {
                    reservedWater += (leftMax - height[left]);
                } else {
                    leftMax = height[left];
                }
                ++left;
            } else {
                if (height[right] < rightMax) {
                    reservedWater += (rightMax - height[right]);
                } else {
                    rightMax = height[right];
                }
                --right;
            }
        }

        return reservedWater;
    }
};

int main() {
    Solution solution;
    vector<int> heights = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    int trappedWater = solution.trap(heights);
    cout << "Total amount of trapped water is : " << trappedWater << endl;
}