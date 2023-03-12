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
    ListNode* mergeKLists(vector<ListNode*>& list) {
        if(list.size() == 0) return NULL;
        priority_queue <int, vector<int>, greater<int>> pq;
        for(int i=0;i<list.size();++i){
            if(list[i] == NULL) continue;
            ListNode* temp = list[i];
            while(temp != NULL){
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        if(pq.size() == 0) return NULL;
        list.clear();
        ListNode* head = new ListNode(pq.top());
        pq.pop();
        ListNode* temp = head;
        while(!pq.empty()){
            temp->next = new ListNode(pq.top());
            pq.pop();
            temp = temp->next;
        }
        return head;
    }
};