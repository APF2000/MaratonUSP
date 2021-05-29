#include <iostream>
#include <vector>
#include <thread>

using namespace std;

unsigned int sum = 0;
void add()
{
    sum += 1;
}

// 852ms sem thread
//
int main()
{
    vector<thread> v_t;
    for(int i = 0; i < 0xfffffff; i++)
    {
        add();
    }
    cout << "Final: " << sum << endl;

    return 0;
}