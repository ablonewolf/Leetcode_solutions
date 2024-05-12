#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    static bool compareSecond(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // Sort in descending order of second items
    }
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long maxScore = 0, currentSum = 0;
        int size = nums1.size();
        vector<pair<int, int>> pairs;

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < size; i++) {
            pairs.push_back({ nums1[i], nums2[i] });
        }

        sort(pairs.begin(), pairs.end(), compareSecond);

        for (int i = 0; i < size; i++) {
            int currentItem = pairs[i].first;
            currentSum += currentItem;
            minHeap.push(currentItem);

            if (minHeap.size() > k) {
                int topItem = minHeap.top();
                currentSum -= topItem;
                minHeap.pop();
            }

            if (minHeap.size() == k) {
                maxScore = max(maxScore, currentSum * pairs[i].second);
            }
        }
        return maxScore;
    }
};

int main() {
    vector<int> nums1 = { 1,3,3,2 };
    vector<int> nums2 = { 2,1,3,4 };
    int k = 3;
    Solution solution;
    long long maxScore = solution.maxScore(nums1, nums2, k);
    cout << "The maximum subsequence score is: " << maxScore << "." << endl;
}
