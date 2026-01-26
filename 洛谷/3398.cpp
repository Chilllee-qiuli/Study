#include<bits/stdc++.h>
using namespace std;
typedef long long ll; // 判断树上两条路径是否相交
const int maxn = 2e5 + 10;
int n, q;
int dth[maxn], anc[maxn][20], dis[maxn];

vector<int> g[maxn];

void dfs(int u, int fa){
    for(auto v : g[u]){
        if(v == fa) continue;
        dth[v] = dth[u] + 1;
        anc[v][0] = u;
        dfs(v, u);
    }
}

void init(){
    for(int j = 1; j <= 18; j++)
        for(int i = 1; i <= n; i++)
        anc[i][j] = anc[anc[i][j - 1]][j - 1];
}

int LCA(int u, int v){
    if(dth[u] < dth[v]) swap(u, v);
    for(int i = 18; i >= 0; i--)
        if(dth[anc[u][i]] >= dth[v]) u = anc[u][i];
    if(u == v) return u;
    for(int i = 18; i >= 0; i--)
        if(anc[u][i] != anc[v][i])
        u = anc[u][i], v = anc[v][i];
    
    return anc[u][0];
}

bool judge(int x, int s, int t){
    return (dth[x] >= dth[LCA(s, t)]) && (LCA(s, x) == x || LCA(t, x) == x);
}

bool work(){
    int aa, bb, cc ,dd;
    cin >> aa >> bb >> cc >> dd;
    int lca1 = LCA(aa, bb);
    int lca2 = LCA(cc, dd);
    return judge(lca1, cc, dd) || judge(lca2, aa, bb);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dth[1] = 1;
    dfs(1, 0);
    init();

    while(q--){
        if(work()) cout << "Y" << endl;
        else cout << "N" << endl;
    }


    return 0;
}