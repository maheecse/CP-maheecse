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

void solve()
{
    int n, c = 0;
    cin >> n;

    string s1;
    cin >> s1;

    vector<int> freq(26, 0);
    set<char> s, s2;

    for (char ch : s1)
    {
        s.insert(ch);
        freq[ch - 'a']++;
    }

    for (char ch : s1)
    {
        if (freq[ch - 'a'] == 1)
        {
            s2.insert(ch);
            s.erase(ch);
        }
        else
        {
            s2.insert(ch);
            freq[ch - 'a']--;
        }

        c = max(c, (int)s.size() + (int)s2.size());
    }

    cout << c << '\n';
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