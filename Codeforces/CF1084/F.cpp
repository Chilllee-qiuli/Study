#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int t;
int n, m;
ll now;
ll dp[maxn];

struct node
{
    int x, y;
    friend bool operator<(node fi, node se)
    {
        return fi.x == se.x ? fi.y > se.y : fi.x < se.x;
    }
};
node a[maxn];
priority_queue<node> qu;

void solve_one()
{
    cin >> n >> m;
    while (!qu.empty())
        qu.pop();
    dp[0] = 0;
    now = 0;
    int nul = 0;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
        dp[i] = 0;
    }
    sort(a + 1, a + 1 + n, [](node x, node y)
         { return x.y == y.y ? x.x > y.x : x.y > y.y; });

    for (int i = 1; i <= n; i++)
    {
        // while(!qu.empty() && qu.top().x < a[i].x) qu.pop();
        // dp[i] = qu.size() + 1;
        // qu.push(a[i]);
        if (qu.size() < a[i].y)
        {
            qu.push(a[i]);
            now += a[i].x;
        }
        else
        {
            // while(!qu.empty() && qu.top().x < a[i].x) { now -= qu.top().x; qu.pop();}
            while (!qu.empty() && qu.size() >= a[i].y)
            {
                now -= qu.top().x;
                qu.pop();
            }
            qu.push(a[i]);
        }
        nul = max(nul, a[i].x);
        dp[qu.size()] = max(dp[qu.size()], now);
    }
    for(int i = n; i >= 0; i--) dp[i] = max(dp[i + 1], dp[i]);
    ll base_max = dp[1]; 

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y == 0)
            cout << max(base_max, 1ll * x) << " ";
        else
            cout << max(base_max, dp[y] + x) << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
        solve_one();

    return 0;
}
