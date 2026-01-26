#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int maxm = 1e6 + 10;
int n, m;
int head[maxn], to[maxm], nxt[maxm], tot;
int val[maxn];
int ed = 1;


void add(int u, int v){
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}

int SCC, scc_maxx[maxn], scc_minn[maxn], S[maxn];

int dfn[maxn], low[maxn], T;
int stk[maxn], top;
int ins[maxn];
void dfs(int u){
    dfn[u] = low[u] = ++T;
    stk[++top] = u;
    ins[u] = 1;
    for(int i = head[u]; i; i = nxt[i]){
        if(dfn[to[i]] == 0){
            dfs(to[i]);
            low[u] = min(low[u], low[to[i]]);
        }
        else if(ins[to[i]]) low[u] = min(low[u], low[to[i]]);
    }

    if(dfn[u] == low[u]){
        ++SCC;
        int p;
        do{
            p = stk[top--];
            ins[p] = 0;
            S[p] = SCC;
            if(p == n) ed = SCC;
            scc_maxx[SCC] = max(scc_maxx[SCC], val[p]);
            scc_minn[SCC] = min(scc_minn[SCC], val[p]);
        }while(p != u);
    }

}

vector<int> g[maxn];
vector<int> topo;
queue<int> qu;
int in[maxn];
int dp[maxn];

int main(){
    //freopen("P1073_4.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    memset(scc_minn, 0x3f, sizeof(scc_minn));
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> val[i];

    for(int i = 1; i <= m; i++){
        int u, v, z;
        cin >> u >> v >> z;
        if(z == 1)  add(u, v);        
        else {
            add(u, v);
            add(v, u);
        }
    }
    
    // for(int i = 1; i <= n; i++)
    // if(!dfn[i]) dfs(i);
    dfs(1);

    for(int i = 1; i <= n; i++)
    for(int j = head[i]; j; j = nxt[j])
        if(S[i] != S[to[j]] && dfn[i] && dfn[to[j]]) g[S[i]].push_back(S[to[j]]), in[S[to[j]]]++;

    for(int i = 1; i <= SCC; i++)
    if(in[i] == 0) qu.push(i);

    while(!qu.empty()){
        int u = qu.front(); qu.pop();
        topo.push_back(u);
        for(auto v : g[u]){
            in[v]--;
            if(in[v] == 0) qu.push(v);
        }
    }

    for(auto u : topo){
        dp[u] = max(dp[u], scc_maxx[u] - scc_minn[u]);
        for(auto v : g[u]){
            // scc_maxx[v] = max(scc_maxx[v], scc_maxx[u]);
            scc_minn[v] = min(scc_minn[v], scc_minn[u]);
            dp[v] = max({dp[v], scc_maxx[v] - scc_minn[v], dp[u]});
        }
    }

    if(dfn[n] == 0){
        cout << 0 << "\n";
        return 0;
    }
    cout << max(dp[ed], scc_maxx[ed] - scc_minn[ed]) << "\n";
    


	return 0;
}
