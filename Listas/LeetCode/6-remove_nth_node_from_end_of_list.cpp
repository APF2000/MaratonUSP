// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    int size_of_list(ListNode* head)
    {
        ListNode *next_node = head;
        int size = 0;

        while(next_node != NULL)
        {
            next_node = next_node->next;
            size++;
        }

        return size;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *next_node = head;
        //ListNode *last_node = head;

        int size = size_of_list(head);

        for(int i = 0; i < size - n - 1; i++)
        {
            //last_node = next_node;
            next_node = next_node->next;
        }

        if(n == size) return head->next;

        next_node->next = next_node->next->next;
        
        return head;
    }
};