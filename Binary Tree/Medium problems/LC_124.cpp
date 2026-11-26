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

class Solution {    // 124. Binary Tree Maximum Path Sum
// @codestorywithMIK:    t=n  s=h [recursive stack space]
    int helper(TreeNode* node, int& maxSum) {
        if(!node) return 0;

        int lSum = helper(node->left, maxSum);
        int rSum = helper(node->right, maxSum);

        int neeche_hi_acha_hai = lSum + rSum + node->val;
        int koi_ek_side_acha = max(lSum, rSum) + node->val;
        int root_acha = node->val;

        maxSum = max({maxSum, neeche_hi_acha_hai, koi_ek_side_acha, root_acha});

        return max(koi_ek_side_acha, root_acha);   // **U**
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; // *U* No "0"; because node values can store -ves 

        helper(root, maxSum);
        return maxSum;
    }
};

int main(){
    Solution sol;

    TreeNode* root = new TreeNode(-10);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << sol.maxPathSum(root) << endl;     // Output: 42

    return 0;
}
