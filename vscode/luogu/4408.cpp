#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n, m;
int d[maxn], f[maxn];
int vis[maxn];
ll dis[maxn];
struct edge{
    int v, w;
};

vector<edge> g[maxn];
int maxu;
void dfs1(int u, int fa){
    f[u] = fa;
    if(dis[u] > dis[maxu]) maxu = u;
    for(auto e : g[u]){
        if(e.v == fa) continue;
        dis[e.v] = dis[u] + e.w;
        dfs1(e.v, u);
    }
}
int maxd = 0;
void dfs2(int u){
    if(dis[u] > dis[maxd]) maxd = u;
    //cout << "nowu = " << u << endl;
    for(auto e : g[u]){
        if(e.v == f[u]) continue;
        if(vis[e.v]) continue;
        dis[e.v] = dis[u] + e.w;
        dfs2(e.v);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    
    dfs1(1, 0);
    memset(dis, 0, sizeof(dis));
    memset(f, 0, sizeof(f));
    int A = maxu;
    maxu = 0;
    dfs1(A, 0);
    int B = maxu;
    ll ans = 0;
   // printf("etst: %d %d\n", A, B);

    for(int i = B; i != A; i = f[i]){
        vis[i] = 1;
        maxd = 0;
        //cout << "nowi : " << i << endl;
        dfs2(i);
        //cout << "maxd = " << maxd << endl;
        ans = max({ans, min(dis[B] - dis[i], dis[i]) +  dis[maxd] - dis[i]});
    }
    cout << ans + dis[B] << endl;


	return 0;
}
