#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    vector<pair<int, int>> rng(n + 1, {-1, -1});
    for (int i = 0; i < q; ++i)
    {
        int p, l, r;
        cin >> p >> l >> r;
        if (rng[p] == make_pair(-1, -1))
        {
            rng[p] = {l, r};
        }
        else
        {
            rng[p] = {max(l, rng[p].first), min(r, rng[p].second)};
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        if (rng[i] == make_pair(-1, -1))
            continue;
        if (rng[i].first > rng[i].second)
        {
            cout << -1 << endl;
            return;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        auto [l, r] = rng[i];
        if (l == -1)
            continue;
        if (a[i] >= l && a[i] <= r)
            continue;
        ans += min(abs(a[i] - l), abs(a[i] - r));
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cout.tie(0);

    int T = 1;
    cin >> T;
    while (T--)
        solve();

    return 0;
}