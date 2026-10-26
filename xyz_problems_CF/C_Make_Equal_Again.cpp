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

    vi a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int l = 0, r = n - 1;

    while (l < n - 1 && a[l] == a[l + 1])
    {
        l++;
    }

    while (r > 0 && a[r] == a[r - 1])
    {
        r--;
    }

    if (a[0] == a[n - 1])
    {
        cout << max(0, r - l) << '\n';
    }
    else
    {
        cout << min(n - l - 1, r) << '\n';
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
