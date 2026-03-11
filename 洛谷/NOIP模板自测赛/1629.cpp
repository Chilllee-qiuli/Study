#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int maxm = 4e5 + 10;

template <typename T>
struct Graph
{
    int head[maxn], to[maxm], nxt[maxm], tot;
    T val[maxm];
    T dis[maxn];
    int vis[maxn];

    Graph() : tot(0)
    {
        memset(head, 0, sizeof(head));
        memset(dis, 0x3f, sizeof(dis));
        memset(vis, 0, sizeof(vis));
    }

    void adde(int u, int v, T w)
    {
        nxt[++tot] = head[u];
        head[u] = tot;
        to[tot] = v;
        val[tot] = w;
    }

    struct Node
    {
        int u;
        T dis;
        bool operator>(const Node &x) const
        {
            return dis > x.dis;
        }
    };

    void dijk(int s)
    {
        memset(dis, 0x3f, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        dis[s] = 0;
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push({s, 0});
        while (!pq.empty())
        {
            Node tp = pq.top();
            pq.pop();
            if (vis[tp.u])
                continue;
            vis[tp.u] = 1;
            int u = tp.u;
            for (int i = head[u]; i; i = nxt[i])
            {
                int v = to[i];
                if (dis[u] + val[i] < dis[v])
                {
                    dis[v] = dis[u] + val[i];
                    pq.push({v, dis[v]});
                }
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    Graph<ll> g_forward, g_backward;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g_forward.adde(u, v, w);
        g_backward.adde(v, u, w);
    }

    g_forward.dijk(1);
    ll dis_forward[maxn];
    memcpy(dis_forward, g_forward.dis, sizeof(g_forward.dis));

    g_backward.dijk(1);
    ll dis_backward[maxn];
    memcpy(dis_backward, g_backward.dis, sizeof(g_backward.dis));

    ll ans = 0;
    for (int i = 2; i <= n; i++)
        ans += dis_forward[i] + dis_backward[i];

    cout << ans << endl;

    return 0;
}
