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
//     vi a(n), b(n);
//     // vll c(2n);
//     FOR(i, 0, n)
//     {
//         cin >> a[i];
//         // c.push_back(a[i]);
//     }
//     FOR(i, 0, n)
//     {
//         cin >> b[i];
//         // c.push_back(b[i]);
//     }
//     //  sort(all(c));

//     vector<int> freq(2 * n + 1, 0);
//     for (int i = 0; i < n; i++)
//     {
//         freq[a[i]]++;
//         freq[b[i]]++;
//     }
//     cout << *max_element(all(freq)) << endl;
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

    vi a(n), b(n);

    FOR(i, 0, n)
    {
        cin >> a[i];
    }

    FOR(i, 0, n)
    {
        cin >> b[i];
    }

    vi fa(2 * n + 1, 0);
    vi fb(2 * n + 1, 0);

    int cnt = 1;
    fa[a[0]] = 1;
    FOR(i, 1, n)
    {
        if (a[i] == a[i - 1])
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }

        fa[a[i]] = max(fa[a[i]], cnt);
    }

    cnt = 1;
    fb[b[0]] = 1;
    FOR(i, 1, n)
    {
        if (b[i] == b[i - 1])
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }

        fb[b[i]] = max(fb[b[i]], cnt);
    }

    int ans = 0;

    FOR(i, 1, 2 * n + 1)
    {
        ans = max(ans, fa[i] + fb[i]);
    }

    cout << ans << endl;
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