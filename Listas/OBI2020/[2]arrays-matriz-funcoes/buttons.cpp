#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    vector<int> nums = { 0, 0, 0, 
                        0, 0, 0, 
                        0, 0, 0, 0 };
    cin >> k;

    int max = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            char num;
            cin >> num;

            int id = (num - '0');
            if(id >= 0 && id <= 9)
            {
                nums[id]++;
                int aux = nums[id];
                if(aux > max) max = aux;
            }
        }
    }
    cout << (max <= 2 * k ? "YES" : "NO") << endl;

    return 0;
}