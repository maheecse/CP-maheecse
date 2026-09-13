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

int check(string s, string x)
{
    int j = 1;
    int cnt = 0;

    for (int i = sz(s) - 1; i >= 0; i--)
    {
        if (s[i] == x[j])
        {
            j--;

            if (j < 0)
                return cnt;
        }
        else
        {
            cnt++;
        }
    }

    return 100;
}
void cp_chere_dibo()
{
    string s;
    cin >> s;

    int ans = 100;

    ans = min(ans, check(s, "00"));
    ans = min(ans, check(s, "25"));
    ans = min(ans, check(s, "50"));
    ans = min(ans, check(s, "75"));

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