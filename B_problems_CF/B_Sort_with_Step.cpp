#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        vector<int> b;

        for (int i = 0; i < n; i++)
        {
            if ((p[i] - 1) % k != i % k)
            {
                b.push_back(i);
            }
        }

        if (b.size() == 0)
        {
            cout << 0 << "\n";
        }
        else if (b.size() == 2)
        {
            int i = b[0];
            int j = b[1];

            swap(p[i], p[j]);

            int f = 1;
            for (int x = 0; x < n; x++)
            {
                if ((p[x] - 1) % k != x % k)
                {
                    f = 0;
                    break;
                }
            }
            if (f == 1)
                cout << "1" << endl;
            else
                cout << "-1" << endl;
            // cout << (ok ? 1 : -1) << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }

    return 0;
}