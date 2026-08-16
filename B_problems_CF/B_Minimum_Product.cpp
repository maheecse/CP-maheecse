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

ll ck_it_br0(ll a, ll b, ll x, ll y, ll n)
{
    ll for_a = min(a - x, n);
    a -= for_a;
    n -= for_a;

    ll for_b = min(b - y, n);
    b -= for_b;

    return a * b;
}

void cp_chere_dibo()
{
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;

    ll p = ck_it_br0(a, b, x, y, n);
    ll q = ck_it_br0(b, a, y, x, n);

    cout << min(p, q) << endl;
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