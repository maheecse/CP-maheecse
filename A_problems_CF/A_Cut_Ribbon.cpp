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

// void cp_chere_dibo()
// {
//     int n, a, b, c;
//     cin >> n >> a >> b >> c;
//     vi v(3);
//     v[0] = a;
//     v[1] = b;
//     v[2] = c;
//     sort(all(v));
//     int cnt = 0;
//     FOR(i, 0, 3)
//     {
//         int d = n - v[i];
//         if (d > 0)
//         {
//             cnt++;
//             n = n - v[i];
//         }
//         else
//             break;
//     }
// }
void cp_chere_dibo()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int ans = 0;

    for (int i = 0; i <= n / a; i++)
    {
        for (int j = 0; j <= n / b; j++)
        {
            int d = n - i * a - j * b;

            if (d >= 0 && d % c == 0)
            {
                int k = d / c;
                ans = max(ans, i + j + k);
            }
        }
    }

    cout << ans << endl;
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