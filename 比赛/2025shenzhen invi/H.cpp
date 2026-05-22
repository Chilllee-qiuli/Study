#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<int, int>
#define mk make_pair
const int N = 1010;
int n, m;
int l, r;
string a[N];
int dis[N][N][2];
bool vis[N][N];
int dt[2][8]={{-1,-1, 0, 1, 1, 1, 0,-1 },
              { 0, 1, 1, 1, 0,-1,-1,-1 }};
queue<pr >q;
void solve()
{
    cin >> n >> m;
    cin >> l >> r;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dis[i][j][0]=dis[i][j][1]=1e9;
        }
    }
    dis[0][0][0]=0;
    dis[0][0][1]=1;
    vis[0][0]=1;
    q.push(pr(0,0));
    while(!q.empty()){
        pr now=q.front();q.pop();
        int nowx=now.first,nowy=now.second;
        for(int i=0;i<8;i++){
            int tx=nowx+dt[0][i],ty=nowy+dt[1][i];
            if(tx<0||ty<0||tx>=n||ty>=m||a[tx][ty]=='0')continue;
            dis[tx][ty][0]=min(dis[tx][ty][0],dis[nowx][nowy][1]+1);
            dis[tx][ty][1]=min(dis[tx][ty][1],dis[nowx][nowy][0]+1);
            if(vis[])
        }

    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}