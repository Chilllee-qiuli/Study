#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5050;
const int maxm = 4e5 + 10;
int head[maxn], val[maxm], nxt[maxm], to[maxm], tot;
int n, m;
int vis[maxn];
ll ans = 0;
int cnt = 0 ;

void adde(int u, int v, int w){
    nxt[++tot] = head[u];
    head[u] = tot;
    to[tot] = v;
    val[tot] = w;
}
struct node{
    int d;
    int u;
    friend bool operator < (node x, node y){
        return x.d > y.d;
    }
};
priority_queue<node> qu;

void prim(){    
    qu.push({0, 1});
    while(!qu.empty()){
        int u = qu.top().u;
        int d = qu.top().d;
        qu.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        cnt++;
        ans += d;
        for(int i = head[u]; i; i = nxt[i]){
            int v = to[i];
            if(vis[v]) continue;
            qu.push({val[i], v});
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
        adde(x, y, z);
        adde(y, x, z);
    }

    prim();

    if(cnt == n) cout << ans << "\n";
    else cout << "orz\n";


    return 0;
}