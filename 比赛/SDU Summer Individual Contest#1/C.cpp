#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e5 + 19;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, m, root;
int head[maxn], to[maxn], nxt[maxn], tot;
ll dis[maxn], a[maxn], wi[maxn];
int fa[maxn];

void adde(int u, int v, int w){
    nxt[++tot] = head[u];
    to[head[u] = tot] = v;
    wi[tot] = w;
}


void dfs(int u, ll d, ll money, int f){
    dis
    fa[u] = f;
    for(int i = head[u]; i; i = nxt[i]){
        if()
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adde(u, v, w);
        adde(v, u, w);
    }
    ll minn = inf;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] < minn){
            minn = a[i];
            root = i;
        }
    }

    dfs(root, 0, a[root], 0);


	return 0;
}
