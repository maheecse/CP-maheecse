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
    string s;
    cin >> s;
    int c = 0;
    vi v;
    FOR(i, 0, n)
    {
        if (s[i] == '#')
        {
            c++;
        }
        else if (s[i] == '*')
        {
            v.push_back(c);
            c = 0;
        }
    }
    if (c > 0)
        v.push_back(c);

    if (v.empty())
    {
        cout << 0 << endl;
        return;
    }

    int ans = *max_element(all(v));
    cout << (ans + 1) / 2 << endl;
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