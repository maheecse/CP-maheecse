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
    int n, k;
    cin >> n >> k;

    if (k == n - 1)
    {
        cout << -1 << endl;
        return;
    }

    k = n - k;

    int c0 = (n + 1) / 2;
    int c1 = n / 2;

    FOR(i, 0, k)
    {
        if (i % 2 == 0)
        {
            if (i + 2 >= k)
            {
                while (c0 > 0)
                {
                    cout << 0;
                    c0--;
                }
            }
            else
            {
                cout << 0;
                c0--;
            }
        }
        else
        {
            if (i + 2 >= k)
            {
                while (c1 > 0)
                {
                    cout << 1;
                    c1--;
                }
            }
            else
            {
                cout << 1;
                c1--;
            }
        }
    }

    cout << endl;
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
