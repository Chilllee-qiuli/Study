#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 220;
int n, m, K;
ll dp[maxn][maxn];

struct Cun
{
    int w, v;
} cun[maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> K;
    for (int i = 1; i <= n; i++)
        cin >> cun[i].w >> cun[i].v;

    for (int i = 1; i <= n; i++)
        for (int j = i - 1; j >= max(0, i - K); j--)
            for (int k = m; k >= cun[i].v; k--)
                dp[i][k] = max({dp[i][k], dp[j][k - cun[i].v] + cun[i].w});

    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i][m]);
    cout << ans << endl;

    // cout << dp[n][m] << endl;

    return 0;
}
