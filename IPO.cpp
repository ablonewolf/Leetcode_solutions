#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int size = profits.size();
        int totalGain = w; // Initialize totalGain with initial capital
        priority_queue<int> maxHeap;

        vector<pair<int, int>> projects; // Store projects as pairs of (capital, profit)
        for (int i = 0; i < size; ++i)
            projects.push_back({ capital[i], profits[i] });

        // Sort projects based on their capital requirements
        sort(projects.begin(), projects.end());

        k = min(k, size);
        int i = 0;
        while (k--) {
            while (projects[i].first <= totalGain && i < size) {
                maxHeap.push(projects[i].second);
                i++;
            }

            if (!maxHeap.empty()) {
                totalGain += maxHeap.top();
                maxHeap.pop();
            }
        }


        return totalGain;
    }
};

int main() {
    int k = 2, w = 0;
    vector<int> profits = { 1,2,3 };
    vector<int> capitals = { 0,1,1 };

    Solution solution;

    int totalGain = solution.findMaximizedCapital(k, w, profits, capitals);

    cout << "Maximized capital is " << totalGain << "." << endl;
}