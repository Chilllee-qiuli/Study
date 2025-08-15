#include<bits/stdc++.h>
using namespace std; // P8435[模板]点双连通分量

typedef long long ll;
const int maxn = 5e5 + 10;
const int maxm = 4e6 + 10;
int n, m;

int head[maxn], nxt[maxm], to[maxm], tot;
void adde(int u, int v){
    nxt[++tot] = head[u];
    to[head[u] = tot] = v;
}

int dfn[maxn], low[maxn], cnt;
int stk[maxn], top;
int VBCC;
vector < int > Ans[maxn]; // 这里记录的是每个VBCC里边有谁

void dfs(int u, int fa){
    dfn[u] = low[u] = ++cnt;
    stk[++top] = u;
    int son = 0;
    for(int i = head[u]; i; i = nxt[i]){
        if(to[i] == fa) continue;
        if(!dfn[to[i]]){
            ++son;
            dfs(to[i], u);
            low[u] = min(low[u], low[to[i]]);
            if(low[to[i]] >= dfn[u]){ 
                // >= 表明u是一个割点，意义是子树为划分的结点无法到u的任何祖先
                // 同时也表明，删掉u会导致子树v中没有划分的点形成点双连通分量
                ++VBCC;
                while(stk[top] != to[i]) Ans[VBCC].push_back(stk[top--]); 
                Ans[VBCC].push_back(to[i]); --top;
                Ans[VBCC].push_back(u);
                // 注意此时u不能出栈了，因为他可能同时属于多个点双连通分量或者他是一个割点
                // 不可能存在一个大于一个点的点集同时存在于两个VBCC中，或者说不存在一条边共存于两个VBCC
            }
        }
        else low[u] = min(low[u], dfn[to[i]]);
    }
    // if(fa == 0 && son >= 2) 则根也是割点
    // 下面这句这里特判的是图的孤立点
    if(fa == 0 && son == 0) Ans[++VBCC].push_back(u);
    
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

    for(int i = 1; i <= n; i++){
        top = 0; // 每次操作完割点可能会留在里边
        if(!dfn[i]) dfs(i, 0);
    }

    cout << VBCC << endl;
    for(int i = 1; i <= VBCC; i++){
        cout << Ans[i].size();
        for(auto u : Ans[i]){
            cout << " " << u;
        }
        cout << endl;
    }
    

	return 0;
}
