// https://leetcode.com/problems/merge-k-sorted-lists/

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

bool foo(ListNode* node1, ListNode* node2)
{
    return (node1->val < node2->val);
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size() == 0) return NULL;

        vector<ListNode*> all_nodes;
        for(ListNode* list : lists)
        {
            ListNode* last_node = list;
            while(last_node != NULL)
            {
                all_nodes.push_back(last_node);
                last_node = last_node->next;
            }
        }

        if(all_nodes.size() == 0) return NULL;

        sort(all_nodes.begin(), all_nodes.end(), foo);

        int n = all_nodes.size();
        ListNode* last_node = all_nodes[0];
        for(int i = 1; i < n; i++)
        {
            cout << last_node->val << endl;

            ListNode* sorted_node = all_nodes[i];
            last_node->next = sorted_node;
            last_node = last_node->next;
        }
        last_node->next = NULL;

        return all_nodes[0];
    }
};