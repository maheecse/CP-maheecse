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

bool check(vi<int> &v, int n, int c, int mid)
{
    int cow = 1;
    int last = v[0];

    FOR(i, 1, n)
    {
        if (v[i] - last >= mid)
        {
            cow++;
            last = v[i];
        }
    }

    return cow >= c;
}

void cp_chere_dibo()
{
    int n, c;
    cin >> n >> c;

    vi<int> v(n);

    FOR(i, 0, n)
    cin >> v[i];

    sort(all(v));

    int l = 1;
    int r = v[n - 1] - v[0];

    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (check(v, n, c, mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << r << endl;
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