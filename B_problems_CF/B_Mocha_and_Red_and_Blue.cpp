#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll tc;
    cin >> tc;

    while (tc--)
    {
        ll n, a, b, c = LLONG_MAX;
        cin >> n;
        vector<ll> cd;
        for (ll i = 1; i * i <= n; i++)
        {
            a = i;
            b = n - i;
            c = min(c, lcm(a, b));
            cd.push_back(lcm(a, b));
        }
        for (ll i = 0; i < cd.size(); i++)
        {
            if (cd[i] == c)
            {
                cout << i + 1 << " " << n - i - 1 << endl;
                break;
            }
        }
    }
}