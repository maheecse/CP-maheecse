
/// BISMILLAHIR RAHMANIR RAHEEM
/// @cf - maheecse

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vi vector
#define vll vector
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

    vector<int> v(n);

    FOR(i, 0, n)
    {
        cin >> v[i];
    }

    sort(all(v));

    vector<int> a;

    FOR(i, 0, n)
    {
        if (i == 0 || v[i] != v[i - 1])
        {
            a.pb(v[i]);
        }
    }

    int f = 1;

    if (a.size() <= 2)
    {
        cout << "YES" << endl;
        return;
    }

    if (a.size() > 3)
    {
        cout << "NO" << endl;
        return;
    }

    FOR(i, 0, a.size() - 2)
    {
        if (a[i + 1] - a[i] != a[i + 2] - a[i + 1])
        {
            f = 0;
            break;
        }
    }

    if (f == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
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
