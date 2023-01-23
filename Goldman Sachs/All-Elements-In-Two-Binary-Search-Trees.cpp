/*
Explanation:
The idea to solve this problem is to use a fact that in-order traversal of a BST is always sorted.
So we are storing In-order traversal of both the trees and compare them whichever is smallest we will 
store it in the result.
Finally after the In-order traversal we have all the elements sorted already in the vector and we return
it.

Time Complexity -> O(M+N) where M is number of nodes in BST1 and N is number of nodes in BST2
*/

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> st1,st2;
        vector<int> result;
        while(root1 || root2 || !st1.empty() || !st2.empty()){
            while(root1){
                st1.push(root1);
                root1 = root1->left;
            }
            while(root2){
                st2.push(root2);
                root2 = root2->left;
            }
            if(st2.empty() || (!st1.empty() && st1.top()->val < st2.top()->val)){
                root1 = st1.top();
                st1.pop();
                result.push_back(root1->val);
                root1 = root1->right;
            }else{
                root2 = st2.top();
                st2.pop();
                result.push_back(root2->val);
                root2 = root2->right;
            }
        }
        return result;
    }
};