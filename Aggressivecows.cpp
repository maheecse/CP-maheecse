// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// bool ispos(vector<ll> &v, ll n, ll c, ll mid)
// {

//     ll cow = 1, lsp = v[0];
//     for (ll i = 0; i < n; i++)
//     {
//         if (v[i] - lsp >= mid)
//         {
//             cow++;
//             lsp = v[i];
//         }
//         if (cow == c)
//             return true;
//     }
//     return false;
// }
// int main()
// {
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         ll n, c;
//         cin >> n >> c;
//         vector<ll> v(n);
//         for (ll i = 0; i < n; i++)
//             cin >> v[i];
//         sort(v.begin(), v.end());

//         ll mid, ans = -1, l = 1, r = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
//         while (l <= r)
//         {
//             mid = (l + r) / 2;
//             if (ispos(v, n, c, mid))
//             {
//                 ans = mid;
//                 l = mid + 1;
//             }
//             else
//             {
//                 r = mid - 1;
//             }
//         }
//         cout << ans << endl;
//     }
// }

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
bool ispos(vector<ll> &v, ll n, ll c, ll mid)
{

    ll cow = 1, lsp = v[0];
    for (ll i = 1; i < n; i++)
    {
        if (v[i] - lsp >= mid)
        {
            cow++;
            lsp = v[i];
        }
        if (cow == c)
            return true;
    }
    return false;
}
void solve()
{
    ll n, c;
    cin >> n >> c;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());

    ll mid, ans = -1, l = 1, r = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (ispos(v, n, c, mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}