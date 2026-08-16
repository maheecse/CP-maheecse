#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll tc;
    cin >> tc;

    while (tc--)
    {
        ll n;
        cin >> n;

        if (n % 2 == 0)
        {
            cout << n - 3 << " " << 2 << " " << 1 << "\n";
        }
        else
        {
            ll c = (n - 1) / 2;

            if (c % 2 == 0)
            {
                cout << c - 1 << " " << c + 1 << " " << 1 << "\n";
            }
            else
            {
                cout << c - 2 << " " << c + 2 << " " << 1 << "\n";
            }
        }
    }
}
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int tc;
//     cin >> tc;

//     while (tc--)
//     {
//         int n;
//         cin >> n;

//         if (n % 2 == 0)
//         {
//             cout << n - 3 << " " << 2 << " " << 1 << "\n";
//         }
//         else
//         {
//             for (int a = 2; a <= n; a++)
//             {
//                 if (__gcd(a - 1, n - 1) == 1)
//                 {
//                     cout << a - 1 << " " << n - a << " " << 1 << "\n";
//                     break;
//                 }
//             }
//         }
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int main()
// {

//     ll tc;
//     cin >> tc;

//     while (tc--)
//     {

//         ll n;
//         cin >> n;

//         if (n % 2 == 0)
//         {
//             cout << n - 3 << " " << 2 << " " << 1 << "\n";
//         }
//         else
//         {

//             for (ll b = 2; b <= 10; b++)
//             {

//                 ll a = n - b - 1;
//                 ll c = 1;

//                 if (a > 0 && a != b && b != c && a != c)
//                 {

//                     if (gcd(a, b) == 1)
//                     {
//                         cout << a << " " << b << " " << c << "\n";
//                         break;
//                     }
//                 }
//             }
//         }
//     }
// }