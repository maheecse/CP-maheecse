/* #include <bits/stdc++.h>
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
        int l, r;
        l = 0, r = n - 1;
        int f = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (v[m] == x)
            {
                f = 1;
                break;
            }
            else if (x < v[m])
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
} */
// 7 13 55 66 78 99 787 7788
// 0 1  2  3  4  5  6    7
// l          m          r

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

        if (binary_search(v.begin(), v.end(), x))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}