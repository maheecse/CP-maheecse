// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// int main()
// {
//     ll n, m;
//     cin >> n >> m;
//     vector<ll> v(n);
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> v[i];
//     }
//     vector<pair<ll, ll>> a;

//     for (ll i = 0; i < n; i++)
//     {
//         a.push_back({v[i], i});
//     }

//     for (ll i = 0; i < n; i++)
//     {
//         ll x;
//         cin >> x;

//         ll turn = (x + m - 1) / m;

//         a.push_back({turn, i + 1});
//     }
//     cout << max_element(a.begin(), a.end())->second << endl;
// }

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> a;

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        ll turn = (x + m - 1) / m;
        a.push_back({turn, i + 1});
    }

    cout << max_element(a.begin(), a.end())->second << endl;
}