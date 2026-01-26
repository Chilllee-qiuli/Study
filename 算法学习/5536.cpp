#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n, k;
int dep[maxn];
int maxd[maxn];

vector<int> g[maxn];
int maxdep, maxu;
int fa[maxn];

void dfs1(int u, int f){
    dep[u] = dep[f] + 1;
    if(dep[u] > maxdep){
        maxdep = dep[u];
        maxu = u;
    }
    for(auto v : g[u]){
        if(v == f) continue;
        fa[v] = u;
        dfs1(v, u);
    }
}

void dfs2(int u, int f){
    dep[u] = dep[f] + 1;
    maxd[u] = dep[u];
    for(auto v : g[u]){
        if(v == f) continue;
        dfs2(v, u);
        maxd[u] = max(maxd[u], maxd[v]);
    }
}
int tmp[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    memset(dep, 0, sizeof(dep));
    maxdep = 0;
    dfs1(maxu, 0);
    memset(dep, 0, sizeof(dep));
    
    int mid = maxu;
    for(int i = 1; i <= (maxdep - 1)/2; i++) mid = fa[mid];

    dfs2(mid, 0);



    for(int i = 1; i <= n; i++) tmp[i] = maxd[i] - dep[i];
    sort(tmp + 1, tmp + 1 + n, greater<int>() );
    int ans = 0;
    for(int i = k + 1; i <= n; i++) ans = max(ans, tmp[i] + 1);
    cout << ans << endl;
 


    return 0;
}