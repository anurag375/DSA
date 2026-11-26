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

class Solution {    // 101. Symmetric Tree
// my-way + gpt:    t=n  s=h [recursive stack space]
    void helper(TreeNode* l, TreeNode* r, bool& isSym){ //
        if(!l && !r) return;

        if(!l || !r || l->val != r->val){
            isSym = false;
            return;
        }

        helper(l->left, r->right, isSym);   // Outer pair
        helper(l->right, r->left, isSym);   // Inner pair
    }

public:
    bool isSymmetric(TreeNode* root) {
        bool isSym = true;
        helper(root->left, root->right, isSym);
        
        return isSym;
    }
};

int main(){
    Solution sol;

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(2);

    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(3);

    cout << sol.isSymmetric(root) << endl;     // Output: false (0)

    return 0;
}
