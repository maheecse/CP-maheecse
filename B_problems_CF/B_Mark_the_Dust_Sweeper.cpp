// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n, c = 0, k = -1, l = -1;
//         long long sum = 0;

//         cin >> n;

//         vector<int> v(n);

//         for (int i = 0; i < n; i++)
//         {
//             cin >> v[i];
//             sum += v[i];
//         }

//         sum -= v[n - 1];

//         for (int i = 0; i < n - 1; i++)
//         {
//             if (v[i] > 0)
//             {
//                 k = i;
//                 break;
//             }
//         }

//         for (int i = n - 2; i >= 0; i--)
//         {
//             if (v[i] > 0)
//             {
//                 l = i;
//                 break;
//             }
//         }

//         if (k != -1)
//         {
//             for (int i = k; i <= l; i++)
//             {
//                 if (v[i] == 0)
//                     c++;
//             }
//         }

//         cout << sum + c << endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, c = 0, k = -1;
        long long sum = 0;

        cin >> n;

        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
        }

        sum -= v[n - 1];

        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] > 0)
            {
                k = i;
                break;
            }
        }

        if (k != -1)
        {
            for (int i = k; i < n - 1; i++)
            {
                if (v[i] == 0)
                    c++;
            }
        }

        cout << sum + c << endl;
    }
}