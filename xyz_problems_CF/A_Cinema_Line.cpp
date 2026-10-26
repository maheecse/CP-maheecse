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
    int a, c25 = 0, c50 = 0;
    FOR(i, 0, n)
    {
        cin >> a;
        if (a == 25)
            c25++;
        else if (a == 50)
        {
            if (c25 == 0)
            {
                cout << "NO" << endl;
                return;
            }
            c25--;
            c50++;
        }
        else
        {
            if (c50 > 0 && c25 > 0)
                c50--, c25--;
            else if (c25 >= 3)
                c25 -= 3;
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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