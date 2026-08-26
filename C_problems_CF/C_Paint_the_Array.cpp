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
//     vll a(n);
//     FOR(i, 0, n)
//     {
//         cin >> a[i];
//     }
//     ll d;
//     FOR(j, 0, 2)
//     {
//         d = a[j];
//         bool k = true;
//         FOR(i, 0, n - 1)
//         {
//             bool f = (a[i] % d == 0);
//             bool s = (a[i + 1] % d == 0);

//             if (f == s)
//             {
//                 k = false;
//                 break;
//             }
//         }
//         if (k)
//         {
//             cout << d << endl;
//             return;
//         }
//     }
//     cout << 0 << endl;
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

    vll a(n);

    FOR(i, 0, n)
    {
        cin >> a[i];
    }

    ll d1 = 0;
    ll d2 = 0;

    FOR(i, 0, n)
    {
        if (i % 2 == 0)
        {
            d1 = gcd(d1, a[i]);
        }
    }

    FOR(i, 0, n)
    {
        if (i % 2 == 1)
        {
            d2 = gcd(d2, a[i]);
        }
    }

    bool k = true;

    FOR(i, 0, n)
    {
        if (i % 2 == 1 && a[i] % d1 == 0)
        {
            k = false;
            break;
        }
    }

    if (k)
    {
        cout << d1 << endl;
        return;
    }

    k = true;

    FOR(i, 0, n)
    {
        if (i % 2 == 0 && a[i] % d2 == 0)
        {
            k = false;
            break;
        }
    }

    if (k)
    {
        cout << d2 << endl;
        return;
    }

    cout << 0 << endl;
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