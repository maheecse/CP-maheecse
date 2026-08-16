#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    while (k--)
    {
        int x;
        cin >> x;
        int l, r, m;
        l = -1, r = n;
        while (l + 1 < r)
        {
            m = (l + r) / 2;
            if (x <= v[m])
            {
                r = m;
            }
            else
                l = m;
        }
        cout << r + 1 << endl;
    }
}