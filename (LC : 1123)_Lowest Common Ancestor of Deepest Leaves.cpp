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

   pair<TreeNode*,int> solve(TreeNode* root , int depth){  //T.C : O(N)

     if(!root) return {nullptr , 0};

     auto left = solve(root->left,depth);
     auto right = solve(root->right,depth);

     if(left.second > right.second) return {left.first,left.second+1};
     if(right.second > left.second) return {right.first ,right.second+1};

     return {root , left.second+1};
   }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
      return solve(root,0).first;  
    }
};
