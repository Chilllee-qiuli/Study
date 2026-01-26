#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx = 0x3f3f3f3f;
const int maxn = 2e6 + 20;
int n, m;
int dis[maxn];
int vis[maxn];
int head[maxn], to[maxn], val[maxn], nxt[maxn], tot;
void add(int u, int v, int w){
    nxt[++tot] = head[u];
    to[tot] = v;
    head[u] = tot;
    val[tot] = w;
}

struct node {
    int u, w;
    bool operator < (const node& y) const {
        return w > y.w;
    }
};
priority_queue<node> pr;

ll ans = 0;
void prim(){
    pr.push({1, 0});
    memset(dis, 0x3f, sizeof(dis));
    while(!pr.empty()){
        node u = pr.top();
        pr.pop();
        if(vis[u.u]) continue;
        vis[u.u] = 1;
        ans += u.w;
        for(int i = head[u.u]; i; i = nxt[i]){
            if(val[i] < dis[to[i]]) {
                dis[to[i]] = val[i];
                pr.push({to[i], dis[to[i]]});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }

    prim();

    cout << ans << endl;

	return 0;
}