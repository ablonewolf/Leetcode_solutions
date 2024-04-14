#include <bits/stdc++.h>
using namespace std;


//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root)
            return 0;

        int ans = 0;

        if (root->left) {
            if (!root->left->left && !root->left->right)
                ans += root->left->val;
            else
                ans += sumOfLeftLeaves(root->left);
        }

        ans += sumOfLeftLeaves(root->right);

        return ans;
    }
};

int main() {
    Solution solution;
    TreeNode* node = new TreeNode(3);
    node->left = new TreeNode(9);
    node->right = new TreeNode(20);
    node->right->left = new TreeNode(15);
    node->right->right = new TreeNode(7);

    int sum = solution.sumOfLeftLeaves(node);
    cout << "Sum of left leaf nodes in this tree is " << sum << endl;
}