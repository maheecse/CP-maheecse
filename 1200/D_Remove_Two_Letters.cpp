/// BISMILLAHIR RAHMANIR RAHEEM

/// @cf - maheecse

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void cp_chere_dibo()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = n - 1;

    for (int i = 0; i < n - 2; i++)
    {
        if (s[i] == s[i + 2])
            ans--;
    }

    cout << ans << '\n';
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