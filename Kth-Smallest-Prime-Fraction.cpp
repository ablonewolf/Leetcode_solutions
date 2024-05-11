#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // Create a priority queue to store pairs of fractions
        priority_queue<pair<double, pair<int, int>>> fractionQueue;

        // Push the fractions formed by dividing each element by
        // the largest element into the priority queue
        for (int i = 0; i < arr.size(); i++)
            fractionQueue.push({ -1.0 * arr[i] / arr.back(), {i, arr.size() - 1} });

        // Iteratively remove the top element (smallest fraction) 
        // and replace it with the next smallest fraction
        while (--k > 0) {
            pair<int, int> currentPair = fractionQueue.top().second;
            fractionQueue.pop();
            // decrease the value of the tail to get the next greater element in the array
            currentPair.second--;
            fractionQueue.push({ -1.0 * arr[currentPair.first] / arr[currentPair.second],
                    {currentPair.first, currentPair.second} });
        }

        // Retrieve the kth smallest fraction from 
        // the top of the priority queue
        pair<int, int> result = fractionQueue.top().second;
        return { arr[result.first], arr[result.second] };
    }
};

int main() {

}