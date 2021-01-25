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
    vector<vector<int>> levelOrder(TreeNode* root) {
     vector<vector<int>>ret;
        if(!root)return ret;
      queue<TreeNode*> q;
       q.push(root) ;
        vector<TreeNode*> temp ;
        while(q.size()>0){
            temp.clear();
            while(q.size()>0){
                TreeNode* node = q.front();

                temp.push_back(node);
                q.pop();
            }
            vector<int> tempret;
            for(auto x: temp){
                tempret.push_back(x->val);
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
            }
            ret.push_back(tempret);



        }
        return ret;

    }
};
