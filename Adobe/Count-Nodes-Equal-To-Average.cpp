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
    int nodes = 0;
    pair<int,int> dfs(TreeNode* root){
        if(!root) return {0,0};
        auto [leftSum,leftCount] = dfs(root->left);
        auto [rightSum,rightCount] = dfs(root->right);
        int sum = leftSum+rightSum+root->val;
        int count = leftCount+rightCount+1;
        if(root->val == (sum/count)) nodes++;
        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return nodes;
    }
};