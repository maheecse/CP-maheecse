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
        int c = 0;
        if (x % 4 == 0)
            cout << x / 4 << endl;
        else
        {
            c = x / 4;
            // int d=x-(4*c);
            cout << c + 1 << endl;
        }
    }
}