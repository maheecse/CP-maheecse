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

    vi v(n);

    FOR(i, 0, n)
    {
        cin >> v[i];
    }

    int l = 0;
    int r = n - 1;

    int mn = 1;
    int mx = n;

    while (l < r)
    {
        if (v[l] != mn && v[l] != mx &&
            v[r] != mn && v[r] != mx)
        {
            cout << l + 1 << " " << r + 1 << endl;
            return;
        }

        if (v[l] == mn)
        {
            mn++;
            l++;
        }
        else if (v[l] == mx)
        {
            mx--;
            l++;
        }
        else if (v[r] == mn)
        {
            mn++;
            r--;
        }
        else if (v[r] == mx)
        {
            mx--;
            r--;
        }
    }

    cout << -1 << endl;
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