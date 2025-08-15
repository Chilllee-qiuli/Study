#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
const int maxn = 5e5 + 10;
const int maxm = 4e6 + 10;
int n, m, root;

int head[maxn], nxt[maxm], to[maxm], tot;
void adde(int u, int v){
    nxt[++tot] = head[u];
    to[head[u] = tot] = v;
}

int dfn[maxn], low[maxn], cnt;
int stk[maxn], top;
int VBCC;
int cut[maxn];

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
            if(low[to[i]] >= dfn[u] && u != root) cut[u] = 1; // 注意**等于**
        }
        else low[u] = min(low[u], dfn[to[i]]);
    }
    // if(fa == 0 && son >= 2) 则根也是割点
    if (u == root && son >= 2) {
        cut[u] = 1;
    }
    
}
vector <int > ans ;

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
        if(!dfn[i]) {
            root = i;
            dfs(i, 0);
        }
    }

    for(int i = 1; i <= n; i++)
        if(cut[i]) ans.push_back(i);

    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(auto it : ans) cout << it << " ";
    

	return 0;
}