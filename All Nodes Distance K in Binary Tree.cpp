class Solution {
public:
    // Function to collect nodes at distance k
    void kDown(TreeNode* root, int k, TreeNode* blockNode, vector<int>& ans) {
        if (!root || root == blockNode || k < 0) return;
        if (k == 0) {
            ans.push_back(root->val);
            return;
        }
        kDown(root->left, k - 1, blockNode, ans);
        kDown(root->right, k - 1, blockNode, ans);
    }

    // Function to find the target and compute distances
    int distanceK(TreeNode* root, TreeNode* target, int k, vector<int>& ans) {
        if (!root) return -1;
        if (root == target) {
            kDown(root, k, nullptr, ans);
            return 1; // Distance to the root (itself)
        }

        int leftDistance = distanceK(root->left, target, k, ans);
        if (leftDistance != -1) {
            // Target is in the left subtree
            kDown(root, k - leftDistance, root->left, ans);
            return leftDistance + 1;
        }

        int rightDistance = distanceK(root->right, target, k, ans);
        if (rightDistance != -1) {
            // Target is in the right subtree
            kDown(root, k - rightDistance, root->right, ans);
            return rightDistance + 1;
        }

        return -1; // Target not found in either subtree
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        distanceK(root, target, k, ans);
        return ans;
    }
};
