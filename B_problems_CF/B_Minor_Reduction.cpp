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
    string s;
    cin >> s;

    for (int i = s.size() - 2; i >= 0; i--)
    {
        int sum = (s[i] - '0') + (s[i + 1] - '0');

        if (sum >= 10)
        {

            for (int j = 0; j < i; j++)
                cout << s[j];

            cout << sum;

            for (int j = i + 2; j < s.size(); j++)
                cout << s[j];

            cout << endl;
            return;
        }
    }

    int sum = (s[0] - '0') + (s[1] - '0');

    cout << sum;

    for (int i = 2; i < s.size(); i++)
        cout << s[i];

    cout << endl;
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