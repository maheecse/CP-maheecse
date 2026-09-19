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
    ll n, k, b, s;
    cin >> n >> k >> b >> s;

    vll v(n, 0);

    v[0] = min(s, k * b + k - 1);
    s -= v[0];

    if (v[0] < k * b)
    {
        cout << -1 << endl;
        return;
    }

    for (int i = 1; i < n; i++)
    {
        v[i] = min(s, k - 1);
        s -= v[i];
    }

    if (s > 0)
    {
        cout << -1 << endl;
        return;
    }

    FOR(i, 0, n)
    cout << v[i] << " ";

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