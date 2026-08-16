#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--)
    {
        int x;
        cin >> x;

        string s;
        cin >> s;

        int cnt = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                cnt++;
            else
                cnt--;
        }

        if (cnt == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}