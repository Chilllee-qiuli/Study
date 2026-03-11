#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int maxm = 4e5 + 10;
int n, m, s;
int head[maxn], to[maxm], val[maxm], nxt[maxm], tot;

void adde(int u, int v, int w){
    nxt[++tot] = head[u];
    head[u] = tot;
    to[tot] = v;
    val[tot] = w;
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

void dijk(){
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    qu.push({s, 0});
    while(!qu.empty()){
        node tp = qu.top(); qu.pop();
        if(vis[tp.u]) continue;
        vis[tp.u] = 1;
        int u = tp.u;
        for(int i = head[u]; i; i = nxt[i]){
            int v = to[i];
            if((ll)dis[u] + val[i] < dis[v]){
                dis[v] = val[i] + dis[u];
                qu.push({v, dis[v]});
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> s;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adde(u, v, w);
        //adde(v, u, w);
    }

    dijk();

    for(int i = 1; i <= n; i++)
    cout << dis[i] << " ";
    

	return 0;
}
