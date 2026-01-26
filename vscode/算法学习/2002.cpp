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

int SCC, S[maxn];

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
        }while(p != u);
    }

}

int in[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        add(u, v);
    }

    for(int i = 1; i <= n; i++)
    if(!dfn[i])dfs(i);

    for(int i = 1; i <= n; i++)
    for(int j = head[i]; j; j = nxt[j])
    if(S[i] != S[to[j]])  in[S[to[j]]]++;

    int ans = 0;
    for(int i = 1; i <= SCC; i++) ans += (in[i] == 0);

    cout << ans << endl;

	return 0;
}
