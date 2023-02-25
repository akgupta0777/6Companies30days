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
    pair<int,int> getMaxLoot(TreeNode* root){
        if(!root)
            return {0,0};

        pair<int,int> left = getMaxLoot(root->left);
        pair<int,int> right = getMaxLoot(root->right);

        int lootWithRoot = root->val + left.first + right.first;
        int lootWithoutRoot = max(left.first,left.second)+max(right.first,right.second);
        pair<int,int> result = {lootWithoutRoot,lootWithRoot}; 
        return result;      
    }

    int rob(TreeNode* root) {
        pair<int,int> result = getMaxLoot(root);
        return max(result.first,result.second);
    }
};