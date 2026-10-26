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

//     vll v(n);

//     FOR(i, 0, n)
//     {
//         cin >> v[i];
//     }

//     ll mx = v[0];
//     ll ans = 0;

//     FOR(i, 1, n)
//     {
//         if (mx < v[i])
//         {
//             mx = v[i];
//         }

//         if (i % 2 == 1)
//         {
//             v[i] = mx;

//             if (v[i - 1] >= v[i])
//             {
//                 ans += v[i - 1] - v[i] + 1;
//                 v[i - 1] = v[i] - 1;
//             }
//         }
//         else
//         {
//             if (v[i - 1] <= v[i])
//             {
//                 ans += v[i] - v[i - 1] + 1;
//                 v[i] = v[i - 1] - 1;
//             }
//         }
//     }

//     cout << ans << '\n';
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     ll tc = 1;
//     cin >> tc;

//     while (tc--)
//     {
//         cp_chere_dibo();
//     }

//     return 0;
// }
// // help lagse 55 min

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream fout;
    fout.open("RAND.DAT");

    srand(time(0));

    for (int i = 0; i < 100; i++)
    {
        int x = rand() % 100;
        fout << x << " ";
    }

    fout.close();

    ifstream fin;
    fin.open("RAND.DAT");

    int y;
    for (int i = 0; i < 100; i++)
    {
        fin >> y;
        cout << y << " ";
    }

    fin.close();

    return 0;
}