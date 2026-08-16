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

void solve()
{
    int n, m;
    cin >> n >> m;
    bool ok = false;
    char a[n + 7][m + 7];
    FOR(i, 0, n)
    {
        FOR(j, 0, m)
        {
            cin >> a[i][j];

            if (a[i][j] == 'C' || a[i][j] == 'M' || a[i][j] == 'Y')
            {
                ok = true;
            }
        }
    }

    if (ok)
        cout << "#Color" << endl;

    else
        cout << "#Black&White" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    // cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}