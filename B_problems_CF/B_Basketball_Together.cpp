/// BISMILLAHIR RAHMANIR RAHEEM
/// وَمَا تَوْفِيقِي إِلَّا بِاللَّهِ عَلَيْهِ تَوَكَّلتُ وَإِلَيْهِ أُنِيبُ

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

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve()
{
    ll n, d;
    cin >> n >> d;
    vll v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(rall(v));
    ll x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        ll k = d / v[i] + 1;
        x += k;

        if (x <= n)
        {
            y++;
        }
        else
        {
            break;
        }
    }
    cout << y << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    // cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}
