class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;

        while (root != nullptr || !st.empty()) {

            // Go as far left as possible
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }

            // Process the node
            root = st.top();
            st.pop();

            ans.push_back(root->val);

            // Now explore right subtree
            root = root->right;
        }

        return ans;
    }
};