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
//     int n;
//     cin >> n;

//     vi v(n);

//     FOR(i, 0, n)
//     cin >> v[i];

//     sort(all(v));
//     /// 4 4 4 4
//     if (v[0] == v[n - 1])
//     {
//         cout << "Yes" << endl;
//         return;
//     }

//     int cnt1 = 1, cnt2 = 0;

//     FOR(i, 1, n)
//     {
//         if (v[i] == v[0])
//             cnt1++;
//         else
//         {
//             cnt2 = n - cnt1;
//             break;
//         }
//     }

//     if (cnt2 == 0)
//     {
//         cout << "Yes" << endl;
//         return;
//     }

//     FOR(i, cnt1, n)
//     {
//         if (v[i] != v[cnt1])
//         {
//             cout << "No" << endl;
//             return;
//         }
//     }

//     if (abs(cnt1 - cnt2) <= 1)
//         cout << "Yes" << endl;
//     else
//         cout << "No" << endl;
// }
void cp_chere_dibo()
{
    int n;
    cin >> n;

    map<int, int> mp;

    FOR(i, 0, n)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    if (mp.size() == 1)
    {
        cout << "Yes" << endl;
        return;
    }

    if (mp.size() > 2)
    {
        cout << "No" << endl;
        return;
    }

    auto it = mp.begin();

    int cnt1 = it->second;
    it++;
    int cnt2 = it->second;

    if (abs(cnt1 - cnt2) <= 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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