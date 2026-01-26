#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int n, m, root;
ll v;
ll vis[maxn];
int head[maxn], nxt[maxn], to[maxn], tot;
ll val[maxn];

void adde(int u, int v, ll w){
    nxt[++tot] = head[u]; to[head[u] = tot] = v;
    val[tot] = w;
}

struct ndis{
    ll w, bag;
}dis[maxn];

ndis add(ndis x, ll w){
    ndis y = x;
    if(w < v - y.w ){
        y.w += w;
        return y;
    }
    else if(w == v - y.w){
        y.bag++;
        y.w = 0;
        return y;
    }
    else {
        y.bag ++;
        y.w = w;
        return y;

    }
}


struct node{
    ll v, w;
    ndis dis;
}tmp;

bool operator < (node x, node y){
    if(x.dis.bag != y.dis.bag) return x.dis.bag > y.dis.bag;
    else return x.dis.w > y.dis.w;
}
bool operator < (ndis x, ndis y){
    if(x.bag != y.bag) return x.bag < y.bag;
    else return x.w < y.w;
}

priority_queue<node> q;
void dijk(){
    for(int i = 0; i <= n; i++){
        dis[i].bag = inf;
    }
    dis[root].bag = 0;
    tmp.v = root;
    tmp.dis = {0, 0};
    q.push(tmp);
    while(!q.empty()){
        int u = q.top().v;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u]; i; i = nxt[i]){
            ndis tmpd = add(dis[u], val[i]);
            if(!(dis[to[i]] < tmpd) && (dis[to[i]].bag != tmpd.bag || dis[to[i]].w != tmpd.w)){
                dis[to[i]] = tmpd;
                tmp.dis = tmpd;
                tmp.v = to[i];
                q.push(tmp);
            }
        }
    }
}


int main(){
    freopen("i.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> v >> root;
    for(int i = 1; i <= m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        adde(x, y, w);
        adde(y, x, w);
    }

    dijk();

    for(int i = 1; i <= n; i++){
        if(dis[i].bag == inf) cout << -1 << " "; 
        else if(dis[i].bag == 0) cout << 1 << " ";
        else cout << dis[i].bag + (dis[i].w != 0) << " ";
        //else cout << dis[i].bag << "  " << dis[i].w << " ";
    }

    

    return 0;
}