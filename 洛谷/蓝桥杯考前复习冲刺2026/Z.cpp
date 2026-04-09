#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int A, B;
int n;
vector<int> g[maxn];
int dis[maxn];

void dfs(int u, int fa){
    dis[u] = dis[fa] + 1;
    for(auto v : g[u]){
        if(v == fa) continue;
        dfs(v, u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);
    for(int i = 1; i <= n; i++)
    if(dis[i] > dis[A]) A = i;

    memset(dis, 0, sizeof(dis));
    dfs(A, 0);
    for(int i = 1; i <= n; i++)
    if(dis[i] > dis[B]) B = i;

    cout << dis[B] - 1 << "\n";
    

    return 0;
}