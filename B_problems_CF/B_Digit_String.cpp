#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int c = 0;
        for (char x : s)
        {
            if (x == '1' || x == '3')
                c++;
        }
        int c2 = 0, u = 0, good = c;
        for (char x : s)
        {
            if (x == '2')
                c2++;
            else if (x == '1' || x == '3')
                u++;

            good = max(good, c2 + (c - u));
        }
        int n = s.size();
        cout << n - good << endl;
    }
}