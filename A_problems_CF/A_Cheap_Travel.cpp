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
    // int n, m, a, b;
    // cin >> n >> m >> a >> b;
    // int sum = 0;
    // int t = 0;
    // int x = (n / m) * min(m * a, b);
    // int y = (n % m) * a;

    // cout << x + y << endl;
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int sum;

    if (m * a <= b)
    {
        sum = n * a;
    }
    else
    {
        sum = (n / m) * b;
        sum += min((n % m) * a, b);
    }

    cout << sum << endl;
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