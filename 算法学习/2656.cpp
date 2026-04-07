#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 8e4 + 10;
const int maxm = 2e5 + 10;
#define pr pair<int, int>
#define mk make_pair
#define fi first
#define se second

int head[maxn], to[maxm], val[maxm], nxt[maxm], tot;
int r[maxm];
void adde(int u, int v, int w, int rr);
int n, m;
int dfn[maxn], low[maxn], T;
int stk[maxn], top;
bool ins[maxn];
int S[maxn], SCC;
int start;
int sum[maxn];
int f[maxn], in[maxn];

vector<pr> G[maxn];

void dfs(int u);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        double rr;
        cin >> u >> v >> w;
        cin >> rr;
        rr = rr * 10 + 0.5;
        adde(v, u, w, (int)rr);
    }

    cin >> start;

    for(int i = 1; i <= n; i++)
    if(!dfn[i]) dfs(i);

    for(int u = 1; u <= n; u++)
    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i];
        if(S[u] != S[v]) G[S[u]].push_back(mk(S[v], val[i])), in[S[v]]++;
        else {
            int tmp = val[i];
            int w = 0;
            while(tmp){
                w += tmp;
                tmp = tmp * r[i] / 10;
            }
            sum[S[u]] += w;
        }
    }

    queue<int> qu;
    for(int i = 1; i <= SCC; i++)
        if(!in[i]) qu.push(i), f[i] = sum[i];
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        for(auto [v, w] : G[u]){
            f[v] = max(f[v], f[u] + sum[v] + w);
            if(--in[v] == 0) qu.push(v);
        }
    }

    cout << f[S[start]] << endl;


	return 0;
}
void adde(int u, int v, int w, int rr){
    nxt[++tot] = head[u];
    head[u] = tot;
    to[tot] = v;
    val[tot] = w;
    r[tot] = rr;
}

void dfs(int u){
    dfn[u] = low[u] = ++T;
    stk[++top] = u;
    ins[u] = 1;
    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i];
        if(!dfn[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(ins[v]) low[u] = min(low[u], low[v]);
    }

    if(dfn[u] == low[u]){
        ++SCC;
        while(stk[top] != u){
            int p = stk[top--];
            ins[p] = 0;
            S[p] = SCC;
        }
        ins[u] = 0;
        S[u] = SCC;
        --top;
    }
}