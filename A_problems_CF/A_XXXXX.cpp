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
    int n, x;
    cin >> n >> x;
    vi v(n);
    ll sum = 0;
    FOR(i, 0, n)
    {
        cin >> v[i];
        sum += v[i];
    }
    if (sum % x != 0)
    {
        cout << n << endl;
        return;
    }
    int f = -1, l = -1;

    FOR(i, 0, n)
    {
        if (v[i] % x != 0)
        {
            f = i;
            break;
        }
    }
    FORR(i, n - 1, 0)
    {
        if (v[i] % x != 0)
        {
            l = i;
            break;
        }
    }
    if (f == -1)
    {
        cout << -1 << endl;
        return;
    }
    cout << max(n - f - 1, l) << endl;
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