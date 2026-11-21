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

class Solution {    // 543. Diameter of Binary Tree
// my-way: [for each node, find max-length in both sides, then add both]
// t=n  s=n [auxiliary space]
    int helper(TreeNode* node, int& maxi){
        if(!node) return 0;

        int leftLen = helper(node->left, maxi);
        int rightLen = helper(node->right, maxi);
        maxi = max(maxi, leftLen + rightLen);

        return max(leftLen, rightLen) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        helper(root, maxi); // no need to store returned value
        return maxi;
    }
};

int main(){
    Solution sol;

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << sol.diameterOfBinaryTree(root) << endl;     // Output: 3

    return 0;
}