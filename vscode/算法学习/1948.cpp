#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pr; // 0-1bfs, 优化建图
#define mk make_pair
const int maxn = 1e3 + 10;
int n, p, k;
int dis[maxn], vis[maxn];

vector<pr> g[maxn];
void adde(int u, int v, int w){
    g[u].push_back(mk(v, w));
}



bool check(int x){
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[1] = 0;

    deque<int> qu;
    qu.push_back(1);
    while(!qu.empty()){
        int u = qu[0];
        qu.pop_front();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto it : g[u]){
            int v = it.first, w = it.second;
            int e = w > x;
            if(dis[v] > (ll) dis[u] + e){
                dis[v] = dis[u] + e;
                if(!e) qu.push_front(v);
                else qu.push_back(v);
            }
        }
    }
    return dis[n] <= k;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> p >> k;

    for(int i = 1; i <= p; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adde(u, v, w);
        adde(v, u, w);
    }

    int l = 0, r = 1e9, ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << ans << endl;


	return 0;
}