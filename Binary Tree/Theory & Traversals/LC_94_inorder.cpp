#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int x, TreeNode *l, TreeNode *r) {
        val = x;
        left = l;
        right = r;
    }
};

class Solution {    // 94. Binary Tree Inorder Traversal
// my-way:    t = n    s = auxiliary space ["n" in skewed tree, log n in balanced tree]
    void helper(TreeNode* node, vector<int>& ans){
        if(node == nullptr) return;

        helper(node->left, ans);
        ans.push_back(node->val);
        helper(node->right, ans);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        helper(root, ans);
        return ans;
    }
};

int main(){
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> ans;
    ans = sol.inorderTraversal(root);     // Output: [1,3,2]
    for(int x : ans) {
        cout << x << " ";
    }
    return 0;
}
