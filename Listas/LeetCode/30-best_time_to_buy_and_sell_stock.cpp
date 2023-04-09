// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<pair<int, int>> prices_and_ids(n);
        for(int i = 0; i < n; i++)
        {
            pair<int, int> price_and_id;
            price_and_id.first = prices[i];
            price_and_id.second = i;

            prices_and_ids[i] = price_and_id;
        }

        sort(prices_and_ids.begin(), prices_and_ids.end(), greater<pair<int, int>>());

        int profit = 0;
        for(int i = 0; i < n; i++)
        {
            int buy_price = prices[i];
            int buy_day = i;

            for(int j = 0; j < n; j++)
            {
                int sell_price = prices_and_ids[j].first;
                int sell_day = prices_and_ids[j].second;

                int new_profit = sell_price - buy_price;

                // if profit is not better, no reason for searching anymore
                if(new_profit <= profit) break;

                // if profit is better, see if day is valid
                if(buy_day < sell_day)
                {
                    profit = new_profit;
                    break;
                }
            }
        }

        return profit;
    }
};