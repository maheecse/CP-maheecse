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
        int n;
        cin >> n;

        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (v[i] % 6 == 0)
                cout << v[i] << " ";
        }

        for (int i = 0; i < n; i++)
        {
            if (v[i] % 2 == 0 && v[i] % 6 != 0)
                cout << v[i] << " ";
        }

        for (int i = 0; i < n; i++)
        {
            if (v[i] % 2 != 0 && v[i] % 3 != 0)
                cout << v[i] << " ";
        }

        for (int i = 0; i < n; i++)
        {
            if (v[i] % 3 == 0 && v[i] % 6 != 0)
                cout << v[i] << " ";
        }

        cout << "\n";
    }
}