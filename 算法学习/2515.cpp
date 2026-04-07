#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 10;
const int maxm = 1e5 + 10;

vector<int> g[maxn], G[maxn];
int Val[maxn], Wei[maxn];
int n, m;
int dfn[maxn], low[maxn], T;
int stk[maxn], top;
bool ins[maxn];
int S[maxn], SCC;

int wei[maxn], val[maxn];
int f[maxn], in[maxn];

void dfs(int u){
    dfn[u] = low[u] = ++T;
    stk[++top] = u;
    ins[u] = 1;
    for(auto v : g[u]){
        if(!dfn[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(ins[v]) low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]){
        ++SCC;
        while(stk[top] != u){
            int p = stk[top--];
            ins[p] = 0;
            S[p] = SCC;
            val[SCC] += Val[p];
            wei[SCC] += Wei[p];
        }
        ins[u] = 0;
        S[u] = SCC;
        val[SCC] += Val[u];
        wei[SCC] += Wei[u];
        --top;
    }
}

int dp[500][maxn];
void dfs2(int u){
    for(int i = m; i >= wei[u]; i--)
    dp[u][i] = max(dp[u][i], dp[u][i - wei[u]] + val[u]);

    for(auto v : G[u]){
        dfs2(v);
        for (int j = m; j >= wei[u]; --j)
        for (int k = 0; k <= j - wei[u]; ++k)
        dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);

    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> Wei[i];

    for(int i = 1; i <= n; i++) cin >> Val[i];

    for(int i = 1; i <= n; i++){
        int fa;
        cin >> fa;
        g[fa].push_back(i);
    }

    for(int i = 1; i <= n; i++)
    if(!dfn[i]) dfs(i);

    for(int i = 1; i <= n; i++)
    for(auto v : g[i])
        if(S[i] != S[v]) G[S[i]].push_back(S[v]), in[S[v]]++;

    for(int i = 1; i <= SCC; i++){
        if(!in[i]) G[0].push_back(i);
    }

    dfs2(0);

    cout << dp[0][m] << endl;


	return 0;
}
