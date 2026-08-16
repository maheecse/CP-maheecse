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
    vi v(n);
    FOR(i, 0, n)
    {
        cin >> v[i];
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    int m = v[n - 1];
    int ans = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i] > m)
            ans++;
        m = min(m, v[i]);
    }
    cout << ans << endl;
    // int ans = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (v[j] < v[i])
    //         {
    //             ans++;
    //             break;
    //         }
    //     }
    // }

    // cout << ans << endl;
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