/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        getleaves(root1, v1);
        getleaves(root2, v2);
        return v1==v2;
    }
    
    void getleaves(TreeNode* root, vector<int>&l){
        if(!root)return;
        
        if(!root->left and !root->right)l.push_back(root->val);
        getleaves(root->left, l);
        getleaves(root->right, l);
    }
};