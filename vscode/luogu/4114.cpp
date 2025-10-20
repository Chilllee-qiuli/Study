#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n;
int head[maxn], to[maxn], nxt[maxn], val[maxn], tot;
int a[maxn];

void adde(int u, int v, int w){
    nxt[++tot] = head[u];
    to[head[u] = tot] = v;
    val[tot] = w;
}

int f[maxn], dth[maxn], siz[maxn], wc[maxn];

void dfs1(int u, int fa){
    dth[u] = dth[fa] + 1;
    f[u] = fa;
    siz[u] = 1;
    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i];
        if(v == fa) continue;
        a[v] = val[i];
        dfs1(v, u);
        siz[u] += siz[v];
        if(siz[v] > siz[wc[u]]) wc[u] = v;
    }
}

int top[maxn], dfn[maxn], rdfn[maxn], cdfn;

void dfs2(int u, int Top){
    top[u] = Top;
    dfn[u] = ++cdfn;
    rdfn[cdfn] = u;
    if(wc[u] == 0) return ;
    dfs2(wc[u], Top);
    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i];
        if(v == f[u] || v == wc[u]) continue;
        dfs2(v, v);
    }
}

ll w[maxn * 4];

void pushup(int u) {w[u] = max(w[u << 1], w[u << 1 | 1]);}
void build(int u, int L, int R){
    if(L == R){
        w[u] = a[rdfn[L]];
        return; 
    }
    int mid = (L + R) >> 1;
    build(u << 1, L, mid);
    build(u << 1 | 1, mid + 1, R);
    pushup(u);
}

bool inrange(int L, int R, int l, int r){return l <= L && R <= r;}
bool outofrange(int L, int R, int l, int r){return r < L || R < l;}


int query(int u, int L, int R, int l, int r){
    if(inrange(L, R, l, r)) return w[u];
    else if(outofrange(L, R, l, r)) return 0;
    else {
        int mid = (L + R) >> 1;
        return max(query(u << 1, L, mid, l, r), query(u << 1 | 1, mid + 1, R, l, r));
    }
}

void ddxg(int u, int L, int R, int p, ll x){
    if(L == R){
        w[u] = x;
        return ;
    }
    int mid = (L + R) >> 1;
    if(p <= mid) ddxg(u << 1, L, mid, p, x);
    else ddxg(u << 1 | 1, mid + 1, R, p, x);
    pushup(u);
}

int qry(int x, int y){
    int ans = 0;
    while(top[x] != top[y]){
        if(dth[top[x]] < dth[top[y]]) swap(x, y);
        ans = max(ans, query(1, 1, n, dfn[top[x]], dfn[x]));
        x = f[top[x]];
    }
    if(x == y) return ans;
    return max(ans, query(1, 1, n, min(dfn[x], dfn[y]) + 1, max(dfn[x], dfn[y])));
    //关于+1： 绑定后 u 到 v 的路径上没有 lca(u, v)
}

int work(int x){
    x *= 2;
    int v = to[x];
    int u = to[x - 1];
    if(f[u] == v) swap(u, v);
    return dfn[v]; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adde(u, v, w);
        adde(v, u, w);
    }

    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);

    string str;
    while(cin >> str){
        if(str == "DONE") return 0;
        int x, y;
        cin >> x >> y;
        if(str == "CHANGE") ddxg(1, 1, n, work(x), y);
        else if(x == y) cout << 0 << endl;
        else cout << qry(x, y) << endl;
        
    }

	return 0;
}
