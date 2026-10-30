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

class Solution {    // 145. Binary Tree Postorder Traversal
// t = n    s = auxiliary space ["n" in skewed tree, log n in balanced tree]
    void helper(TreeNode* node, vector<int>& ans){
        if(node == nullptr) return;

        helper(node->left, ans);
        helper(node->right, ans);
        ans.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
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
    ans = sol.postorderTraversal(root);     // Output: [3,2,1]
    for(int x : ans) {
        cout << x << " ";
    }
    return 0;
}