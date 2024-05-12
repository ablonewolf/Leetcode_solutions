#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double result = DBL_MAX; // Initialize result with maximum value
        vector<pair<double, int>> pairs;
        int size = quality.size();

        // Keep pushing the ratio and quality as the pair
        for (int i = 0; i < size; i++) {
            pair<double, int> currentPair = make_pair(wage[i] / (double)quality[i], quality[i]);
            pairs.push_back(currentPair);
        }

        // Sort the pairs based on the ratio of wage and quality
        sort(pairs.begin(), pairs.end(), [](const auto& left, const auto& right) {
            return left.first < right.first;
        });

        priority_queue<int> maxHeap;
        int totalQuality = 0;

        for (const auto& currentPair : pairs) {
            maxHeap.push(currentPair.second);
            totalQuality += currentPair.second;

            if (maxHeap.size() > k) {
                int currentMaxQuality = maxHeap.top();
                maxHeap.pop();
                totalQuality -= currentMaxQuality;
            }

            if (maxHeap.size() == k) {
                // Calculate the cost for hiring k workers
                double rate = currentPair.first;
                double cost = rate * totalQuality;
                result = min(result, cost);
            }
        }

        return result;
    }
};

int main() {

}