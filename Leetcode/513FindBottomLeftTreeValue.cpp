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
    int findBottomLeftValue(TreeNode* root) {
        int maxL = -1;

        int ans = root->val;
        inorder(root,maxL,0,ans);
        return ans ;
    }
    void inorder(TreeNode* root, int &maxL, int current,int &ans){
        if(current>maxL and !root->left and !root->right){
            ans = root->val;
            maxL = current;
        }

        if(root->left){
            inorder(root->left,maxL,current+1,ans);
        }
        if(root->right){
            inorder(root->right,maxL,current+1,ans);
        }
    }

};
