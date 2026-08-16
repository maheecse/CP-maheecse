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

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORR(i, a, b) for (int i = (a); i >= (b); i--)

using i128 = __int128_t;
using u128 = __uint128_t;

const int MOD = 1e9 + 7;
const ll INF = 1e18;
void cp_chere_dibo()
{
    ll n;
    cin >> n;

    // 1 3 6 10 15

    ll ans = INF;

    ll k = n / 15;

    if (k > 10)
        k = 10;

    for (ll i = 0; i <= k; i++)
    {

        ll f = n / 15 - i;

        ll p = n - f * 15; // 15 coin newar por baki (-__-)

        ll cnt = f;

        if (p == 12)
        {
            cnt += 2; // 12 = 6 + 6
        }
        else
        {

            cnt += p / 10; // maxi 10 coin ni
            p %= 10;

            cnt += p / 6;
            p %= 6;

            cnt += p / 3;
            p %= 3;

            cnt += p;
        }

        ans = min(ans, cnt);
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