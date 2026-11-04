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

class Solution {    // 100. Same Tree
// my-way: [modified preorder DFS traversal]
    void helper(TreeNode* pNode, TreeNode* qNode, bool &isSame){
        if(!pNode && !qNode) return;

        if(!pNode || !qNode || pNode->val != qNode->val){   // *U*
            isSame = false;
            // return;
        }
        if(pNode && qNode) helper(pNode->left, qNode->left, isSame);
        if(pNode && qNode) helper(pNode->right, qNode->right, isSame);

    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool isSame = true; // default
        helper(p, q, isSame);
        return isSame;
    }
};

int main(){
    Solution sol;

    TreeNode* pRoot = new TreeNode(1);
    pRoot->left = new TreeNode(2);
    pRoot->right = new TreeNode(3);

    TreeNode* qRoot = new TreeNode(1);
    qRoot->left = new TreeNode(2);
    qRoot->right = new TreeNode(3);

    cout << sol.isSameTree(pRoot, qRoot) << endl;     // Output: 1 (true)
    return 0;
}