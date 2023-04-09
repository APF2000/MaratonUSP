// https://leetcode.com/problems/same-tree/

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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if(p == NULL) return (q == NULL);
        if(q == NULL) return (p == NULL);

        if(p->val != q->val) return false;

        bool right_ok = isSameTree(p->right, q->right);
        bool left_ok = isSameTree(p->left, q->left);

        return right_ok && left_ok;
    }
};