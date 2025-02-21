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
class FindElements {
    unordered_set<int> st;  //S.C : O(n)

public:
    void contaminated(TreeNode*& root) { //T.C : O(n)

        queue<TreeNode*> q;
        root->val = 0;
        q.push(root);

        while (!q.empty()) {

            auto front = q.front();
            q.pop();

            st.insert(front->val);
            if (front->left) {
                front->left->val = 2 * front->val + 1;
                q.push(front->left);
            }

            if (front->right) {
                front->right->val = 2 * front->val + 2;
                q.push(front->right);
            }
        }
    }

    FindElements(TreeNode* root) {
        st.clear();
        contaminated(root);
    }

    bool find(int target) {

        if (st.find(target) != st.end()) //T.C : O(1)
            return true;

        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
