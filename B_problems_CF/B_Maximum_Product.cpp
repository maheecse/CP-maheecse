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

    vll v(n), a(6);

        FOR(i, 0, n)
    {
        cin >> v[i];
    }
    sort(all(v));

    a[0] = 1LL * v[n - 5] * v[n - 4] * v[n - 3] * v[n - 2] * v[n - 1];

    a[1] = 1LL * v[0] * v[n - 4] * v[n - 3] * v[n - 2] * v[n - 1];

    a[2] = 1LL * v[0] * v[1] * v[n - 3] * v[n - 2] * v[n - 1];

    a[3] = 1LL * v[0] * v[1] * v[2] * v[n - 2] * v[n - 1];

    a[4] = 1LL * v[0] * v[1] * v[2] * v[3] * v[n - 1];

    a[5] = 1LL * v[0] * v[1] * v[2] * v[3] * v[4];

    cout << *max_element(all(a)) << endl;
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