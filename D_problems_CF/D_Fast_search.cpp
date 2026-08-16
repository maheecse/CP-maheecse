#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int k;
    cin >> k;
    while (k--)
    {
        int x, y;
        cin >> x >> y;

        // lourbound marsi
        int l = -1, r = n;
        while (l + 1 < r)
        {
            int m = (l + r) / 2;
            if (v[m] < x)
                l = m;
            else
                r = m;
        }
        int L = r;

        // upperbound marsi
        int l1 = -1, r1 = n;
        while (l1 + 1 < r1)
        {
            int m1 = (l1 + r1) / 2;
            if (v[m1] <= y)
                l1 = m1;
            else
                r1 = m1;
        }
        int R = r1;

        cout << R - L << " ";
    }
}