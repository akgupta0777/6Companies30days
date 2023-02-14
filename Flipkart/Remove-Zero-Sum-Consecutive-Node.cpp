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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0,head);
        int prefix = 0;
        unordered_map<int,ListNode*> seenPrefix;
        ListNode* temp = dummy;
        while(temp){
            prefix+=temp->val;
            seenPrefix[prefix] = temp;
            temp = temp->next;
        }
        prefix = 0;
        temp = dummy;
        while(temp){
            prefix+=temp->val;
            temp->next = seenPrefix[prefix]->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};