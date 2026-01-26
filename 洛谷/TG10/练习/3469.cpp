#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
const int maxn = 1e5 + 10;
const int maxm = 1e6 + 10;
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
int siz[maxn];
ll ans[maxn];
vector <int> tmp;

void dfs(int u, int fa){

    dfn[u] = low[u] = ++cnt;
    stk[++top] = u;
    int son = 0;
    siz[u] = 1;
    ll ans_tmp = 0;
    ll Siz = 0;
    tmp.clear();
    for(int i = head[u]; i; i = nxt[i]){
        if(to[i] == fa) continue;
        if(!dfn[to[i]]){
            ++son;
            dfs(to[i], u);
            low[u] = min(low[u], low[to[i]]);
            siz[u] += siz[to[i]];
            tmp.push_back(siz[to[i]]);

            if(low[to[i]] >= dfn[u]) { // 不能走到祖先的儿子们各自成为一个连通块
                cut[u] = 1; // 注意**等于**  
                Siz += siz[to[i]];
                ans_tmp += 1ll * siz[to[i]] * siz[to[i]];

            }
        }
        else low[u] = min(low[u], dfn[to[i]]);
    } 
    ans[u] += 2ll* (n - 1);
    // if(fa == 0 && son >= 2) 则根也是割点
    if (u == root && son >= 2) {
        cut[u] = 1;
    }
    if(cut[u]){
        if(u != root){
            ll fa_siz = n - 1 - Siz;
            ans_tmp += fa_siz * fa_siz;
        }
       ans[u] += 1ll * (n - 1) * (n - 1) - ans_tmp;// 能走到祖先的和割点是同一个连通块
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

    for(int i = 1; i <= n; i++){
        top = 0; // 每次操作完割点可能会留在里边
        if(!dfn[i]) {
            root = i;
            dfs(i, 0);
        }
    }

    for(int i = 1; i <= n; i++)
        cout << ans[i] << endl;

	return 0;
}