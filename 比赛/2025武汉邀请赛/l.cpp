#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    int ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if ((a[i] & 1) != (a[j] & 1))
                continue;
            if (a[i] == a[j])
            {
                ans = max(ans, j - i + 1);
                continue;
            }
            int mid = (a[i] + a[j]) / 2;
            int t = lower_bound(a.begin() + i, a.begin() + j + 1, mid) - a.begin();
            if (a[t] != mid)
                continue;
            while (t + 1 <= (i + j) / 2 && a[t + 1] == a[t])
                ++t;
            if (t != i && t != j)
            {
                int c = t - i - 1;
                int b = j - t - 1;
                int r = b > c ? 2 * c + 1 : 2 * b;
                ans = max(ans, 3 + r);
            }
            else
            {
                ans = max(ans, 2);
            }
        }
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