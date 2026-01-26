#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
int t;
int n, m;
char mp[maxn][maxn];
int vis[maxn][maxn];
int flag = 0;
int pianyi[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int x, int y){
    vis[x][y] = 1;
    if(mp[x][y] == 'T') flag = 1;
    if(flag) return ;
    for(int i = 0; i <= 3; i++){
        int nowx = x + pianyi[i][0]; 
        int nowy = y + pianyi[i][1];
        if(mp[nowx][nowy] == '#' || nowx > n || nowx < 1 || nowy > m || nowy < 1 || vis[nowx][nowy]) continue;
        // vis[nowx][nowy] = 1;
        dfs(nowx, nowy);
        // vis[nowx][nowy] = 0;
    }
}


int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> m;
        memset(vis, 0, sizeof(vis));
        flag = 0;
        for(int i = 1; i <= n; i++) cin >> (mp[i] + 1);
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(mp[i][j] == 'S') dfs(i, j);
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

	return 0;
}