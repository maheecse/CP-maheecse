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
    string s;
    cin >> n >> s;

    vi v;
    int Z = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            Z++;
            v.pb(i + 1);
        }
    }

    if (Z % 2)
    {
        cout << sz(v) << '\n';

        for (int x : v)
            cout << x << ' ';

        cout << endl;
    }
    else
    {
        v.clear();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                v.pb(i + 1);
        }

        if (sz(v) % 2)
        {
            cout << -1 << endl;
            return;
        }

        cout << sz(v) << endl;

        for (int x : v)
            cout << x << ' ';

        cout << endl;
    }
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