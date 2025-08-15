#include<bits/stdc++.h>
using namespace std; // P8436[模板]边双连通分量
typedef long long ll;
const int maxn = 1e6 + 14;
const int maxm = 4e6 + 14;
int n, m;
// 链式前向星
int head[maxm], nxt[maxm], to[maxm], tot = 1;
void adde(int u, int v){
    nxt[++tot] = head[u];
    to[head[u] = tot] = v;
}

int dfn[maxn], low[maxn], cnt;
bool brige[maxm]; // 某一条边是不是桥

void dfs(int u, int lst){
    dfn[u] = low[u] = ++cnt;
    for(int i = head[u]; i; i = nxt[i]){
        if(i == lst) continue;
        if(dfn[to[i]] == 0){
            dfs(to[i], i ^ 1); // !! 注意写法，防止走同一条边回到父节点
            low[u] = min(low[u], low[to[i]]);
            if(low[to[i]] > dfn[u]) brige[i] = brige[i^1] = 1;
        }
        else low[u] = min(low[u], dfn[to[i]]);
    }
}

bool vis[maxn]; // 某个点是否已经属于一个EBCC
vector < int > ans[maxn]; // 记录每个EBCC有哪些点
int EBCC; // EBCC计数

// 显然，不走桥能搜到的点都在同一个EBCC之中
void dfs2(int u){
    ans[EBCC].push_back(u);
    vis[u] = 1;
    for(int i = head[u]; i; i = nxt[i]){
        if(brige[i]) continue; // 如果这条边是桥就不走了
        if(!vis[to[i]]) dfs2(to[i]);
    }
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++){
        cin >> u >> v;
        adde(u, v);
        adde(v, u);
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i]) dfs(i, 0);
    for(int i = 1; i <= n; i++)
        if(!vis[i]){
            ++EBCC;
            dfs2(i);
        }
    cout << EBCC << endl;
    for(int i = 1; i <= EBCC; i++){
        cout << ans[i].size() << " ";
        for(auto u : ans[i]) cout << u << " ";
        cout << endl;
    }
    
	return 0;
}
