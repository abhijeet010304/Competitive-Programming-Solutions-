/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

class Solution {
    TreeNode *val,*ans;
public:

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        inorder(cloned, target->val,ans);
        return ans;
    }
    void inorder(TreeNode* cloned, int target,TreeNode* &ans){
        if(cloned==NULL) return ;
        inorder(cloned->left,target,ans);
        inorder(cloned->right,target,ans);
        if(target==cloned->val){ ans = cloned;
        }
    }
};
