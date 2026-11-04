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

class Solution {    // 103. Binary Tree Zigzag Level Order Traversal
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    // my-way: [modified BFS traversal]
        if(!root) return vector<vector<int>>{};

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;

        bool rev = false;   // tracks whick one (subarray) to reverse..

        while(!q.empty()){
            vector<TreeNode*> subArr;
            vector<int> subArrVal;
            
            while(!q.empty()){
                TreeNode* curr = q.front();
                subArr.push_back(curr);
                subArrVal.push_back(curr->val);
                q.pop();
            }

            if(rev){
                reverse(subArrVal.begin(), subArrVal.end());
                rev = false;
            }else{
                rev = true;
            }

            ans.push_back(subArrVal);

            // refill the q:
            for(TreeNode* node:subArr){
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return ans;
    }
};

int main(){
    Solution sol;

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = sol.zigzagLevelOrder(root);     // Output: [[3],[20,9],[15,7]]

    for(vector<int> subArr:ans){
        cout << "[";
        for(int num:subArr) 
            cout << num << " ";
        cout << "] ";
    }
    return 0;
}