#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 10;
const int maxm = 5e4 + 10;

int n, m;

int head[maxn], to[maxm], nxt[maxm], tot = 1;
void adde(int u, int v){
    nxt[++tot] = head[u];
    to[head[u] = tot] = v;
}

int dfn[maxn], low[maxn], cnt;
int stk[maxn], top;
int bel[maxn], siz[maxn], ECC;
bool ins[maxn];
void dfs(int u){ // 有向图不需要lst
    dfn[u] = low[u] = ++cnt;
    stk[++top] = u;
    ins[u] = 1;
    for(int i = head[u]; i; i = nxt[i]){
        if(!dfn[to[i]]){
            dfs(to[i]);
            low[u] = min(low[u], low[to[i]]);
            //if(low[to[i]] > dfn[u]) 
        }
        else if(ins[to[i]]) low[u] = min(low[u], dfn[to[i]]); // 只有v还在栈中（即还未形成ECC）的时候横叉边有效
    }

    if(low[u] == dfn[u]){
        ++ECC;
        int v;
        do{
            v = stk[top--];
            ins[v] = 0;
            bel[v] = ECC;
            ins[v] = 0;
            ++siz[ECC];
        }while(v != u);
    }

}

set < int > mp[maxn];
int deg[maxn];

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;

    for(int i = 1, u, v; i <= m; i++){
        cin >> u >> v;
        adde(u, v);
    }

    for(int i = 1; i <= n; i++)
        if(!dfn[i]) dfs(i);

    for(int u = 1; u <= n; u++)
    for(int i = head[u]; i; i = nxt[i])
        if(bel[u] != bel[to[i]])
            mp[bel[u]].insert(bel[to[i]]);
    
    int ans = 0, lst = 0;
    for(int i = 1; i <= ECC; i++)
    if(mp[i].size() == 0) ans++, lst = i;

    if(ans == 1) cout << siz[lst] << endl;
    else cout << 0 << endl;


	return 0;
}