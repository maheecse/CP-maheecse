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
    // int n;
    // cin >> n;
    // vi v(n);
    // int f = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     cin >> v[i];
    //     if (v[i] > n)
    //     {
    //         int f = 1;
    //     }
    // }
    // if (f == 1)
    // {
    //     cout << "NO" << endl;
    //     return;
    // }
    // int c = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (v[i] <= i)
    //     {
    //         c++;
    //     }
    // }

    // cout << "NO\n";
    int n;
    cin >> n;

    vi v(n + 1);
    int f = 0;

    FOR(i, 1, n + 1)
    {
        cin >> v[i];

        if (v[i] > i)
        {
            f = 1;
        }
    }

    if (f == 1)
        cout << "NO\n";
    else
        cout << "YES\n";
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