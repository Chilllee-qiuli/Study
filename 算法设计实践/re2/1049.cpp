#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 150;
int n, m;
int t;
char mp[maxn][maxn];
int stx, sty;
int yidong[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int flag = 0;
int dis[maxn][maxn];
struct node{
    int x, y;
};
queue<node> vc;


void bfs(){
    while(!vc.empty()){
        node tp = vc.front();
        vc.pop();
        int x = tp.x , y = tp.y;
        for(int i = 0; i <= 3; i++){
            int nowx = x + yidong[i][0];
            int nowy = y + yidong[i][1];
            if(nowx < 1 || nowx > n || nowy < 1 || nowy > m || dis[nowx][nowy] || mp[nowx][nowy] == '#') continue;
            dis[nowx][nowy] = dis[x][y] + 1;
            if(mp[nowx][nowy] == 'T') flag = dis[nowx][nowy];
            vc.push({nowx, nowy});
        }
        if(flag) break;
        
    }
    
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    cin >> mp[i][j];

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    if(mp[i][j] == 'S') {
        dis[i][j] = 1;
        vc.push({i, j});
        bfs();
    }

    if(flag)  cout << flag - 1 << endl;
    else cout << -1 << endl;

	return 0;
}