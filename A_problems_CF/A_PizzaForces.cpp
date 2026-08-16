#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll tc;
    cin >> tc;

    while (tc--)
    {
        ll n, a = 0;
        cin >> n;
        if (n <= 6)
        {
            cout << 15 << endl;
            continue;
        }
        else if (n <= 8)
        {
            cout << 20 << endl;
            continue;
        }
        else if (n <= 10)
        {
            cout << 25 << endl;
            continue;
        }
        else if (n % 2 != 0)
        {
            a = ((n + 1) * 5) / 2;
            cout << a << endl;
        }
        else
        {
            a = (n * 5) / 2;
            cout << a << endl;
        }
    }
}