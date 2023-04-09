// https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        bool has_cycle = false;
        ListNode *next_node = head;
        unordered_set<ListNode*> visited_nodes;

        while(next_node != NULL)
        {
            bool was_node_seen = (visited_nodes.find(next_node) != visited_nodes.end());
            if(was_node_seen)
            {
                has_cycle = true;
                break;
            }

            visited_nodes.insert(next_node);
            next_node = next_node->next;
        }

        return has_cycle;
    }
};