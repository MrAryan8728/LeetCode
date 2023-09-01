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
        vector<int> ans;
        if(!root) return {};
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            TreeNode * elem = q.front();
            q.pop();
            ans.push_back(elem->val);
            if(elem->right){q.push(elem->right);}
            if(elem->left){q.push(elem->left);}
            for(int i = 1;i<s;++i){
                TreeNode * temp = q.front();
                q.pop();      
            if(temp->right){q.push(temp->right);}
            if(temp->left){q.push(temp->left);}
            }
        }
        return ans;
    }
};