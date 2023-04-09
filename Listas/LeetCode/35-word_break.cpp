// https://leetcode.com/problems/word-break/

class Solution {
public:

    unordered_map<int, unordered_set<int>> graph;

    void create_graph(string s, vector<string>& wordDict)
    {
        for(string word : wordDict)
        {
            for(int i = 0; i < s.size(); i++)
            {
                int j = i;
                for(int k = 0; j < s.size(); j++, k++)
                {
                    if(word[k] != s[j]) 
                    {
                        break;
                    }

                    if(k == word.size() - 1) 
                    {
                        graph[i].insert(k + i + 1);
                        break;
                    }
                }
            }
        }
    }

    unordered_set<int> get_graph_connected_component(unordered_map<int, unordered_set<int>> g)
    {
        unordered_set<int> reachables_from_graph;
        queue<int> nodes_to_visit;
        nodes_to_visit.push(0);

        while(!nodes_to_visit.empty())
        {
            int node_id = nodes_to_visit.front();
            nodes_to_visit.pop();
            reachables_from_graph.insert(node_id);

            for(int adj_node : g[node_id])
            {
                bool node_was_not_visited = (reachables_from_graph.find(adj_node) == reachables_from_graph.end());
                if(node_was_not_visited)
                {
                    nodes_to_visit.push(adj_node);
                }                
            }
        }

        return reachables_from_graph;
    }

    bool wordBreak(string s, vector<string>& wordDict) 
    {        
        create_graph(s, wordDict);

        unordered_set<int> connected_component_graph = get_graph_connected_component(graph);

        int size = s.size();
        bool is_biggest_string_reachable = (connected_component_graph.find(size) != connected_component_graph.end());

        return is_biggest_string_reachable;
    }
};