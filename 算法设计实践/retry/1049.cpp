#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
int n, m;
char mp[maxn][maxn];
int vis[maxn][maxn];
int pianyi[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
queue< pair<int, int > > qu;

int bfs(){
    int stx = 0, sty = 0;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        if(mp[i][j] == 'S') stx = i, sty = j;
    qu.push(make_pair(stx, sty));
    vis[stx][sty] = 1;

    while(!qu.empty()){
        int x = qu.front().first, y = qu.front().second;
        qu.pop();
        for(int i = 0; i <= 3; i++){
            int nowx = x + pianyi[i][0], nowy = y + pianyi[i][1];
            if(vis[nowx][nowy] || nowx < 1 || nowy < 1 || nowx > n || nowy > m || mp[nowx][nowy] == '#') continue;
            vis[nowx][nowy] = vis[x][y] + 1;
            if(mp[nowx][nowy] == 'T') return vis[nowx][nowy];
            qu.push(make_pair(nowx, nowy));
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> (mp[i] + 1);

    cout << bfs() - 1 << endl;

	return 0;
}