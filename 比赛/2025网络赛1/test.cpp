#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int root;
typedef long long ll;
int n, m, v;

int c[maxn];
int vis[maxn];
int head[maxn], nxt[maxn], to[maxn], tot;
ll val[maxn];
ll dis[maxn];

struct node{
    int v, w;
}tmp;

void adde(int u, int v, ll w){
    nxt[++tot] = head[u]; to[head[u] = tot] = v;
    val[tot] = w;
}

bool operator < (node x, node y){
    return x.w > y.w;
}


priority_queue<node> q;
void dijk(){
    for(int i = 0; i <= n; i++){
        dis[i]= inf;
    }
    dis[root]= 0;
    tmp.v = root;
    tmp.w = 0;
    q.push(tmp);
    while(!q.empty()){
        int u = q.top().v;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u]; i; i = nxt[i]){
            //ndis tmpd = add(dis[u], val[i]);
            if(dis[to[i]] > (ll) dis[u] + val[i]){
                dis[to[i]] = dis[u] + val[i];
                tmp.w = dis[to[i]];
                tmp.v = to[i];
                q.push(tmp);
            }
        }
    }
}


int main(){
    freopen("t.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    //cin >> n >> m >> v >> root;
    cin >> n >> m >> root;
    for(int i = 1; i <= m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        adde(x, y, w);
        adde(y, x, w);
    }

    dijk();

    for(int i = 1; i <= n; i++){
        cout << dis[i] << " ";
    }
    

    return 0;
}