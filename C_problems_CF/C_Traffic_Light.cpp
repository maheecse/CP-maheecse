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
    char c;
    cin >> n >> c;

    string s;
    cin >> s;

    if (c == 'g')
    {
        cout << 0 << endl;
        return;
    }
    string t = s + s;

    int lg = -1;
    int ans = 0;

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        if (t[i] == 'g')
            lg = i;
        if (i < n)
            if (t[i] == c)
                ans = max(ans, lg - i);
    }

    cout << ans << endl;
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