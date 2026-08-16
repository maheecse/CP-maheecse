// #include <bits/stdc++.h>
// using namespace std;

// double n;

// bool ok(double mid)
// {
//     return (mid * mid + sqrt(mid) >= n);
// }

// int main()
// {
//     cin >> n;

//     double l = 0, r = 100000;
//     double eps = 1e-10;

//     while (r - l > eps)
//     {
//         double mid = (l + r) / 2;

//         if (ok(mid))
//             r = mid - 1;
//         else
//             l = mid + 1;
//     }

//     cout << setprecision(15) << r << endl;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int n;

// bool ok(double mid)
// {
//     return (mid * mid + sqrt(mid) >= n);
// }

// int main()
// {
//     cin >> n;

//     double l = 0, r = 100000;
//     double eps = 1e-7;

//     while (r - l > eps)
//     {
//         double mid = (l + r) / 2;

//         if (ok(mid))
//             r = mid;
//         else
//             l = mid;
//     }

//     cout << setprecision(6) << r << endl;
// }