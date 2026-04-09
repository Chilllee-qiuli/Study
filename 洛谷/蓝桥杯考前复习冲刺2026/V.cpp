#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;

int dis[maxn][maxn];
int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    }
    for(int i = 1; i <= n; i++) dis[i][i] = 0;

    for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    cout << dis[i][j] << " \n"[j == n];


    

    return 0;
}