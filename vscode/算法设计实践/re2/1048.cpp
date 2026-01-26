#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 150;
int n, m;
int t;
char mp[maxn][maxn];
int stx, sty;
int vis[maxn][maxn];
int yidong[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int flag = 0;

void dfs(int x, int y){
    if(mp[x][y] == 'T' || flag){
        flag = 1;
        return ;
    }
    for(int i = 0; i <= 3; i++){
        int nowx = x + yidong[i][0];
        int nowy = y + yidong[i][1];
        if(nowx < 1 || nowx > n || nowy < 1 || nowy > m || vis[nowx][nowy] || mp[nowx][nowy] == '#') continue;
        vis[nowx][nowy] = 1;
        dfs(nowx, nowy);
    }
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        memset(vis, 0, sizeof(vis));
        flag = 0;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++)
          cin >> mp[i][j];

        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
           if(mp[i][j] == 'S') dfs(i, j);
        
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;

    }


	return 0;
}