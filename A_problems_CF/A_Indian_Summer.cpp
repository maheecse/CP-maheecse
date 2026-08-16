#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    set<string> s;

    while (t--)
    {
        string x;
        getline(cin, x);
        s.insert(x);
    }

    cout << s.size() << endl;
}
// int j = 0, c = 1;

// for (int i = 1; i < s.size(); i++)
// {
//     if (s[j] != s[i])
//     {
//         c++;
//         j = i;
//     }
// }

// cout << c << endl;
