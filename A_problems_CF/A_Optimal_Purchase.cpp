#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, a, b, solve = 0;
        cin >> n >> a >> b;
        if (a * 3 <= b)
            solve = n * a;
        else
        {
            solve += (n / 3) * b;

            if ((n % 3) * a < b)
            {
                solve += (n % 3) * a;
            }
            else
            {
                solve += b;
            }
        }

        cout << solve << endl;
    }
}