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
#include<bits/stdc++.h>
class Solution {
public:
    int ans = 0;
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) return 0;
        int nums = 0;
        helper(root, nums);
        return ans;
    }
    void helper(TreeNode* root, int& nums){
        nums *= 10;
        nums += root->val;
        if(root->left == nullptr and root->right == nullptr){
            ans += nums;
            return;
        }
        if(root->left != nullptr){
            helper(root->left, nums);
            nums /= 10;    
        }
        if(root->right != nullptr){
            helper(root->right, nums);
            nums /= 10;    
        }
    }
};