// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main()
// {
//     ll n;
//     cin >> n;

//     for (ll i = 2; i * i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             ll c = 0;

//             while (n % i == 0)
//             {
//                 c++;
//                 n /= i;
//             }

//             cout << "(" << i << "^" << c << ")";

//             if (n > 1)
//                 cout << "*";
//         }
//     }

//     if (n > 1)
//     {
//         cout << "(" << n << "^1)";
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main()
// {
//     ll n;
//     cin >> n;
//     // 1378---8^n;
//     ll base = 8;
//     ll mod = 10;

//     ll res = 1;
//     while (n)
//     {
//         if (n % 2 == 1)
//         {
//             res = (res * base) % mod;
//             n--;
//         }
//         else
//         {
//             base = (base * base) % mod;
//             n /= 2;
//         }
//     }
//     cout << res << endl;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main()
// {
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         ll n;
//         cin >> n;
//         vector<ll> v;
//         if (n >= 1)
//             v.push_back(n + 2);
//         if (n >= 2)
//             v.push_back(1);
//         if (n >= 3)
//             v.push_back(n + 5);
//         for (ll i = 2; i < v.size(); i++)
//         {
//             v.push_back(i);
//         }
//         for (ll i = 0; i < v.size(); i++)
//         {
//             cout << v[i] << " ";
//         }
//         cout << endl;
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main()
// {
//     ll t;
//     cin >> t;

//     while (t--)
//     {
//         ll n;
//         cin >> n;

//         ll L = n + 2;
//         ll S = 1;

//         for (ll i = 0; i < n; i++)
//         {
//             if (i % 2 == 0)
//             {
//                 cout << L << " ";
//                 L++;
//             }
//             else
//             {
//                 cout << S << " ";
//                 S++;
//             }
//         }

//         cout << endl;
//     }
// }

// // #include <bits/stdc++.h>
// // using namespace std;

// // int main()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(NULL);

// //     int t;
// //     cin >> t;

// //     while (t--)
// //     {
// //         int n;
// //         cin >> n;

// //         int l = 1, r = 2 * n;

// //         for (int i = 0; i < n; i++)
// //         {
// //             if (i % 2 == 0)
// //                 cout << l++ << " ";
// //             else
// //                 cout << r-- << " ";
// //         }

// //         cout << "\n";
// //     }
// // }

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
//         vector<int> v;

//         for (int i = 1; i <= n; i++)
//         {
//             v.push_back(n + i);
//         }
//         for (int i = 0; i < v.size(); i++)
//         {
//             cout << v[i] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int tc;
//     cin >> tc;

//     while (tc--)
//     {
//         int n;
//         cin >> n;

//         for (int i = 1; i <= n; i++)
//         {
//             cout << n + i << " ";
//         }
//         cout << "\n";
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, sum = 0, ans = -1;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (n <= 2)
        {
            cout << "-1" << endl;
            continue;
        }
        ll l = 0, r = 1e18;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            ll nsum = sum + mid;
            double avg = (double)nsum / (2.0 * n);

            ll unhap = 0;
            for (ll i = 0; i < n; i++)
            {
                if (a[i] < avg)
                    unhap++;
            }
            if (unhap > n / 2)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}
