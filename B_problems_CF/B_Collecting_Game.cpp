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

    vll v(n), ans(n), p(n);

    map<ll, vector<int>> mp;

    FOR(i, 0, n)
    {
        cin >> v[i];
        mp[v[i]].pb(i);
    }

    sort(all(v));

    p[0] = v[0];

    FOR(i, 1, n)
    {
        p[i] = p[i - 1] + v[i];
    }

    ans[n - 1] = n - 1;

    FORR(i, n - 2, 0)
    {
        int j = upper_bound(v.begin() + i + 1, v.end(), p[i]) - v.begin() - 1;

        if (j > i)
            ans[i] = ans[j];
        else
            ans[i] = i;
    }

    vll Fans(n);
    map<ll, int> cnt;

    FOR(i, 0, n)
    {
        int in = mp[v[i]][cnt[v[i]]];

        Fans[in] = ans[i];

        cnt[v[i]]++;
    }

    FOR(i, 0, n)
    {
        cout << Fans[i] << " ";
    }

    cout << endl;
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