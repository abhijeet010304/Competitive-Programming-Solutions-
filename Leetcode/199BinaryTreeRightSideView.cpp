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
    vector<int> rightSideView(TreeNode* root) {

        int maxL = -1;
        vector<int> ans;
        if(!root )return ans;
        inorder(root,maxL,0,ans);
        for(auto x:ans){
            cout<<x<<" ";
        }
        return ans;
    }
   void inorder(TreeNode* root,int &maxL,int current,vector<int>& ans){
        if(current>maxL){
            maxL = current;
            ans.push_back(root->val);
        }
        if(root->right)
            inorder(root->right,maxL,current+1,ans);
        if(root->left)
            inorder(root->left,maxL,current+1,ans);

    }
};
