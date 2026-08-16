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

void solve()
{
    string r;
    cin >> r;
    int x = r[1] - '0';
    for (int i = 1; i <= 8; i++)
    {
        if (i != x)
            cout << r[0] << i << endl;
    }

    for (char c = 'a'; c <= 'h'; c++)
    {
        if (c != r[0])
            cout << c << x << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}

// cout<<"a2\n\a3\na4\na5\na6\na7\na8";
// cout<<"b1\n\c1\nd1\ne1\nf1\na7\na8";