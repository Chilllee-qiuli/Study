#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
vector<int> g[maxn];
int du[maxn], val[maxn], vis[maxn];
int f[maxn];
int n;
int ans ;

void tuopu();
void dfs(int u, int fa){
    f[u] += val[u];
    int maxx = 0;
    for(auto v : g[u]){
        if(!vis[v] || v == fa) continue;
        dfs(v, u);
        ans = max(ans, maxx + f[v] + val[u]);
        maxx = max(maxx, f[v]);
    }
    f[u] += maxx;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> val[i];

    for(int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        du[u]++;
        du[v]++;
    }

    tuopu();
    for(int i = 1; i <= n; i++)
    if(!vis[i]) dfs(i, 0);

	return 0;
}
void tuopu(){
    queue<int> qu;
    for(int i = 1; i <= n; i++)
        if(du[i] == 1) qu.push(i);

    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto v : g[u]){
            if(vis[v]) continue;
            if(--du[v] == 1) qu.push(v);
        }
    }

}