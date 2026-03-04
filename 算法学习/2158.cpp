#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 40040;
int phi[maxn], p[maxn], cnt;
bool vis[maxn];
int n;

void pre()
{
    for (int i = 2; i < maxn - 10; i++)
    {
        if (!vis[i])
        {
            p[++cnt] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= cnt && 1LL * i * p[j] < maxn - 10; j++)
        {
            int t = i * p[j];
            vis[t] = 1;
            if (i % p[j] == 0)
            {
                phi[t] = phi[i] * p[j];
                break;
            }
            else
            {
                phi[t] = phi[i] * (p[j] - 1);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    phi[1] = 1;
    pre();
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        ans += phi[i];
    }
    cout << ans * 2 + 1 << endl;

    return 0;
}
