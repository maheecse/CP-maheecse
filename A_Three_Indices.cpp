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

#define yes cout << \"YES\n\"
#define no cout << \"NO\n\"

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
    vi v(n), s;
    FOR(i, 0, n)
    cin >> v[i];

    FOR(j, 1, n - 1)
    {
        int l = -1, r = -1;

        FOR(i, 0, j)
        {
            if (v[j] > v[i])
            {
                l = i;
                break;
            }
        }
        FOR(k, j + 1, n)
        {
            if (v[j] > v[k])
            {
                r = k;
                break;
            }
        }
        if (l != -1 && r != -1)
        {
            cout << "YES" << endl;
            cout << l + 1 << " " << j + 1 << " " << r + 1 << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--)
    {
        cp_chere_dibo();
    }

    return 0;
}