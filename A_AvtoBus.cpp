// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int main()
// {
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         ll n, f = 0;
//         cin >> n;
//         if ((n % 6) % 4 == 0)
//         {
//             ll mn = n / 6 + (n % 6) / 4;
//             cout << mn << " ";
//         }
//         else
//             f++;

//         if ((n % 4) % 6 == 0)
//         {
//             ll mx = n / 4 + (n % 4) / 6;
//             cout << mx << endl;
//         }
//         else
//             f++;
//         if (f > 0)
//             cout << "-1" << endl;
//     }
// // }
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main()
// {
//     ll t;
//     cin >> t;

//     while (t--)
//     {
//         ll n, f = 0;
//         cin >> n;

//         if (n % 2 == 0 && n >= 4)
//         {
//             ll mn = (n + 5) / 6;
//             cout << mn << " ";

//             ll mx = n / 4;
//             cout << mx << endl;
//         }
//         else
//             cout << -1 << endl;
//     }
// // }
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

//         if (n % 2 != 0 || n < 4)
//         {
//             cout << -1 << endl;
//             continue;
//         }

//         ll mn, mx;

//         if (n % 6 == 0)
//             mn = n / 6;
//         else
//             mn = n / 6 + 1;

//         mx = n / 4;

//         cout << mn << " " << mx << endl;
//     }
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
        ll n;
        cin >> n;
        vector<ll> v(n), a;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll g = v[0];
        for (ll i = 0; i < n - 1; i++)
        {
            g = gcd(v[i + 1], g);
        }
        ll mx = *max_element(v.begin(), v.end());
        ll ans = mx / g;
        cout << ans << endl;
    }
}