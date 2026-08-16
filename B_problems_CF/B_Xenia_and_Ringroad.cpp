
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    vector<long long> v(m);
    for (auto &x : v)
    {
        cin >> x;
    }
    long long cnt = v[0] - 1;
    for (long long i = 0; i < m - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            cnt += (n - v[i]) + v[i + 1];
        }
        else if (v[i] == v[i + 1])
            cnt += 0;
        else
            cnt += v[i + 1] - v[i];
    }
    cout << cnt;
}