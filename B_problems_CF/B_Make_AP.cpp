/// BISMILLAHIR RAHMANIR RAHEEM
/// وَمَا تَوْفِيقِي إِلَّا بِاللَّهِ عَلَيْهِ تَوَكَّلتُ وَإِلَيْهِ أُنِيبُ

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>

const int N = 1000000;

vector<int> prime(N + 1, 1);
vector<int> cnt(N + 1, 0);
vector<int> pref(N + 1, 0);

void precompute()
{
    prime[0] = prime[1] = 0;

    for (ll i = 2; i * i <= N; i++)
    {
        if (prime[i])
        {
            for (ll j = i * i; j <= N; j += i)
            {
                prime[j] = 0;
            }
        }
    }

    for (ll i = 1; i <= N; i++)
    {
        cnt[i] = cnt[i - 1] + prime[i];
    }

    for (ll i = 1; i <= N; i++)
    {
        if (prime[cnt[i]])
            pref[i] = pref[i - 1] + 1;
        else
            pref[i] = pref[i - 1];
    }
}

void solve()
{
    ll l, r;
    cin >> l >> r;

    cout << pref[r] - pref[l - 1] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int tc;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}