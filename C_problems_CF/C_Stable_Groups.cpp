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
    ll n, k, x;
    cin >> n >> k >> x;
    vll v(n);
    FOR(i, 0, n)
    {
        cin >> v[i];
    }
    vll a;
    sort(all(v));
    FOR(i, 0, n - 1)
    {
        if (v[i + 1] - v[i] > x)
        {
            ll p = v[i + 1] - v[i];
            ll c = (p - 1) / x;
            a.pb(c);
        }
    }
    sort(all(a));

    ll ans = sz(a) + 1;

    FOR(i, 0, sz(a))
    {
        if (k >= a[i])
        {
            k -= a[i];
            ans--;
        }
        else
            break;
    }
    cout << ans << endl;
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