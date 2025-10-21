#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pr;
#define mk make_pair
const int maxn = 1e5 + 10;
// 优化建图
int n, m, c;
int st, ed;
int dis[maxn];
int vis[maxn];

vector<pr> g[maxn];
void adde(int u, int v, int w){
    g[u].push_back(mk(v, w));
}
struct node{
    int u;
    int w;
    friend bool operator < (node x, node y){
        return x.w > y.w;
    }
};

priority_queue<node> qu;
void dijk(){
    dis[st] = 0;
    node tmp = {st, 0}; // 一定要注意定义的顺序
    qu.push(tmp);

    while(!qu.empty()){
        int u = qu.top().u;
        qu.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto it : g[u]){
            int v = it.first, w = it.second;
            if(dis[v] > (long long) dis[u] + w){
                dis[v] = dis[u] + w;
                tmp = {v, dis[v]};
                qu.push(tmp);
            }
        } 

        for(int j = 1; j <= n * 2; j <<= 1) // !!!
            if((u ^ j) <= n && (ll) dis[u] + j * c < dis[u ^ j]){ // !!! 一定要注意写法，是判断终点在不在n的范围内
                dis[u ^ j] = dis[u] + j * c;
                qu.push({u ^ j, dis[u ^ j]});
            }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> m >> c;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adde(u, v, w);
    }
    cin >> st >> ed;
    memset(dis, 0x3f, sizeof(dis));
    dijk();

    cout << dis[ed] << endl;
    


	return 0;
}