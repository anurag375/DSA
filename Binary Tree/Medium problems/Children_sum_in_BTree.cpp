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

class Solution {    // 239. Children Sum Property in Binary Tree
// my-way + gpt:    t=n  s=h [recursive stack space]
    int helper(TreeNode* node, bool& satisfied){
        if(!node) return 0;
        
        if(!node->left && !node->right) return node->val; // *U* leaf node = always (true) 

        int lSum = helper(node->left, satisfied);
        int rSum = helper(node->right, satisfied);
        
        if(node->val != lSum + rSum){
            satisfied = false;
        }

        return node->val;   // *U* just need to compare the child's value (NOT sum)
    }

public:
    bool checkChildrenSum(TreeNode* root) {
        bool satisfied = true;
        helper(root, satisfied);

        return satisfied;
    }
};


int main(){
    Solution sol;

    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(4);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);

    cout << sol.checkChildrenSum(root) << endl;     // Output: true (1)

    return 0;
}
