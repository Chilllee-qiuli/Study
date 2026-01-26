#include<bits/stdc++.h>
using namespace std; 
typedef long long ll; // 洛谷进阶篇std
const int maxn = 5050;
const int maxm = 2e4 + 10;
int n, m;

int head[maxn], to[maxm], nxt[maxm], tot = 1;
void adde(int u, int v){
    nxt[++tot] = head[u];
    to[head[u] = tot] = v;
}

int deg[maxn]; // 统计度数
int dfn[maxn], low[maxn], cnt;
int stk[maxn], top, bel[maxn]; // bel: 这个点属于哪个EBCC

int EBCC;
pair<int, int> brige[maxn]; int anscnt;

void dfs(int u, int lst){
    dfn[u] = low[u] = ++cnt;
    stk[++top] = u;
    for(int i = head[u]; i; i = nxt[i]){
        if(i == lst) continue;
        if(!dfn[to[i]]){
            dfs(to[i], i ^ 1);
            low[u] = min(low[u], low[to[i]]);

        }
        else low[u] = min(low[u], dfn[to[i]]);
    }

    if(low[u] == dfn[u]){
        int v; ++EBCC;
        do{
            v = stk[top--];
            bel[v] = EBCC;
        }while(v != u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adde(u, v);
        adde(v, u);
    }

    for(int i = 1; i <= n; i++)
        if(!dfn[i]) dfs(i, 0);

    for(int i = 2; i <= tot; i += 2){
        int u = to[i], v = to[i^1];
        if(bel[u] != bel[v]) // 找出所有的割边
        ++deg[bel[u]], ++deg[bel[v]];
    }
    
        int ans = 0 ;
    for(int i = 1; i <= EBCC; i++){
        ans += deg[i] == 1;
    }

        cout << (ans + 1) / 2 << endl;

	return 0;
}