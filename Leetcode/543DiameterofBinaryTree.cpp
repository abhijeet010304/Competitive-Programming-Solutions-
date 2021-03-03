class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res=-1e9;
        int ans = helper(root,res);
        return max(res-1,0);
    }
    int helper(TreeNode* root, int &res){
        if(!root)return 0;
        
        int l = helper(root->left,res);
        int r = helper(root->right,res);
        
        int temp = max(l,r)+1;
        
        res = max(res,l+r+1);
        return temp;
            
    }
};
