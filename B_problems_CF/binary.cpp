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
    vi v = {2, 3, 4, 5, 7, 8, 9, 11, 11, 11, 11, 19};
    int n = v.size();
    int l = -1, r = n;
    int x;
    cin >> x;
    // while (l + 1 < r)
    // {
    //     int mid = (l + r) / 2;
    //     if (v[mid] >= x)
    //     {
    //         r = mid;
    //     }
    //     else
    //         l = mid;
    // }
    // cout << r << endl;

    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        if (v[mid] > x)
        {
            r = mid;
        }
        else
            l = mid;
    }
    // cout << r << endl; uper chaek
    cout << l << endl; // last occurance
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