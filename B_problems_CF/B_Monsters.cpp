
// #include <bits/stdc++.h>
// using namespace std;

// #define f(i, a, b) for (int i = a; i < b; i++)

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n, k;
//         cin >> n >> k;

//         vector<pair<int, int>> a;

//         f(i, 0, n)
//         {
//             int x;
//             cin >> x;

//             int r = x % k;
//             if (r == 0)
//                 r = k;

//             a.push_back({-r, i + 1});
//         }

//         sort(a.begin(), a.end());

//         f(i, 0, n)
//         {
//             cout << a[i].second << " ";
//         }

//         cout << endl;
//     }
// }

// /// BISMILLAHIR RAHMANIR RAHEEM
// /// وَمَا تَوْفِيقِي إِلَّا بِاللَّهِ عَلَيْهِ تَوَكَّلتُ وَإِلَيْهِ أُنِيبُ

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define ld long double
// #define vi vector<int>
// #define vll vector<long long>
// #define pii pair<int, int>
// #define pll pair<long long, long long>
// #define pb push_back
// #define fi first
// #define se second
// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define sz(x) ((int)(x).size())

// const int MOD = 1e9 + 7;
// const ll INF = 1e18;

// void solve()
// {
//     ll n,s;
//     cin>>n;
//     if(n%1000==0) cout<<0<<endl;
//     else{
//         n+=100;
//         s+=100;
//         if(n%1000) {
//             cout<<s<<endl;
//             return 0;
//         }
//     }

// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int tc = 1;
//     //cin >> tc;

//     while (tc--)
//     {
//         solve();
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, s = 0;
    cin >> n;

    if (n % 1000 == 0)
        cout << 0 << endl;
    else
    {
        while (n % 1000 != 0)
        {
            n++;
            s++;
        }
        cout << s << endl;
    }
}