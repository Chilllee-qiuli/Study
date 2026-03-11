#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
const int maxm = 4e6 + 10;
const int mod = 100003;
int n, m, s;
int head[maxn], to[maxm], nxt[maxm], tot;

void adde(int u, int v){
    nxt[++tot] = head[u];
    head[u] = tot;
    to[tot] = v;
}

struct node{
    int u;
    ll dis;
    friend bool operator < (node x, node y){
        return x.dis > y.dis;
    }
};

priority_queue<node> qu;
int dis[maxn], vis[maxn];
ll dp[maxn];

void dijk(){
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0; dp[1] = 1;
    qu.push({1, 0});
    while(!qu.empty()){
        node tp = qu.top(); qu.pop();
        if(vis[tp.u]) continue;
        vis[tp.u] = 1;
        int u = tp.u;
        for(int i = head[u]; i; i = nxt[i]){
            int v = to[i];
            if((ll)dis[u] + 1 < dis[v]){
                dis[v] = 1 + dis[u];
                dp[v] = dp[u];
                qu.push({v, dis[v]});
            }
            else if((ll)dis[u] + 1 == dis[v]){
                dp[v] += dp[u];
                dp[v] %= mod;
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adde(u, v);
        adde(v, u);
    }

    dijk();

    for(int i = 1; i <= n; i++)
    cout << dp[i] % mod << endl;
    

	return 0;
}
