// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int main()
// {
//     ll int t;
//     cin >> t;

//     while (t--)
//     {
//         ll int a, b;
//         cin >> a >> b;
//         if (a == b)
//             cout << 0 << " " << 0 << endl;
//         else
//         {
//             ll int g = abs(a - b);
//             ll int next = min(a % g, g - (a % g));
//             cout << g << " " << next << endl;
//         }
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// bool prime(ll z)
// {
//     if (z < 2)
//         return false;
//     else if (z <= 3)
//         return true;
//     else if (z % 2 == 0)
//         return false;
//     else
//     {
//         for (ll i = 3; i * i <= z; i += 2)
//         {
//             if (z % i == 0)
//                 return false;
//         }
//         return true;
//     }
// }

// int main()
// {
//     ll t;
//     cin >> t;

//     while (t--)
//     {
//         ll x, y;
//         vector<ll> v;

//         cin >> x >> y;

//         ll n = x - y;

//         for (ll i = 1; i <= n; i++)
//         {
//             if (prime(i))
//             {
//                 v.push_back(i);
//             }
//         }

//         bool f = false;

//         for (ll i = 0; i < v.size(); i++)
//         {
//             if (n % v[i] == 0)
//             {
//                 f = true;
//                 break;
//             }
//         }

//         if (f)
//             cout << "YES" << endl;
//         else
//             cout << "NO" << endl;
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
//         ll x, y;
//         cin >> x >> y;

//         ll n = x - y;

//         if (n > 1)
//             cout << "YES" << endl;
//         else
//             cout << "NO" << endl;
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// vector<ll> fibonacci(int n)
// {
//     vector<ll> fib;

//     if (n <= 0)
//         return fib;

//     fib.push_back(0);

//     if (n == 1)
//         return fib;

//     fib.push_back(1);

//     for (int i = 2; i < n; i++)
//     {
//         fib.push_back(fib[i - 1] + fib[i - 2]);
//     }

//     return fib;
// }
// int main()
// {
//     ll n, f = 0;
//     cin >> n;
//     vector<ll> v = fibonacci(n);
//     for (ll i = 0; i < v.size(); i++)
//     {
//         for (ll j = 0; j < v.size(); j++)
//         {
//             for (ll k = 0; k < v.size(); k++)
//             {
//                 if (v[i] + v[j] + v[k] == n)
//                 {
//                     cout << v[i] << " "
//                          << v[j] << " "
//                          << v[k] << endl;

//                     f = 1;
//                     break;
//                 }
//             }

//             if (f)
//                 break;
//         }

//         if (f)
//             break;
//     }

//     if (!f)
//     {
//         cout << "I'm too stupid to solve this problem" << endl;
//     }
// }

// #include <bits/stdc++.h>

// using namespace std;
// set<int> s;
// void div(int n)
// {
//     for (int i = 1; i <= sqrt(n); i++)
//     {
//         if (n % i == 0)
//         {
//             int x = i;
//             s.insert(x);
//             int y = n / i;
//             s.insert(y);
//         }
//     }
// }
// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     if (k > s.size())
//         cout << -1 << endl;
//     else
//         cout << s[k - 1] << endl;
// }