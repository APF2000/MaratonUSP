// https://leetcode.com/problems/reorder-list/

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
    void reorderList(ListNode* head) 
    {
        vector<ListNode*> nodes;

        ListNode* last_node = head;
        while(last_node != NULL)
        {
            nodes.push_back(last_node);
            last_node = last_node->next;
        }

        int n = nodes.size();
        for(int i = 0; i < (n - 1) / 2; i++)
        {
            nodes[i]->next = nodes[n - 1 - i]; 
            nodes[n - 1 - i]->next = nodes[i + 1];          
        }

        if(n % 2 == 0)
        {
            int first_middle_id = (n - 1) / 2;
            int second_middle_id = first_middle_id + 1;

            nodes[first_middle_id]->next = nodes[second_middle_id]; 
            nodes[second_middle_id]->next = NULL;    
        }
        else
        {
            int middle_id = (n - 1) / 2;
            nodes[middle_id]->next = NULL;    
        }
    }
};