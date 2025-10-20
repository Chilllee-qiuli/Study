#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n, m;
char mp[110][110];
int stx, sty, edx, edy;
struct node{
    int x, y;
};
queue<node> q;
bool vis[110][110];
int step[110][110];
int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
void bfs(int x, int y){
    memset(vis, 0, sizeof(vis));
    while(!q.empty()) q.pop();
    q.push({x, y});
    vis[x][y] = 1;
    step[x][y] = 0;
    while(!q.empty()){
        node now = q.front(); q.pop();
        if(now.x == edx && now.y == edy){
            cout << step[edx][edy] << endl;
            return;
        }
        for(int i = 0; i < 4; i++){
            int tx = now.x + dir[i][0];
            int ty = now.y + dir[i][1];
            if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
            if(mp[tx][ty] == '#') continue;
            if(vis[tx][ty]) continue;
            vis[tx][ty] = 1;
            step[tx][ty] = step[now.x][now.y] + 1;
            q.push({tx, ty});
        }
    }
    cout << -1 << endl;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) 
        {
            cin >> mp[i][j];
            if(mp[i][j] == 'S'){
                stx = i, sty = j;
            }
            else if(mp[i][j] == 'T'){
                edx = i, edy = j;
            }
        }
        bfs(stx, sty);
    

	return 0;
}
