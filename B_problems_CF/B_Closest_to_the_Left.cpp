
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
        int x;
        cin >> x;
        int l, r, m;
        l = -1, r = n;
        while (l + 1 < r)
        {
            m = (l + r) / 2;
            if (x < v[m])
            {
                r = m;
            }
            else
                l = m;
        }

        int y;
        cin >> y;
        int l1, r1, m1;
        l1 = -1, r1 = n;
        while (l1 + 1 < r1)
        {
            m = (l1 + r1) / 2;
            if (y <= v[m])
            {
                r1 = m1;
            }
            else
                l1 = m1;
        }

        cout << r1 - r << " ";
    }
}
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> v;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }

        // print: 6 divisible first
        for (int x : v)
        {
            if (x % 6 == 0)
                cout << x << " ";
        }

        // then only even (not 6)
        for (int x : v)
        {
            if (x % 2 == 0 && x % 6 != 0)
                cout << x << " ";
        }

        // then neither 2 nor 3
        for (int x : v)
        {
            if (x % 2 != 0 && x % 3 != 0)
                cout << x << " ";
        }

        // then only divisible by 3 (not 6)
        for (int x : v)
        {
            if (x % 3 == 0 && x % 6 != 0)
                cout << x << " ";
        }

        cout << "\n";
    }

    return 0;
}