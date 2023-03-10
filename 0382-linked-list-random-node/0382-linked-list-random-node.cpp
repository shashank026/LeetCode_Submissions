/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    vector<int> nums;
public:
    Solution(ListNode* head) {
        ListNode* temp = head;
        while(temp){
            nums.push_back(temp->val);
            temp = temp->next;
        }
    }
    
    int getRandom() {
        // int pick = (rand() % (nums.size() - 0 ) + 0);
        int pick = rand() % nums.size();
        return nums[pick];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */