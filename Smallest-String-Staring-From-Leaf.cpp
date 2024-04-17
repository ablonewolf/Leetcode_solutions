#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
private:
    void DFS(TreeNode* node, string temp, string& smallest) {
        if (!node) {
            return;
        }
        temp = char('a' + node->val) + temp;

        if (!node->left && !node->right) {
            if (smallest.empty() || temp < smallest) {
                smallest = temp;
            }
        }
        DFS(node->left, temp, smallest);
        DFS(node->right, temp, smallest);
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        string temp = "";
        string smallest = "";

        DFS(root, temp, smallest);

        return smallest;
    }
};

int main() {

}