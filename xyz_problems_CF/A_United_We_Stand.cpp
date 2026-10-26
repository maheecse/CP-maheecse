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

    int a[n];
    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    vi A, B;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == mx)
            A.pb(a[i]);
        else
            B.pb(a[i]);
    }

    if (B.size() == 0)
    {
        cout << -1 << '\n';
        return;
    }

    cout << A.size() << " " << B.size() << '\n';

    for (int x : A)
        cout << x << " ";

    cout << '\n';

    for (int x : B)
        cout << x << " ";

    cout << '\n';
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