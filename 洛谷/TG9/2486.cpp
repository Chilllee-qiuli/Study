#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
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
struct Node {
    int lcol, rcol;
    ll seg;
    int lzy;
    Node(ll seg = 0, int lzy = 0) : seg(seg), lzy(lzy) {}
} t[maxn * 4];

void pushup(int u) {
    t[u].lcol = t[u << 1].lcol;
    t[u].rcol = t[u << 1 | 1].rcol;
    t[u].seg = t[u << 1].seg + t[u << 1 | 1].seg - (t[u << 1].rcol == t[u << 1 | 1].lcol);
}


void build(int u, int L, int R){
    t[u].lzy = 0;
    if (L == R) {
        t[u].lcol = t[u].rcol = a[rdfn[L]];
        t[u].seg = 1;
        return;
    }
    int M = (L + R) >> 1;
    build(u << 1, L, M); build(u << 1 | 1, M + 1, R);
    pushup(u);
}

bool InRange(int L, int R, int l, int r) {return l <= L && R <= r;}
bool OutofRange(int L, int R, int l, int r) {return r < L || R < l;}

void maketag(int u, int L, int R, int c) {
    t[u].lcol = t[u].rcol = c;
    t[u].seg = 1;
    t[u].lzy = c;
}

void pushdown(int u, int L, int R) {
    if (!t[u].lzy) return;
    int M = (L + R) >> 1;
    maketag(u << 1, L, M, t[u].lzy);
    maketag(u << 1 | 1, M + 1, R, t[u].lzy);
    t[u].lzy = 0;
}

struct Res {
    int lcol, rcol;
    ll seg;
    Res(int l=0, int r=0, ll s=0): lcol(l), rcol(r), seg(s) {}
};

Res qjcx(int u, int L, int R, int l, int r) {
    if (l > R || r < L) return Res(-1, -1, 0);// 不相交，返回空段
    if (l <= L && R <= r) return Res(t[u].lcol, t[u].rcol, t[u].seg);
    pushdown(u, L, R);
    int M = (L + R) >> 1;
    Res left = qjcx(u << 1, L, M, l, r);
    Res right = qjcx(u << 1 | 1, M + 1, R, l, r);
    // 注意这里，显然不会存在一个段seg=1，所以这里seg=0是标记的空段，并不包含在目标区间内，所以要特判避免干扰我们的左右端点颜色
    if (left.seg == 0) return right;
    if (right.seg == 0) return left;
    ll seg = left.seg + right.seg - (left.rcol == right.lcol);
    return Res(left.lcol, right.rcol, seg);
}

void qjxg(int u, int L, int R, int l, int r, int c) {
    if (l > R || r < L) return;
    if (l <= L && R <= r) {
        maketag(u, L, R, c);
        return;
    }
    pushdown(u, L, R);
    int M = (L + R) >> 1;
    qjxg(u << 1, L, M, l, r, c);
    qjxg(u << 1 | 1, M + 1, R, l, r, c);
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

// 路径查询
Res qry(int x, int y) {
    vector<Res> lft, rht;
    while (top[x] != top[y]) {
        if (dep[top[x]] >= dep[top[y]]) {
            lft.push_back(qjcx(1, 1, n, dfn[top[x]], dfn[x]));
            x = fa[top[x]];
        } else {
            rht.push_back(qjcx(1, 1, n, dfn[top[y]], dfn[y]));
            y = fa[top[y]];
        }
    }
    int l = dfn[x], r = dfn[y];
    Res mid;
    if (l <= r) {
        mid = qjcx(1, 1, n, l, r);
        // mid.lcol 连接 x，mid.rcol 连接 y
    } else {
        mid = qjcx(1, 1, n, r, l);
        swap(mid.lcol, mid.rcol); // 交换后，mid.lcol 是 x，mid.rcol 是 y
    }

    // 合并顺序：rht（逆序）+ mid + lft（正序）
    Res res = mid;
    for (int i = rht.size() - 1; i >= 0; --i) {
        res.seg += rht[i].seg - (rht[i].lcol == res.rcol);
        res.rcol = rht[i].rcol;
    }
    for (int i = 0; i < lft.size(); ++i) {
        if(i != lft.size() - 1) res.seg += lft[i].seg - (lft[i + 1].rcol == lft[i].lcol);
        else res.seg += lft[i].seg - (lft[i].lcol == res.lcol);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    r = 1;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    dfs1(r, 0);
    dfs2(r, 0);
    build(1, 1, n);
    for(int x, y, z; m; --m){
        char ch;
        cin >> ch;
        if(ch == 'C'){
            cin >> x >> y >> z;
            upd(x, y, z); // 表示将树从 x 到 y 结点最短路径上所有节点的值都染色为 z
        }
        else if(ch == 'Q'){
            cin >> x >> y;
            cout << qry(x, y).seg << "\n"; // 表示求树从 x 到 y 结点最短路径上颜色段数量
        }
       

    }

	return 0;
}
