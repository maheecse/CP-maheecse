#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int a = 0, b = 0, ans = 0;
        for (char ch : s)
        {
            if (ch == '(')
            {
                b++;
            }
            else
            {
                b--;
                if (b < 0)
                {
                    b = 0;
                    a++;
                }
            }
        }

        cout << a << endl;
    }
}