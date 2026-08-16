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

    string s = "ROYGBIV";

    int x = n % 7;

    while (n >= 7)
    {
        cout << "ROYGBIV";
        n -= 7;
    }

    if (x == 1)
    {
        cout << "G";
    }
    else if (x == 2)
    {
        cout << "YG";
    }
    else if (x == 3)
    {
        cout << "OYG";
    }
    else if (x == 4)
    {
        cout << "ROYG";
    }
    else if (x == 5)
    {
        cout << "ROYGB";
    }
    else if (x == 6)
    {
        cout << "ROYGBI";
    }

    cout << endl;
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