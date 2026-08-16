// /// BISMILLAHIR RAHMANIR RAHEEM
// /// @cf - maheecse

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define ld long double
// #define vi vector<int>
// #define vll vector<long long>
// #define pii pair<int, int>
// #define pll pair<long long, long long>
// #define pb push_back
// #define fi first
// #define se second

// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define sz(x) ((int)(x).size())

// #define FOR(i, a, b) for (int i = (a); i < (b); i++)
// #define FORR(i, a, b) for (int i = (a); i >= (b); i--)

// using i128 = __int128_t;
// using u128 = __uint128_t;

// const int MOD = 1e9 + 7;
// const ll INF = 1e18;

// void cp_chere_dibo()
// {
//     ll n;
//     cin >> n;
//     vll v(n + 1);

//     ll alice = 0, bob = 0;

//     FOR(i, 1, n + 1)
//     {
//         cin >> v[i];
//     }

//     sort(v.begin() + 1, v.end(), greater<int>());

//     for (ll i = 1; i <= n; i++)
//     {
//         // cin >> v[i];
//         if (i % 2 == 1 && v[i] % 2 == 0)
//         {
//             alice += v[i];
//         }
//         else if (i % 2 == 0 && v[i] % 2 == 1)
//         {
//             bob += v[i];
//         }
//     }

//     if (alice > bob)
//         cout << "Alice" << endl;
//     else if (alice < bob)
//         cout << "Bob" << endl;
//     else
//         cout << "Tie" << endl;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int tc = 1;
//     cin >> tc;

//     while (tc--)
//     {
//         cp_chere_dibo();
//     }

//     return 0;
// }
/// BISMILLAHIR RAHMANIR RAHEEM
/// @cf - maheecse

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define fi first
#define se second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, a, b) for (int i = (a); i >= (b); i--)

using i128 = __int128_t;
using u128 = __uint128_t;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void cp_chere_dibo()
{
    int n;
    cin >> n;

    vector<ll> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll mn = *min_element(a.begin(), a.end());
    ll mx = *max_element(a.begin(), a.end());

    ll cmn = 0, cmx = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == mn)
            cmn++;

        if (a[i] == mx)
            cmx++;
    }

    if (mn == mx)
    {
        ll a = n * (n - 1);
        cout << a << endl;
    }
    else
    {
        ll a = cmn * cmx * 2;
        cout << a << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;

    while (tc--)
    {
        cp_chere_dibo();
    }

    return 0;
}