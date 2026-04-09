#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<int, int> 
#define mk make_pair
const int maxn = 2e5 + 10;
const int maxm = 4e5 + 10;
int head[maxn], val[maxm], to[maxm], nxt[maxm], tot;
int n, m, s;

void adde(int u, int v, int w){
    nxt[++tot] = head[u];
    head[u] = tot;
    to[tot] = v;
    val[tot] = w;
}

ll dis[maxn], vis[maxn];
priority_queue<pr, vector<pr>, greater<pr>> qu;

void dijk(){
    qu.push({0, s}); // dis, u;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    while(!qu.empty()){
        int u = qu.top().second;
        qu.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u]; i; i = nxt[i]){
            int v = to[i];
            if(vis[v]) continue;
            if((ll) dis[u] + val[i] < dis[v]){
                dis[v] = dis[u] + val[i];
                qu.push({dis[v], v});
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
    cout << "\n";


    

    return 0;
}