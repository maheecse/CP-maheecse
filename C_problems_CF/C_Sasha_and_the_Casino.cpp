#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        ll k, x, a;
        cin >> k >> x >> a;

        __int128 sum = 0;

        for (int i = 1; i <= x + 1; i++)
        {
            __int128 juaa = sum / (k - 1) + 1;
            sum += juaa;

            if (sum > a)
                break;
        }

        if (sum <= a)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}