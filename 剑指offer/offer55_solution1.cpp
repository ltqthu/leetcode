/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 先序遍历
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (root == nullptr) return true;
        if (abs(getHeight(root->left) - getHeight(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int getHeight(TreeNode *root) {
        if (root == nullptr) return 0;
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);
        return left_height > right_height ? left_height + 1 : right_height + 1;
    }
};

int main() {
    TreeNode *root = new TreeNode(3);
    TreeNode *left1 = new TreeNode(9);
    TreeNode *right1 = new TreeNode(20);
    TreeNode *left1_left = new TreeNode(9);
    TreeNode *right1 = new TreeNode(20);

    return 0;
}