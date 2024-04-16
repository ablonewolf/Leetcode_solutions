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
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<TreeNode*> q;
        q.push(root);

        // For level 1, we have no parent node, so we just return the root with
        // new children.
        if (depth == 2) {
            TreeNode* leftNode = new TreeNode(val);
            TreeNode* rightNode = new TreeNode(val);
            leftNode->left = root->left;
            rightNode->right = root->right;
            root->left = leftNode;
            root->right = rightNode;
            return root;
        }

        int currentDepth = 1;
        while (!q.empty()) {
            int size = q.size();
            // We only want to process nodes at the level just before the
            // desired depth
            if (currentDepth == depth - 1) {
                for (int i = 0; i < size; ++i) {
                    TreeNode* current = q.front();
                    q.pop();
                    // Add new nodes as children of the current nodes
                    TreeNode* leftNode = new TreeNode(val);
                    leftNode->left = current->left;
                    current->left = leftNode;
                    TreeNode* rightNode = new TreeNode(val);
                    rightNode->right = current->right;
                    current->right = rightNode;
                }
                break; // No need to continue BFS beyond this level
            } else {
                // Continue BFS until we reach the level just before the
                // desired depth
                for (int i = 0; i < size; ++i) {
                    TreeNode* current = q.front();
                    q.pop();
                    if (current->left)
                        q.push(current->left);
                    if (current->right)
                        q.push(current->right);
                }
                ++currentDepth;
            }
        }

        return root;
    }
};

int main() {

}