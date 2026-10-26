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
    int n, k;
    cin >> n >> k;

    vi v(n);

    FOR(i, 0, n)
    {
        cin >> v[i];
    }

    if (k % 2 == 0)
    {
        int k1 = k / 2;

        FOR(i, 0, k1)
        {
            v[i] = 0;
        }

        FORR(i, n - 1, n - k1)
        {
            v[i] = 0;
        }
    }
    else
    {
        int k1 = (k + 1) / 2;

        FOR(i, 0, k1)
        {
            v[i] = 0;
        }

        FORR(i, n - 1, n - k1 + 1)
        {
            v[i] = 0;
        }
        reverse(v.begin(), v.end() + 1);
    }

    FOR(i, 0, n)
    {
        if (v[i] != 0)
        {
            cout << v[i] << " ";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    // cin >> tc;

    while (tc--)
    {
        cp_chere_dibo();
    }

    return 0;
}