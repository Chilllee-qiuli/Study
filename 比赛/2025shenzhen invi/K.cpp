#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<int, int>
#define mk make_pair
const int maxn = 4e5 + 10;
int n;

ll nxt[maxn], to[maxn], head[maxn], val[maxn],  tot;

void adde(int u, int v, ll x){
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
    val[tot] = x;
}
pr jiao(pr x, pr y){
    if(x.second < y.first || y.second < x.first) return mk(-1, -1);
    return mk(max(x.first, y.first), min(x.second, y.second));
}

int flag = 1;
pr f[maxn];
void dfs(int u, int fa){
    f[u] =  mk(1, 1e9 + 1);
    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i], w = val[i];
        if(v == fa) continue;
        dfs(v, u);

        if(f[v].first == -1) f[u] = mk(-1, -1);
        else if(w <= f[v].first)f[u] = mk(-1, -1);
        else if(w > f[v].second) f[u] = jiao(f[u], mk(w - f[v].second, w - f[v].first));
        else f[u] = jiao(f[u], mk(1, w - f[v].first));
    }

}
int a[maxn];
void dfs2(int u, int fa, int wet){
    // if(!nxt[head[u]]){ // leaf
    //     a[u] = 
    // }

    // if(u != 1)
    a[u] = wet - a[fa];

    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i], w = val[i];
        if(v == fa) continue;
        dfs2(v, u, w);
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        int u, v, x;
        cin >> u >> v >> x;
        adde(u, v, x);
        adde(v, u, x);
    }

     dfs(1, 0);

    if(f[1].first == -1) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES\n";

    dfs2(1, 0, f[1].first);

    for(int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];



    return 0;



}