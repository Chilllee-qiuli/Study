#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = 2e6 + 10;
const int maxn = 1e6 + 20;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int head[maxn], nxt[maxm], to[maxm], mcnt;
int val[maxm];
int lmp[maxn];

void add(int u, int v, int va){
    ++mcnt;
    nxt[mcnt] = head[u];
    head[u] = mcnt;
    to[mcnt] = v;
    val[mcnt] = va;
}

ll dist[4][maxn];
int n, m, k;
struct node{
    int now;
    ll dis;
    ll g;
    node (int noww, ll diss, ll h, int u, int v){
        now = noww;
        g = diss;
        if(h == -1) {
            dis = diss;
            return ;
        }
        for(int i = 0; i < 4; i++){
            ll du = dist[i][u], dt = dist[i][v];
            if (du >= inf/2 || dt >= inf/2) continue;
            h = max(h, llabs(dt - du));
        }
        dis = diss + h;
    }
    friend bool operator < (const node x, const node y){
        return x.dis > y.dis;
    }
};
priority_queue<node>qu;
int nowst = 0;


void dijk(int st){

    priority_queue<node>().swap(qu);
    for(int i = 0; i <= n; i++) dist[nowst][i] = inf;
    dist[nowst][st] = 0;
    qu.push({st, 0, -1, 0, 0});

    while(!qu.empty()){
        node tp = qu.top();
        qu.pop();
        int u = tp.now;
        if (tp.dis != dist[nowst][u]) continue;
        for(int i = head[u]; i; i = nxt[i]){
            int v = to[i];
            if(dist[nowst][v] > dist[nowst][u] + val[i]){
                dist[nowst][v] = dist[nowst][u] + val[i];
                qu.push({v, dist[nowst][v], -1, 0, 0});
            }
        }
    }
}

int vis[maxn];
ll dis[maxn];

ll bfs_A(int uu, int vv){
    priority_queue<node>().swap(qu);
    qu.push({uu, 0, 0, uu, vv});
    dis[uu] = 0;
    while(!qu.empty()){
        node tp = qu.top();
        qu.pop();
        int u = tp.now;
        if (tp.g != dis[u]) continue;
        if(u == vv) return dis[u];
        for(int i = head[u]; i; i = nxt[i]){
            //if(vis[to[i]]) continue;
            //vis[to[i]] = 1;
            if(dis[to[i]] > dis[u] + val[i]){
                dis[to[i]] = dis[u] + val[i];
                qu.push({to[i], dis[to[i]], 0, to[i], vv});
            }
        }
    }
    return -1;
}


int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }

    for(int i = 0, st = 1; i < 4; i++, nowst++){
        dijk(st);
        lmp[st] = 1;
        int nxt = 1;
        for(int j = 1; j <= n; j++)
            if(dist[nowst][j] > dist[nowst][nxt] && !lmp[j])
            nxt = j;
        st = nxt;
    }

    while(k--){
        int u, v;
        cin >> u >> v;
        //memset(vis, 0, sizeof(vis));
        memset(dis, 0x3f, sizeof(dis));
        cout << bfs_A(u, v) << endl;
    }


    return 0;
}