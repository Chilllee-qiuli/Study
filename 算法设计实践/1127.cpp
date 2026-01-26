#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1010;
int n, m;
ll dis[maxn][maxn];


int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    memset(dis, 0x3f, sizeof(dis));

    for(int i = 1; i <= m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        
        dis[u][v] = dis[v][u] = min(w, dis[u][v]);
    }

    for(int i = 1; i <= n; i++) dis[i][i] = 0;

    for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    if(dis[i][j] > (ll) dis[i][k] + dis[k][j]) dis[i][j] = dis[i][k] + dis[k][j];

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= i; j++)
    cout << (dis[i][j] == 0x3f3f3f3f3f3f3f3f ? -1 : dis[i][j]) << " \n"[j == i];

	return 0;
}