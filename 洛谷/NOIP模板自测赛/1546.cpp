#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5050;
const int maxm = 4e5 + 10;
int head[maxn], nxt[maxm], val[maxm], to[maxm], tot;
int n, m;

void adde(int u, int v, int w){
    nxt[++tot] = head[u];
    to[tot] = v;
    head[u] = tot;
    val[tot] = w;
}

int vis[maxn], ans, dis_tmp[maxn];
struct node{
    int u;
    int dis;
    friend bool operator < (node x, node y){
        return x.dis > y.dis;
    }
};
priority_queue<node> qu;

void prim(){
    memset(dis_tmp, 0x3f, sizeof(dis_tmp)); // 减少入堆
    dis_tmp[1] = 0;
    qu.push({1, 0});
    while(!qu.empty()){
        node tp = qu.top();
        qu.pop();
        int u = tp.u;
        if(vis[u]) continue;
        vis[u] = 1;
        ans += tp.dis;
        for(int i = head[u]; i; i = nxt[i]){
            int v = to[i];
            if(val[i] < dis_tmp[v]){
                dis_tmp[v] = val[i];
                qu.push({v, val[i]});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++){
        int v;
        cin >> v;
        if(i == j) continue;
        adde(i, j, v);
    }

    prim();

    int flag = 1;
    for(int i = 1; i <= n; i++)
        if(!vis[i]) flag = 0;
    
    if(!flag) cout << "orz\n";
    else cout << ans << endl;




	return 0;
}
