#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        long long sum = ((n + k - 1) / k) * k;
        long long ans = (sum + n - 1) / n;

        cout << ans << '\n';
    }
}