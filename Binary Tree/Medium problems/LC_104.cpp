#include<bits/stdc++.h>
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

class Solution {    // 104. Maximum Depth of Binary Tree
// my-way: [modified Preorder DFS traversal]
    void helper(TreeNode* node, int &level, int &maxLevel){
        if(!node) return;

        level++;
        maxLevel = max(maxLevel, level);

        helper(node->left, level, maxLevel);
        helper(node->right, level, maxLevel);
        level--;
    }
public:
    int maxDepth(TreeNode* root) {
        int level = 0;
        int maxLevel = 0;
        helper(root, level, maxLevel);
        return maxLevel;
    }
};

int main(){
    Solution sol;

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << sol.maxDepth(root) << endl;     // Output: 3
    return 0;
}