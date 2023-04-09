// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int maxDepth(TreeNode* root) 
    {
        if(root == NULL) return 0;

        queue<pair<TreeNode*, int>> nodes_and_depths_to_visit;
        pair<TreeNode*, int> root_and_depth = { root, 1 };
        nodes_and_depths_to_visit.push(root_and_depth);
        int max_depth = 1;

        while(!nodes_and_depths_to_visit.empty())
        {
            pair<TreeNode*, int> node_and_depth_to_visit = nodes_and_depths_to_visit.front();
            nodes_and_depths_to_visit.pop();

            TreeNode* node_to_visit = node_and_depth_to_visit.first;
            TreeNode* left_child = node_to_visit->left;
            TreeNode* right_child = node_to_visit->right;

            int node_depth = node_and_depth_to_visit.second;
            max_depth = node_depth;

            pair<TreeNode*, int> root_and_depth_left = { left_child, node_depth + 1 };
            pair<TreeNode*, int> root_and_depth_right = { right_child, node_depth + 1 };

            if(left_child != NULL) nodes_and_depths_to_visit.push(root_and_depth_left);
            if(right_child != NULL) nodes_and_depths_to_visit.push(root_and_depth_right);
        }

        return max_depth;
    }
};