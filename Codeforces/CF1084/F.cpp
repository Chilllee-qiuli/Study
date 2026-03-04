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
    ll x;
    int y;
    friend bool operator<(node fi, node se)
    {
        return fi.x == se.x ? fi.y < se.y : fi.x > se.x;
    }
};
node a[maxn];
priority_queue<node> qu;

void setmax()

void solve_one()
{
    cin >> n >> m;
    while (!qu.empty())
        qu.pop();
    dp[0] = 0;
    now = 0;
    int cnt = 1;
    ll maxx = 0;
    multiset<int> mt;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
        dp[i] = 0;
    }
    sort(a + 1, a + 1 + n, [](node x, node y)
         { return x.y == y.y ? x.x > y.x : x.y > y.y; });


    for(int k = n; k >= 0; k--){
        while(cnt < n && a[cnt].y >= k){
            now += a[cnt].x;
            mt.insert(a[cnt].x);
            cnt++;
        }
        while(mt.size() > k + 1){
            now -= *mt.begin();
            mt.erase(*mt.begin());
        }
    }


    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y == 0)
            cout << max(dp[0], 1ll * x) << " ";
        else
            cout << max(dp[y - 1], dp[y] + x) << " ";
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
