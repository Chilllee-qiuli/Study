#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int maxm = 2e5 + 10;
int n, c[maxn];
int sum;

int head[maxn], val[maxm], to[maxm], nxt[maxm], tot;
void adde(int u, int v, int w){
    to[++tot] = v;
    val[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
}
int siz[maxn];
ll dp[maxn];
void dfs1(int u, int fa){
    siz[u] = c[u];
    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i];
        if(v == fa) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        dp[u] += 1ll * val[i] * siz[v] + dp[v];
    }
}
ll ans = 0x3f3f3f3f3f3f3f3f;
void dfs2(int u, int fa, ll w){
    if(fa)
    dp[u] = dp[fa] + w * (sum - siz[u]) - w * siz[u];
    ans = min(ans, dp[u]);
    for(int i = head[u]; i; i = nxt[i]){
        int v = to[i];
        if(v == fa) continue;
        dfs2(v, u, val[i]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n ;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
        sum += c[i];
    }

    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adde(u, v, w);
        adde(v, u, w);
    }

    dfs1(1, 0);
    dfs2(1, 0, 0);

    cout << ans << endl;

	return 0;
}
