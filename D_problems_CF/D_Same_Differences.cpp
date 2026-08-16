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

// #define FOR(i, a, b) for (ll i = (a); i < (b); i++)
// #define FORR(i, a, b) for (int i = (a); i >= (b); i--)

// using i128 = __int128_t;
// using u128 = __uint128_t;

// const int MOD = 1e9 + 7;
// const ll INF = 1e18;

// void cp_chere_dibo()
// {
//     ll n;
//     cin >> n;
//     vi v(n);
//     map<ll, ll> mp;
//     ll ans = 0;

//     for (ll i = 0; i < n; i++)
//     {
//         cin >> v[i];

//         ans += mp[v[i] - i];

//         mp[v[i] - i]++;
//     }

//     cout << ans << endl;
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
    string s[4];

    for (int i = 0; i < 4; i++)
        cin >> s[i];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int c = 0;

            if (s[i][j] == '#')
                c++;
            if (s[i][j + 1] == '#')
                c++;
            if (s[i + 1][j] == '#')
                c++;
            if (s[i + 1][j + 1] == '#')
                c++;

            if (c >= 3 || c <= 1)
            {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    //  cin >> tc;

    while (tc--)
    {
        cp_chere_dibo();
    }

    return 0;
}