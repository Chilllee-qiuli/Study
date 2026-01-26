#include<bits/stdc++.h>
using namespace std; // P3387
typedef long long ll;
const int maxn = 1e4 + 10;
const int maxm = 1e5 + 10;
vector<int> mp[maxn], G[maxn]; // 原图；缩点后的DAG

int n, m;
int A[maxn]; // 点权
int dfn[maxn], low[maxn], T; // dfs序；经过不超过一条非树边能到达的最浅节点；dfn的cnt：T
int stk[maxn], top; // 维护一个未被分配进SCC的栈
bool ins[maxn]; // 某个点是否在上一行的栈里
int S[maxn], SCC; // 维护某个点在哪个SCC里，以及计数

int sum[maxn]; // 每一个SCC的点权和；
int f[maxn], in[maxn]; // 拓扑排序；in是入度

void dfs(int u){
    dfn[u] =  low[u] = ++T;
    stk[++top] = u;
    ins[u] = 1;
    for(auto v : mp[u]){
        if(dfn[v] == 0){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(ins[v]) low[u] = min(low[u], dfn[v]); // 只有v还在栈中（即还未形成ECC）的时候横叉边有效
    }
    if(dfn[u] == low[u]){
        ++SCC;
        while(stk[top] != u){
            int p = stk[top--];
            ins[p] = 0;
            S[p] = SCC;
            sum[SCC] += A[p];
        }
        ins[u] = 0;
        S[u] = SCC;
        sum[SCC] += A[u];
        --top;
    }
}

queue<int> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> A[i];
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        mp[u].push_back(v);
    }
    for(int i = 1; i <= n; i++)
    if(!dfn[i]) dfs(i); // 注意可能有多个非连通图
    
    for(int i = 1; i <= n; i++)
    for(auto v : mp[i])
        if(S[i] != S[v]) G[S[i]].push_back(S[v]), in[S[v]]++; // 统计入度

    for(int i = 1; i <= SCC; i++)
    if(!in[i]) q.push(i), f[i] = sum[i];
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : G[u]){
            f[v] = max(f[v], f[u] + sum[v]);
            --in[v];
            if(!in[v]) q.push(v);
        }
    }
    int ans = 0;
    for(int i = 1; i <= SCC; i++) 
        ans = max(ans, f[i]);
    
    cout << ans << endl;

	return 0;
}