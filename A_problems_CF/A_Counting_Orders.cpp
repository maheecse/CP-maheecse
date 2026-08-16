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
    vi a(n), b(n);
    FOR(i, 0, n)
    cin >> a[i];
    FOR(i, 0, n)
    cin >> b[i];
    sort(all(a));
    sort(all(b));
    long long ans = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        auto it = upper_bound(a.begin(), a.end(), b[i]);
        // b theke boro a;
        int g = a.end() - it;
        // koita b theke boro
        int prev = n - 1 - i;
        // age koita use hoi gesse
        int op = g - prev;
        // baki oprion

        if (op <= 0)
        {
            ans = 0;
            break;
        }

        ans = (ans * op) % MOD;
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