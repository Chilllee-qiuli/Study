#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5050;

vector<int> g[maxn];
int n; 
int ans[maxn];
int siz[maxn];

void dfs(int u, int fa){
    siz[u]++;
    vector<int> son;
    if(!g[u].size()) return;

    for(auto v : g[u]){
        if(v == fa) continue;
        dfs(v, u);
        siz[u] += siz[v];
        //if(siz[v]) ans.push_back(siz[v]);
        if(siz[v]) son.push_back(siz[v]);
        
    }
    //ans.push_back(siz[u] - 1);
    vector<int> vis(siz[u], 0);
    vis[0] = 1;
    for(auto it : son)
    for(int w = siz[u] - 1; w >= it; w--){
        vis[w] |= vis[w - it];
    }

    for(int i = 1; i < siz[u]; i++)
    ans[i] |= vis[i];

} 


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);

    int cnt = 0;
    for(int i = 1; i <= n - 2; i++)
    if(ans[i]) ans[n - i - 1] |= ans[i];
    for(int i = 1; i <= n - 2; i++) 
    if(ans[i]) cnt++;
    
    cout << cnt << "\n";

    for(int i = 1; i <= n - 2; i++)
    if(ans[i]) cout << i << " " << n - i - 1 << "\n";
    




    return 0;
}