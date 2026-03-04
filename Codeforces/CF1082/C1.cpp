#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
int t;
int n;
int a[maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int ans = 1, l = a[1], r = a[1];
        for (int i = 2; i <= n; i++)
        {
            if (a[i] == a[i - 1] + 1 || (a[i] == a[i - 1] && a[i] > l))
            {
                r = a[i];
                continue;
            }
            else if (a[i] > l && a[i] <= r + 1)
            {
                r = a[i];
                continue;
            }
            // cout << i << " " << a[i] << " " << l << " " << r << endl;
            ans++;
            l = a[i];
            r = a[i];
        }
        cout << ans << endl;
    }

    return 0;
}
