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
//     ll n;
//     cin >> n;

//     while (1)
//     {
//         string s = to_string(n);

//         ll ans = 1;

//         for (auto c : s)
//         {
//             int digit = c - '0';

//             if (digit != 0)
//             {
//                 ans = lcm(ans, digit);
//             }
//         }

//         if (n % ans == 0)
//         {
//             cout << n << endl;
//             break;
//         }

//         n++;
//     }
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
int main()
{
    int n;
    cin >> n;
    int v[n + 1];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int l = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != v[i + 1])
        {
            l++;
        }
    }
    cout << "new length :" << " ";
    cout << l << endl;
}