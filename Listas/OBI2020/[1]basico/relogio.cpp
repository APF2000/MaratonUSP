#include <bits/stdc++.h>


using namespace std;


int main()
{
    int h, p, f, d;
    cin >> h >> p >> f >> d;

    int dp = ( ( p - f ) * d + 16) % 16;
    int dh = ( ( h - f ) * d + 16) % 16;

    cout << ((dh < dp) ? 'S' : 'N') << endl;
}