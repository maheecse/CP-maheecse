// /// BISMILLAHIR RAHMANIR RAHEEM
// /// @cf - maheecse

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define ld long double
// #define vi vector<int>
// #define vll vector<long long>
// #define pii pair<int, int>
// #define pll pair<long long, long long>
// #define pb push_back
// #define fi first
// #define se second

// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define sz(x) ((int)(x).size())

// #define FOR(i, a, b) for (int i = (a); i < (b); i++)
// #define FORR(i, a, b) for (int i = (a); i >= (b); i--)

// using i128 = __int128_t;
// using u128 = __uint128_t;

// const int MOD = 1e9 + 7;
// const ll INF = 1e18;

// void cp_chere_dibo()
// {
// int N;
// cin >> N;
// n = 4 * N;
// vector<pair<int, char>> v(n);

// FOR(i, 0, n)
// {
//     cin >> v[i].first >> v[i].second;
// }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int tc = 1;
//     cin >> tc;

//     while (tc--)
//     {
//         cp_chere_dibo();
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define bs binary_search
#define sum accumulate
#define psum(v) partial_sum(all(v), (v).begin())
#define psum2(src, dest) partial_sum(all(src), (dest).begin())
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forc(v) for (auto &x : v)
#define forp(v) for (auto x : v)

void solve()
{
    int n, m;
    cin >> n >> m;
    vi l(n), f(m);
    forc(l) cin >> x;
    forc(f) cin >> x;

    int mxl = *max_element(all(l));
    int mxf = *max_element(all(f));
    if (mxl != mxf)
    {
        cout << "No" << endl;
    }
    else
        cout << "Yes" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}