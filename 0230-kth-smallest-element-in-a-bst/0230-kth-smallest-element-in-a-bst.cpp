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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        helper(root, pq);
        int cnt = 1;
        while(true){
            if(cnt == k) return pq.top();
            pq.pop();
            cnt++;
        }
        return 0;
    }
    void helper(TreeNode* root, priority_queue<int, vector<int>, greater<int>>& pq){
        if(root == NULL) return;
        pq.push(root->val);
        helper(root->left, pq);
        helper(root->right, pq);
    }
};