#include<bits/stdc++.h>
using namespace std; // P1656
typedef long long ll; // 洛谷进阶篇std
const int maxn = 160;
const int maxm = 5050 * 2;
int n, m;

int head[maxn], to[maxm], nxt[maxm], tot = 1;
void adde(int u, int v){
    nxt[++tot] = head[u];
    to[head[u] = tot] = v;
}

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
            if(low[to[i]] > dfn[u]) brige[++anscnt] = make_pair (min(u, to[i]), max(u, to[i]));
        }
        else low[u] = min(low[u], dfn[to[i]]);
    }

    if(low[u] == dfn[u]){
        int v; ++EBCC;
        do{
            v = stk[top--]; // ! 是top--不是--top
            bel[v] = EBCC;
        }while(v != u);
    }
}

bool cmp(pair<int, int> cmpx, pair<int, int> cmpy){
    return cmpx.first == cmpy.first ? cmpx.second < cmpy.second : cmpx.first < cmpy.first;
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
    
    sort(brige + 1, brige + 1 + anscnt, cmp);

    for(int i = 1; i <= anscnt; i++)
        cout << brige[i].first << " " << brige[i].second << endl;

	return 0;
}
