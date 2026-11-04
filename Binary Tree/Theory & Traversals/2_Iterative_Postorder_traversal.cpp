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

class Solution {    // Iterative Postorder Traversal    => [uses two stacks]
public:
    vector<int> preorderTraversal(TreeNode* root) {
    // t = n    s = auxiliary space ["n" in skewed tree, log n in balanced tree]
        if(!root) return vector<int> {};
    
        vector<int> ans;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root);

        // 1> transfer elements from "st1" to "st2" (one at a time):
        while(!st1.empty()){    // * take 1 at a time..
            TreeNode* curr = st1.top();
            st1.pop();
            st2.push(curr);
            
            if(curr->left) st1.push(curr->left);    // *** push in same order..
            if(curr->right) st1.push(curr->right);   
            
        }

        // 2> take out all elements from "st2" and form "ans" vector
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
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
    ans = sol.preorderTraversal(root);     // Output: [2,3,1]
    for(int x : ans) {
        cout << x << " ";
    }
    return 0;
}