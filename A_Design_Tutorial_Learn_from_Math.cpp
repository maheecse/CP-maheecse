// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// bool p(int x)
// {
//     if (x < 2)
//         return false;

//     if (x == 2)
//         return true;

//     if (x % 2 == 0)
//         return false;

//     for (int i = 3; i * i <= x; i += 2)
//     {
//         if (x % i == 0)
//             return false;
//     }

//     return true;
// }
// int main()
// {
//     ll n, x, y;
//     cin >> n;
//     if (n % 2 == 0)
//     {
//         x = n / 2;
//         y = n / 2;
//         while (1)
//         {
//             if (!p(x) && !p(y))
//             {
//                 cout << x << " " << y << endl;
//                 break;
//             }
//             else
//             {
//                 x++;
//                 y--;
//             }
//         }
//     }
//     else
//     {
//         x = (n / 2) + 1;
//         y = n / 2;
//         while (1)
//         {
//             if (!p(x) && !p(y))
//             {
//                 cout << x << " " << y << endl;
//                 break;
//             }
//             else
//             {
//                 x++;
//                 y--;
//             }
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;
#define ll int

bool prime[90000001];
int n = 90000000;
vector<int> v;
void sieve()
{
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == false)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = true;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == false)
            v.push_back(i);
    }
}
int main()
{
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << v[n - 1] << endl;
    }
    return 0;
}