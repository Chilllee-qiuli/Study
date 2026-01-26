#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10; // 注意为了保持模板泛用性，去掉了%p的所有操作
// const int maxm = 2e5 + 10;
int n, m, r;
int fa[maxn], siz[maxn], dep[maxn], wson[maxn], a[maxn];

vector< int > mp[maxn];

void dfs1(int u, int f){
    fa[u] = f;
    siz[u] = 1;
    dep[u] = dep[f] + 1;
    for(auto v : mp[u]){
        if(v == f) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if(siz[v] > siz[wson[u]]) wson[u] = v; // 确定重孩子
    }
}

int dfn[maxn], vistime, rdfn[maxn], top[maxn];
void dfs2(int u, int Top) {
    dfn[u] = ++vistime; // 确定dfn序，由于dfn序依赖重儿子的确定，所以必须放在dfs2   !!!
    rdfn[vistime] = u; // 反向确定DFS序第 vistime 个结点是 u
    top[u] = Top;
    if(wson[u] == 0) return ;
    dfs2(wson[u], Top);
    for(auto v : mp[u]){
        if(v == fa[u] || v == wson[u]) continue;
        dfs2(v, v);
    }
}

// 线段树部分
ll w[maxn * 4], lzy[maxn * 4];
void pushup(int u) {w[u] = (w[u << 1] + w[u << 1 | 1]) ;}

void build(int u, int L, int R){
    if(L == R) {
        w[u] = a[rdfn[L]]; // 到达叶节点，该区间的点权是DFS序上第L个结点的权值， 即a[rdfn[L]]  !!!
        return ;
    }
    int M = (L + R) >> 1;
    build(u << 1, L, M); build(u << 1 | 1, M + 1, R);
    pushup(u);
}

bool InRange(int L, int R, int l, int r) {return l <= L && R <= r;}
bool OutofRange(int L, int R, int l, int r) {return r < L || R < l;}

void maketag(int u, int len, ll x){
    lzy[u] += x;
    w[u] += x * len ;
    //lzy[u] %= p;
}

void pushdown(int u, int L, int R){
    if(lzy[u] == 0) return; // 如果没有懒标记，直接返回
    int M = (L + R) >> 1;
    maketag(u << 1, M - L + 1, lzy[u]);
    maketag(u << 1 | 1, R - M, lzy[u]);
    lzy[u] = 0;
}

ll qjcx(int u, int L, int R, int l, int r){
    if(InRange(L, R, l, r)) return w[u];
    if(OutofRange(L, R, l, r)) return 0;
    pushdown(u, L, R);
    int M = (L + R) >> 1;
    return (qjcx(u << 1, L, M, l, r) + qjcx(u << 1 | 1, M + 1, R, l, r));
}

void qjxg(int u, int L, int R, int l, int r, ll x){
    if(InRange(L, R, l, r)) {
        maketag(u, R - L + 1, x);
        return;
    }
    if(OutofRange(L, R, l, r)) return;
    pushdown(u, L, R);
    int M = (L + R) >> 1;
    qjxg(u << 1, L, M, l, r, x);
    qjxg(u << 1 | 1, M + 1, R, l, r, x);
    pushup(u);
}

void upd(int x, int y, ll z){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        qjxg(1, 1, n, dfn[top[x]], dfn[x], z); // 把跳链这段区间先给修改了
        x = fa[top[x]];
    }
    qjxg(1, 1, n, min(dfn[x], dfn[y]), max(dfn[x], dfn[y]), z); // 最后在同一个链上
}

ll qry(int x, int y){
    ll res = 0;
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        res += qjcx(1, 1, n, dfn[top[x]], dfn[x]); // 注意较深的点 DFS 序大，整条链是从上到下铺展
        x = fa[top[x]];
    }
    res += qjcx(1, 1, n, min(dfn[x], dfn[y]), max(dfn[x], dfn[y]));
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    dfs1(r, 0);
    dfs2(r, r);
    build(1, 1, n);
    for(int op, x, y, z; m; --m){
        cin >> op;
        if(op == 1){
            cin >> x >> y >> z;
            upd(x, y, z); // 表示将树从 x 到 y 结点最短路径上所有节点的值都加上 z
        }
        else if(op == 2){
            cin >> x >> y;
            cout << qry(x, y) << "\n"; // 表示求树从 x 到 y 结点最短路径上所有节点的值之和。
        }
        else if(op == 3){
            cin >> x >> z;
            qjxg(1, 1, n, dfn[x], dfn[x] + siz[x] - 1, z); // 表示将以 x 为根节点的子树内所有节点值都加上 z。
            // 这里很巧妙的利用 DFS 序，一个结点子树内的 DFS 序是连续的
        }
        else {
            cin >> x;
            cout << qjcx(1, 1, n, dfn[x], dfn[x] + siz[x] - 1) << "\n"; // 表示求以 x 为根节点的子树内所有节点的值之和。
        }

    }

	return 0;
}
