#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
#define pr pair<int, int>
#define fi first
#define se second
#define mk make_pair
int n;
vector<int> tree[maxn];
int son[maxn], dp[maxn][2];
int ans;

void dfs(int u, int fa)
{
    vector<pr> sonv;
    for (auto v : tree[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        sonv.push_back(mk(dp[v][0] + 1, dp[v][1]));
        son[u]++;
    }

    sort(sonv.begin(), sonv.end(), [](const pr &a, const pr &b)
         { return (a.se - a.fi) < (b.se - b.fi); });
    // 排前面，说明保留消耗比删掉小
    for (int i = 0; i < sonv.size(); i++)
    {
        if (i < 2)
            dp[u][0] += sonv[i].second;
        else
            dp[u][0] += sonv[i].first;

        if (!i)
            dp[u][1] += sonv[i].second;
        else
            dp[u][1] += sonv[i].first;
    }
    //printf("%d %d %d\n", u, dp[u][0], dp[u][1]);

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0);

    cout << min(dp[1][0], dp[1][1]) << '\n';

    return 0;
}
