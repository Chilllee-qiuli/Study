#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn = 4e5 + 10;
const int inf = 0x3f3f3f3f;

int head[maxn], nxt[maxn], to[maxn], val[maxn], tot;
void adde(int u, int v, int w){
    nxt[++tot] = head[u];
    to[tot] = v;
    head[u]  = tot;
    val[tot] = w;
}

int f[maxn], dep[maxn], siz[maxn], wc[maxn], a[maxn];
void dfs1(int u, int fa){
    f[u] = fa;
    dep[u] = dep[fa] + 1;
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
    dfn[u] = ++cdfn;
    rdfn[cdfn] = u;
    top[u] = Top;
    if(!wc[u]) return ;
    dfs2(wc[u], Top);
    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i];
        if(v == f[u] || v == wc[u]) continue;
        dfs2(v, v);
    }
}
struct Node{
    ll sum;
    int maxx, minn;
    Node(){
        sum = 0;
        maxx = -inf; 
        minn = inf; 
    }
}node[maxn * 4];
int lzy[maxn * 4];


void pushup(int u){
    node[u].maxx = max(node[u << 1].maxx, node[u << 1 | 1].maxx);
    node[u].minn = min(node[u << 1].minn, node[u << 1 | 1].minn);
    node[u].sum = node[u << 1].sum + node[u << 1 | 1].sum;
    //cout << "pushup u = " << u << " sum = " << node[u].sum << " maxx = " << node[u].maxx << " minn = " << node[u].minn << endl;
}

void build(int u, int L, int R){
    if(L == R){
        node[u].sum = a[rdfn[L]];
        node[u].maxx = node[u].sum;
        node[u].minn = node[u].sum;
        //cout << "build u = " << u << " sum = " << node[u].sum << " maxx = " << node[u].maxx << " minn = " << node[u].minn << endl;
        return ;
    }
    int mid = (L + R) >> 1;
    build(u << 1, L, mid);
    build(u << 1 | 1, mid + 1, R);
    pushup(u);
}



int work(int x){
    int u = to[x * 2 - 1] ;
    int v = to[x * 2] ;
    if(f[u] == v) swap(u, v);
    return dfn[v]; 
}

bool inRange(int L, int R, int l, int r){return l <= L && R <= r;}
bool outOfRange(int L, int R, int l, int r){return r < L || R < l;}

void maketag(int u){
    lzy[u] ^= 1;
    swap(node[u].maxx, node[u].minn); 
    node[u].maxx *= -1;
    node[u].minn *= -1;
    node[u].sum *= -1; 
}
void pushdown(int u){
    if(lzy[u]){
        maketag(u << 1);
        maketag(u << 1 | 1);
        lzy[u] = 0;
    }
}
void ddxg(int u, int L, int R, int p, ll x){
    if(L == R){
        node[u].sum = x;
        node[u].maxx = x; 
        node[u].minn = x; 
        return;
    }
    if(lzy[u]) pushdown(u);
    int mid = (L + R) >> 1;
    if(p <= mid) ddxg(u << 1, L, mid, p, x);
    else ddxg(u << 1 | 1, mid + 1, R, p, x);
    pushup(u);
}
Node query(int u, int L, int R, int l, int r){
    Node tmp;
    if(lzy[u]) pushdown(u);
    //pushup(u);
    
    if(inRange(L, R, l, r)) return node[u];
    else if(!outOfRange(L, R, l, r)) {
        int mid = (L + R) >> 1;
        Node lf = query(u << 1, L, mid, l, r), rht = query(u << 1 | 1, mid + 1, R, l, r);
        tmp.sum = lf.sum + rht.sum;
        tmp.maxx = max(lf.maxx, rht.maxx);
        tmp.minn = min(lf.minn, rht.minn);
    }
    //pushup(u);
    return tmp;
}
/*
void maketag(int u, int L, int R, int l, int r){
    if(inRange(L, R, l, r)) lzy[u] ^= 1; 
    else if(!outOfRange(L, R, l, r)){
        if(lzy[u]) pushdown(u);
        int mid = (L + R) >> 1;
        maketag(u << 1, L, mid, l, r);
        maketag(u << 1 | 1, mid + 1, R, l, r);
        pushup(u);
    }
}*/

void modify(int u, int L, int R, int l, int r){
    if(inRange(L, R, l, r)){
        maketag(u);
        return;
    }
    if(outOfRange(L, R, l, r)) return;
    if(lzy[u]) pushdown(u);
    int mid = (L + R) >> 1;
    modify(u << 1, L, mid, l, r);
    modify(u << 1 | 1, mid + 1, R, l, r);
    pushup(u);
}

void work_path(int x, int y){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        modify(1, 1, n, dfn[top[x]], dfn[x]);
        x = f[top[x]];
    }
    modify(1, 1, n, min(dfn[x], dfn[y]) + 1, max(dfn[x], dfn[y]));
}

Node query_path(int x, int y){
    Node res;
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        Node tmp = query(1, 1, n, dfn[top[x]], dfn[x]);
        res.sum += tmp.sum;
        res.maxx = max(res.maxx, tmp.maxx);
        res.minn = min(res.minn, tmp.minn);
        x = f[top[x]];
    }
    Node tmp = query(1, 1, n, min(dfn[x], dfn[y]) + 1, max(dfn[x], dfn[y]));
    res.sum += tmp.sum;
    res.maxx = max(res.maxx, tmp.maxx);
    res.minn = min(res.minn, tmp.minn);
    return res;
}

int main(){

    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u++, v++;
        adde(u, v, w);
        adde(v, u, w);
    }
    

    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);

    //cout << "built" << endl;

    int q;
    cin >> q;
    while(q--){
        string str;
        int x, y;
        cin >> str >> x >> y;
        if(str == "C") ddxg(1, 1, n, work(x), y);
        else if(str == "N") work_path(x + 1, y + 1);
        else {
            Node ans = query_path(x + 1, y + 1);
            if(str == "SUM")
                cout << ans.sum << endl;
            
            else if(str == "MAX")
                cout << ans.maxx << endl;

            else
                cout << ans.minn << endl;

        }
        //cout << "operation done" << endl;
    }



}