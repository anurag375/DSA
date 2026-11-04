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

class Solution {    // Iterative Preorder Traversal     =>  [uses single stack]
public:
    vector<int> preorderTraversal(TreeNode* root) {
    // t = n    s = auxiliary space ["n" in skewed tree, log n in balanced tree]
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            // 1> store root nodes in the "ans" vector:
            TreeNode* node = st.top();
            ans.push_back(node->val);
            st.pop();

            // 2> push to "st" in opposite order (i.e, R L) => [because of LIFO rule]
            if(node->right) st.push(node->right);   // *** in opposite order..
            if(node->left) st.push(node->left);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    
    vector<int> ans;
    ans = sol.preorderTraversal(root);     // Output: [1,2,3]
    for(int x : ans) {
        cout << x << " ";
    }
    return 0;
}