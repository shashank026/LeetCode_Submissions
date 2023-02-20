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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* i = head, *j = head;
        int cnt = 0;
        vector<int> nums;
        while(j != nullptr){
            if(cnt == k){
                int temp = 0;
                while(temp < k){
                    i->val = nums[k-temp-1];
                    i = i->next;
                    temp++;
                }
                cnt = 0;
                nums.clear();
            }else{
                nums.push_back(j->val);
                cnt++;
                j = j->next;
            }
        }
        if(cnt == k){
            int temp = 0;
            while(temp < k){
                i->val = nums[k-temp-1];
                i = i->next;
                temp++;
            }
            cnt = 0;
            nums.clear();
        }
        return head;
    }
};