#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll m, n;

vector<ll> t, z, y;

bool ok(ll mid)
{
    ll total = 0;

    for (int i = 0; i < n; i++)
    {
        ll cycle = t[i] * z[i] + y[i];
        ll full = mid / cycle;
        ll balloons = full * z[i];
        ll rem = mid % cycle;
        balloons += min(z[i], rem / t[i]);
        total += balloons;

        if (total >= m)
            return true;
    }

    return total >= m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    t.resize(n);
    z.resize(n);
    y.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> z[i] >> y[i];
    }

    ll l = 0, r = 1e15;

    while (l < r)
    {
        ll mid = (l + r) / 2;

        if (ok(mid))
            r = mid;
        else
            l = mid + 1;
    }

    ll T = l;

    cout << T << "\n";

    ll need = m;
    vector<ll> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        ll cycle = t[i] * z[i] + y[i];

        ll full = T / cycle;

        ll balloons = full * z[i];

        ll rem = T % cycle;

        balloons += min(z[i], rem / t[i]);

        ans[i] = min(need, balloons);

        need -= ans[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
// 3 din dhore gutai o pari naiiii