#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    public:
    TreeNode(int x, TreeNode *l, TreeNode *r) {
        val = x;
        left = l;
        right = r;
    }

    public:
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {    // 110. Balanced Binary Tree
// my-way + codestorywithMIK:   t=n  s=n [auxiliary space]
    int helper(TreeNode* node, bool &isBalanced){
        if(!node) return 0; // *U* "null" node height = 0

        int leftHeight = helper(node->left, isBalanced);
        int rightHeight = helper(node->right, isBalanced);

        if(abs(leftHeight - rightHeight) > 1) isBalanced = false;

        return max(leftHeight, rightHeight) + 1;    // *U*
    }

public:
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        helper(root, isBalanced);
        return isBalanced;
    }
};

int main(){
    Solution sol;

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << sol.isBalanced(root) << endl;     // Output: true (1)

    return 0;
}