#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int maxm = 2e5 + 10;
int fa[maxn], siz[maxn], dep[maxn], wson[maxn], a[maxn];

vector< int > mp[maxn];

void dfs1(int u, int f){
    fa[u] = f;
    siz[u] = 1;
    dep[u] = dep[f] + 1;
    for(auto v : mp[u]){
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
ll w[maxn * 4];
void pushup(int u) {w[u] = w[u << 1] + w[u << 1 | 1];}

void build(int u, int L, int R){
    if(L == R) {
        w[u] = a[rdfn[L]]; // 到达叶节点，该区间的点权是DFS序上第L个结点的权值， 即a[rdfn[L]]  !!!
        return ;
    }
    int M = (L + R) >> 1;
    build(u << 1, L, M); build(u << 1 | 1, M + 1, R);
    pushup(u);
}

bool InRange(int L, int R, int l, int r) {r}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

	return 0;
}
