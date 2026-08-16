#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i1 = 0, j1 = 0;
    while (n--)
    {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'A')
                a++;
            else if (s[i] == 'B')
                b++;
            else if (s[i] == 'C')
                c++;
            else if (s[i] == 'D')
                d++;
            else if (s[i] == 'E')
                e++;
            else if (s[i] == 'F')
                f++;
            else if (s[i] == 'G')
                g++;
            else if (s[i] == 'H')
                h++;
            else if (s[i] == 'I')
                i1++;
            else if (s[i] == 'J')
                j1++;
        }
    }
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    v.push_back(e);
    v.push_back(f);
    v.push_back(g);
    v.push_back(h);
    v.push_back(i1);
    v.push_back(j1);
    auto it = max_element(v.begin(), v.end());
    int q = *it;

    if (a == q)
        cout << "A";
    if (b == q)
        cout << "B";
    if (c == q)
        cout << "C";
    if (d == q)
        cout << "D";
    if (e == q)
        cout << "E";
    if (f == q)
        cout << "F";
    if (g == q)
        cout << "G";
    if (h == q)
        cout << "H";
    if (i1 == q)
        cout << "I";
    if (j1 == q)
        cout << "J";
}