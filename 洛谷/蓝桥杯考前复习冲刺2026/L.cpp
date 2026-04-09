#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<int, int>
#define mk make_pair
const int maxn = 300;

char mp[maxn][maxn];
int n;
int vis[maxn][maxn];
int pian[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool bfs1(pr st){
    memset(vis, 0, sizeof(vis));
    queue<pr> qu;
    qu.push(st);
    while(!qu.empty()){
        int u = qu.front().first;
        int v = qu.front().second;
        qu.pop();
        if(vis[u][v]) continue;
        vis[u][v] = 1;
        for(int i = 0; i < 4; i++){
            int x = u + pian[i][0];
            int y = v + pian[i][1];
            if(vis[x][y] || mp[x][y] == '1') continue;
            if(x >= n || y >= n || x <= 1 || y <= 1) return 0;
            qu.push(mk(x, y));
        }
    }
    return 1;
}

pr find(){
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    if(mp[i][j] == '0' && bfs1(mk(i, j))) return mk(i, j);

    return mk(0, 0);
}

void bfs2(pr st){
    memset(vis, 0, sizeof(vis));
    queue<pr> qu;
    qu.push(st);
    while(!qu.empty()){
        int u = qu.front().first;
        int v = qu.front().second;
        qu.pop();
        if(vis[u][v]) continue;
        vis[u][v] = 1;
        mp[u][v] = '2';
        for(int i = 0; i < 4; i++){
            int x = u + pian[i][0];
            int y = v + pian[i][1];
            if(vis[x][y] || mp[x][y] == '1') continue;
            if(x > n || y > n || x < 1 || y < 1) continue;
            qu.push(mk(x, y));
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    cin >> mp[i][j];
    
    pr st = find();

    bfs2(st);

    for(int i = 1; i <= n; i++, cout << "\n")
    for(int j = 1; j <= n; j++)
    cout << mp[i][j] << " ";
    

    return 0;
}