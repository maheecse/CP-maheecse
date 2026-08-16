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
    vi v(n);
    int e = 0, o = 0;
    FOR(i, 0, n)
    {
        cin >> v[i];
        if (v[i] % 2 == 0)
            e++;
        else
            o++;
    }
    if (e % 2 == 0 && o % 2 == 0) // both even..;;;
        cout << "YES" << endl;
    else if (e % 2 != o % 2) // even odd
        cout << "NO" << endl;
    else
    {
        sort(all(v));
        FOR(i, 0, n - 1)
        {
            if (abs(v[i] - v[i + 1]) == 1)
            {
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
    }
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
//     int n;
//     cin >> n;
//     vi v(n);
//     int x = 10000;

//     FOR(i, 0, n)
//     {
//         cout << x++ << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int tc = 1;
//     // cin >> tc;

//     while (tc--)
//     {
//         cp_chere_dibo();
//     }

//     return 0;
// }