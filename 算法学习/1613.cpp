#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 55;
int g[maxn][maxn];
bool f[33][maxn][maxn];
int dis[maxn][maxn];
int n, m;


void dp(){
    for(int u = 1; u <= n; u++)
    for(int v = 1; v <= n; v++)
    if(g[u][v]) f[0][u][v] = 1;

    for(int i = 0; i <= 30; i++) // 对于2^i 次长度的两点关系，维护传递性
    for(int k = 1; k <= n; k++)
    for(int u = 1; u <= n; u++)
    for(int v = 1; v <= n; v++){
        f[i][u][v] |= (f[i - 1][u][k] & f[i - 1][k][v]);
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
    }
    dp();

    memset(dis, 0x3f, sizeof(dis));
    for(int i = 1; i <= n; i++) dis[i][i] = 0;

    for(int i = 0; i <= 30; i++) // 新建图，连接长度恰好为 2^k 的点
    for(int u = 1; u <= n; u++)
    for(int v = 1; v <= n; v++){
        if(f[i][u][v]) dis[u][v] = min(dis[u][v], 1);
    }
    for(int k = 1; k <= n; k++) // 跑一个floyd
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    cout << dis[1][n] << "\n";


	return 0;
}
