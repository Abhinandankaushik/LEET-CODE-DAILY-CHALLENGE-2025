/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public: 
    unordered_map<int,int>mp; //S.C : O(n);

    TreeNode* solve(int preStart, int preEnd, int postStart,
                    vector<int>& preorder, vector<int>& postorder) { //T.C : O(2*n) + system stack (maximum depth of tree)
                                                                           //--> O(2*n) + O(logn) 

        if (preStart > preEnd)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);

        if (preStart == preEnd)
            return root;

        int next = preorder[preStart + 1];
       
         //using map to avoid again and again do looping --> taking extra space to save extra time 
         int j = mp[next];

        int size = j - postStart + 1;

        root->left = solve(preStart + 1, preStart + size, postStart, preorder,
                           postorder);
        root->right =
            solve(preStart + size + 1, preEnd, j + 1, preorder, postorder);

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int n = preorder.size();

         for(int i =0 ;i < n ;i ++ )  //T.C : O(n)
         mp[postorder[i]] = i;

        return solve(0, n - 1, 0, preorder, postorder);
    }
};
