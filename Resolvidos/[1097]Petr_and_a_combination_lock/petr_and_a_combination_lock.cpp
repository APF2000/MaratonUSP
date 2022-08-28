//https://codeforces.com/problemset/problem/1097/B

#include <iostream>
#include <set>
#include <vector>

using namespace std;

// (a + b) % c == (a % c + b % c) % c

// 0x0 - 0xf
// 0000 - 1111

int consegue(vector<int> nums, int index, set<int> sums)
{
    int num = nums[index];
    
    set<int> aux_sums;
    for (int sum : sums)
    {   
        aux_sums.insert( (sum + num) % 360 );
        aux_sums.insert( (sum - num) % 360 );
    }
    sums = aux_sums;

    if(index != nums.size() - 1) 
        return consegue(nums, index + 1, sums);
    else{
        if(sums.find(0) != sums.end()) return 0;
        return -1;
    }
}

// 001
// 110
int consegue_alternativo(int n, vector<int> nums){
    int dois_a_n = ( 1 << n );

    for (int bits = 0; bits < dois_a_n; bits++)
    {
        int sum = 0;
        int aux_bits = bits;

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            int dig = aux_bits % 2;
            aux_bits /= 2;

            if(dig == 1) sum += num;
            else sum -= num;
        }
        if(sum % 360 == 0) return 0;
    }

    return -1;
}

int main()
{
    int n;
    int total = 0;
    vector<int> nums;
    //set<int> sums = { 0 };

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    total = consegue_alternativo(n, nums);

    if(total == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
