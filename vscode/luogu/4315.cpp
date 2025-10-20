#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const ll INF = -0x3f3f3f3f3f3f3f3f;
int n;

int head[maxn], nxt[maxn], to[maxn], val[maxn], tot;
void adde(int u, int v, int w){
    nxt[++tot] = head[u];
    to[head[u] = tot] = v;
    val[tot] = w;
} 
int a[maxn];
int f[maxn], dep[maxn], wc[maxn], siz[maxn];
void dfs1(int u, int fa){
    f[u] = fa;
    dep[u] = dep[fa] + 1;
    siz[u] = 1;
    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i];
        if(v == fa) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        a[v] = val[i];
        if(siz[v] > siz[wc[u]]) wc[u] = v;
    }
}

int top[maxn], dfn[maxn], rdfn[maxn], cdfn;
void dfs2(int u, int Top){
    top[u] = Top;
    dfn[u] = ++cdfn;
    rdfn[cdfn] = u;
    if(!wc[u]) return;
    dfs2(wc[u], Top);
    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i];
        if(v == f[u] || v == wc[u]) continue;
        dfs2(v, v);
    }
}

ll maxx[maxn * 4];
ll lzy1[maxn * 4], lzy2[maxn * 4]; 
void pushup(int u){
    maxx[u] = max(maxx[u << 1], maxx[u << 1 | 1]);
}
void build(int u, int L, int R){
    lzy1[u] = -1;
    if(L == R){
        maxx[u] = a[rdfn[L]];
        return;
    }
    int mid = (L + R) >> 1;
    build(u << 1, L, mid);
    build(u << 1 | 1, mid + 1, R);
    pushup(u);
}

bool inRange(int L, int R, int l, int r){return l <= L && R <= r;}
bool outOfRange(int L, int R, int l, int r){return r < L || R < l;}

// 关于maketag：先处理本层，然后记录标记
// pushdown的时候maketag处理子节点
// 这样保证每次pushdown结束的时候其儿子节点都是正确的数据。保证查询正确
void maketag(int u, int type, ll x){
    if(type == 1){
        lzy1[u] = x;
        lzy2[u] = 0;
        maxx[u] = x;
    }
    else {
        // 这里不太清楚要不要先判断有没有赋值标记，我认为应该不用判断，因为一旦有标记maxx肯定已经存了的
        if(lzy1[u] != -1){
            lzy1[u] += x;
            maxx[u] = lzy1[u];
        } else {
            lzy2[u] += x;
            maxx[u] += x;
        }
    }
}

void pushdown(int u, int L, int R){
    if(lzy1[u] != -1){
        maketag(u << 1, 1, lzy1[u]);
        maketag(u << 1 | 1, 1, lzy1[u]);
        lzy1[u] = -1;
        //lzy2[u] = 0;
    }
    if(lzy2[u]){
        maketag(u << 1, 2, lzy2[u]);
        maketag(u << 1 | 1, 2, lzy2[u]);
        lzy2[u] = 0;
    }
}


void ddxg(int u, int L, int R, int p, int x){
    if(L == R){
        maxx[u] = x;
        lzy1[u] = -1;  // 重置标记
        lzy2[u] = 0;
        return ;
    }
    pushdown(u, L, R);
    int mid = (L + R) >> 1;
    if(p <= mid) ddxg(u << 1, L, mid, p, x);
    else ddxg(u << 1 | 1, mid + 1, R, p, x);
    pushup(u);
}

void qjxg(int u, int L, int R, int l, int r, int type, ll x){
    if(inRange(L, R, l, r)){
        maketag(u, type, x);
        return;
    }
    pushdown(u, L, R);
    int mid = (L + R) >> 1;
    if(l <= mid) qjxg(u << 1, L, mid, l, r, type, x);
    if(r > mid) qjxg(u << 1 | 1, mid + 1, R, l, r, type, x);
    pushup(u);
}

void cover(int x, int y, ll w){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        qjxg(1, 1, n, dfn[top[x]], dfn[x], 1, w);
        x = f[top[x]];
    }
    if(x == y) return;
    if(dep[x] < dep[y]) swap(x, y);
    qjxg(1, 1, n, dfn[y] + 1, dfn[x], 1, w);
}

void add(int x, int y, ll w){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        qjxg(1, 1, n, dfn[top[x]], dfn[x], 2, w);
        x = f[top[x]];
    }
    if(x == y) return;
    if(dep[x] < dep[y]) swap(x, y);
    qjxg(1, 1, n, dfn[y] + 1, dfn[x], 2, w);
}

ll qjcx(int u, int L, int R, int l, int r){
    if(inRange(L, R, l, r)) return maxx[u];
    pushdown(u, L, R);
    int mid = (L + R) >> 1;
    ll res = INF;
    if(l <= mid) res = max(res, qjcx(u << 1, L, mid, l, r));
    if(r > mid) res = max(res, qjcx(u << 1 | 1, mid + 1, R, l, r));
    return res;
}

ll qry(int x, int y){
    ll res = INF;
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        res = max(res, qjcx(1, 1, n, dfn[top[x]], dfn[x]));
        x = f[top[x]];
    }
    if(x == y) return res;
    if(dep[x] < dep[y]) swap(x, y);
    return max(res, qjcx(1, 1, n, dfn[y] + 1, dfn[x]));
}

int main(){
    // freopen("1.in", "r", stdin);
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
        if(str == "Stop") break;
        if(str == "Change") {
            int k, w;
            cin >> k >> w;
            int edge_id = k * 2;
            int u = to[edge_id - 1], v = to[edge_id];
            if(dep[u] > dep[v]) {
                ddxg(1, 1, n, dfn[u], w);
            } else {
                ddxg(1, 1, n, dfn[v], w);
            }        
        }
        else if(str == "Cover"){
            int u, v, w;
            cin >> u >> v >> w;
            cover(u, v, w);
        }
        else if(str == "Add"){
            int u, v, w;
            cin >> u >> v >> w;
            add(u, v, w);
        }
        else {
            int u, v;
            cin >> u >> v;
            cout << qry(u, v) << endl;
        }
    }

    return 0;
}