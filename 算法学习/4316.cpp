#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int head[maxn], nxt[maxn], val[maxn], to[maxn], tot;
int n, m;
int out[maxn], deg[maxn];
double f[maxn];

void adde(int u, int v, int w){
    nxt[++tot] = head[u];
    to[tot] = v;
    head[u] = tot;
    val[tot] = w;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adde(v, u, w); // 反向建图
        ++out[u];
        ++deg[u];
    }

    queue<int> qu;
    qu.push(n);
    while(!qu.empty()){
        int u = qu.front(); qu.pop();
        for(int i = head[u]; i; i = nxt[i]){
            int v = to[i];
            f[v] += (f[u] + val[i]) / out[v];
            if(--deg[v] == 0) qu.push(v);
        } 
    }

    printf("%.2lf\n", f[1]);
    





	return 0;
}
