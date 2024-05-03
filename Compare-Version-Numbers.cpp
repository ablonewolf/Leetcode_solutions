#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {

        int size1 = version1.size();
        int size2 = version2.size();

        int i = 0, j = 0;

        while (i < size1 || j < size2) {
            long long int sum1 = 0, sum2 = 0;

            while (i < size1 && version1[i] != '.') {
                sum1 = sum1 * 10 + version1[i] - '0';
                ++i;
            }

            while (j < size2 && version2[j] != '.') {
                sum2 = sum2 * 10 + version2[j] - '0';
                ++j;
            }

            if (sum1 < sum2) {
                return -1;
            }
            if (sum1 > sum2) {
                return 1;
            }

            ++i;
            ++j;
        }

        return 0;
    }
};


int main() {
    string version1 = "7.5.2.4";
    string version2 = "7.5.3";

    Solution solution;

    int result = solution.compareVersion(version1, version2);

    switch (result) {
    case -1:
        cout << "version1 is lower than version2." << endl;
        break;

    case 1:
        cout << "version1 is greater than version2." << endl;
        break;

    default:
        cout << "Both of the versions are equal." << endl;
        break;
    }

}