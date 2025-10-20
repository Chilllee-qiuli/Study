#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int dth[maxn], siz[maxn], wc[maxn], f[maxn];
int cur[maxn];

vector<int> mp[maxn];

void dfs1(int u, int fa){
    dth[u] = dth[fa] + 1;
    siz[u] = 1;
    f[u] = fa;
    for(auto v : mp[u]){
        if(v == fa) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if(siz[v] > siz[wc[u]]) wc[u] = v;
    }
}

int dfn[maxn], rdfn[maxn], cdfn;
int top[maxn];

void dfs2(int u, int Top){
    dfn[u] = ++cdfn;
    rdfn[cdfn] = u;
    top[u] = Top;
    if(wc[u] == 0) return ;
    dfs2(wc[u], Top);
    for(auto v : mp[u]){
        if(v == f[u] || v == wc[u]) continue;
        dfs2(v, v);
    }
}

ll w[maxn * 4];

void pushup(int u){
    w[u] = min(w[u << 1], w[u << 1 | 1]); // w[u] << 1 | 1 是严重逻辑错误
}

void build(int u, int L, int R){
    if(L == R){
        w[u] = inf;
        return; // 递归终止条件
    }
    int mid = (L + R) >> 1;
    build(u << 1, L, mid);
    build(u << 1 | 1, mid + 1, R);
    pushup(u);
}

bool inrange(int L, int R, int l, int r){
    return (l <= L) && (R <= r);
}

bool outofrange(int L, int R, int l, int r){
    return (r < L) || (R < l);
}

ll query(int u, int L, int R, int l, int r){
    if(inrange(L, R, l, r)) return w[u];
    else if(!outofrange(L, R, l, r)){
        int mid = (L + R) >> 1;
        return min(query(u << 1, L, mid, l, r), query(u << 1 | 1, mid + 1, R, l, r));  
    }
    else return inf;
}

void ddxg(int u, int L, int R, int p, ll x){
    if(L == R) w[u] = x;
    else {
        int mid = (L + R) >> 1;
        if(p <= mid) ddxg(u << 1, L, mid, p, x);
        else ddxg(u << 1 | 1, mid + 1, R, p, x);
        pushup(u);
    }
}

int n, q;

int qry(int x, int y){
    ll ans = inf;
    while(top[x] != top[y]){
        if(dth[top[x]] < dth[top[y]]) swap(x, y);
        ans = min(ans, query(1, 1, n, dfn[top[x]], dfn[x]));
        x = f[top[x]]; // 别忘了跳链
    }
    return min(ans, query(1, 1, n, min(dfn[x], dfn[y]), max(dfn[x], dfn[y])));
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    //cout << "tets" << endl;
    while(q--){
        int op, p;
        cin >> op >> p;
        if(!op){
            cur[p] ^= 1;
            if(cur[p]) ddxg(1, 1, n, dfn[p], dfn[p]);
            else ddxg(1, 1, n, dfn[p], inf);
        }
        else {
            int ans = qry(1, p); 
            if(ans == inf) cout << -1 << endl;
            else cout << rdfn[ans] << endl;
            //cout << "etst" << endl;
        }
    }


    return 0;
}