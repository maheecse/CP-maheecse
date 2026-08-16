// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int main()
// {
//     ll n, x, c = 0;
//     cin >> n >> x;

//     vector<vector<int>> v(n, vector<int>(n));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             v[i][j] = (i + 1) * (j + 1);
//             if (v[i][j] == x)
//                 c++;
//         }
//     }
//     cout << c << endl;
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, x, c = 0, j;
    cin >> n >> x;
    for (ll i = 1; i <= n; i++)
    {
        if (x % i == 0)
        {
            j = x / i;
            if (j <= n)
                c++;
        }
    }
    cout << c << endl;
}