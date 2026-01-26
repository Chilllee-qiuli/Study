#include<bits/stdc++.h>
using namespace std; // P2863
typedef long long ll; // 洛谷进阶篇std
const int maxn = 2e5 + 10;
const int maxm = 5e4 + 10;

int n, m;
int head[maxn], nxt[maxn], to[maxn], tot;
void adde(int u, int v){
    nxt[++tot] = head[u]; to[head[u] = tot] = v;
}

int dfn[maxn], low[maxn], T;
int stk[maxn], top;
bool ins[maxn];
int SCC[maxn], scc, siz[maxn];

void dfs(int u){
    dfn[u] = low[u] = ++T;
    ins[stk[++top] = u] = 1;
    for(int i = head[u]; i; i = nxt[i]){
        if(dfn[to[i]] == 0) {
            dfs(to[i]);
            low[u] = min(low[u], low[to[i]]);
        } 
        else if(ins[to[i]]){ // 只有v还在栈中（即还未形成ECC）的时候横叉边有效
            low[u] = min(low[u], dfn[to[i]]);
        }
    }
    if(low[u] == dfn[u]){
        int v; ++scc;
        do{
            v = stk[top--];
            SCC[v] = scc;
            ins[v] = 0;
            ++siz[scc];
        }while(v != u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;

    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        adde(u, v);
    }

    for(int i = 1; i <= n; i++){
        if(!dfn[i]) dfs(i);
    }

    int ans = 0 ;
    for(int i = 1; i <= scc; i++)
    if(siz[i] > 1) ans++;

    cout << ans << endl;

	return 0;
}