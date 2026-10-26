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
    cin >> v[i];

    sort(all(v));

    vector<ll> pref(n + 1, 0);

    FOR(i, 0, n)
    pref[i + 1] = pref[i] + v[i];

    ll ans = 0;

    FOR(i, 0, k + 1)
    {
        int l = 2 * i;
        int r = n - (k - i);

        ll sum = pref[r] - pref[l];

        ans = max(ans, sum);
    }

    cout << ans << '\n';
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