#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
const int maxm = 1e6 + 10;
int n, m;

vector<int> mp[maxn];
int val[maxn], fa[maxn], siz[maxn], son[maxn];
int dep[maxn], top[maxn];

void dfs1(int x, int f){
    fa[x] = f; siz[x] = 1; dep[x] = dep[f] + 1;
    for(auto to : mp[x]){
        if(to == f) continue;
        dfs1(to, x);
        siz[x] += siz[to];
        if(siz[to] > siz[son[x]]) son[x] = to;
    }
}

void dfs2(int x, int tp){
    top[x] = tp;
    if(!son[x]) return ;
    dfs2(son[x], tp);
    for(auto to : mp[x]){
        if(to == fa[x] || to == son[x]) continue;
        dfs2(to, to);
    }
}


int LCA(int x, int y){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    if(dep[x] < dep[y]) return x;
    return y;
}

int main(){
   // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n - 1; i++){
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    dfs1(1, -1);
    dfs2(1, 1);

    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        int lxy = LCA(x, y);
        int lxz = LCA(x, z);
        int lyz = LCA(y, z);
        //printf("test:  %d %d %d\n", lxy, lxz, lyz);
        int p = lxy;
        if (dep[lxz] > dep[p]) p = lxz;
        if (dep[lyz] > dep[p]) p = lyz;
        int c = dep[x] + dep[y] + dep[z] - dep[lxy] - dep[lxz] - dep[lyz];

        cout << p << " " << c << endl;

    }


	return 0;
}