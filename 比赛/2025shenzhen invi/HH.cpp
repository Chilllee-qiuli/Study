#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<int, int>
#define mk make_pair
const int N = 2010;
const int inf = 0x3f3f3f3f;
int g[N][N];
int n, m;
int l, r;
int vis[N][N];
int dis[N][N];
int ou[N][N], ji[N][N];
int dt[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

void solve(){
    cin >> n >> m;
    cin >> l >> r;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++) {
        vis[i][j] = 0;
        dis[i][j] = inf;   
        ou[i][j] = inf;
        ji[i][j] = inf;
    }

    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) g[i][j + 1] = (s[j] - '0');
        g[i][m + 1] = 0;
    }
    for(int j = 0; j <= m + 1; j++) g[n + 1][j] = 0;


    queue<pr> qu;
    qu.push(mk(1, 1));
    dis[1][1] = 0;
    while(!qu.empty()){
        int u = qu.front().first;
        int v = qu.front().second;

        qu.pop();
        if(vis[u][v]) continue;
        vis[u][v]++;
        for(int i = 0; i < 8; i++){
            int x = u + dt[i][0], y = v + dt[i][1];

            if(x >= 1 && y >= 1 && x <= n && y <= m && vis[x][y] <= 3 && g[x][y]){
                dis[x][y] = min(dis[x][y], dis[u][v] + 1);
                int tmp = dis[u][v] + 1;
                if(tmp & 1) ji[x][y] = min(ji[x][y], tmp);
                else ou[x][y] = min(ou[x][y], tmp);
                if(ou[u][v] != inf) ji[x][y] = min(ji[x][y], ou[u][v] + 1);
                if(ji[u][v] != inf) ou[x][y] = min(ou[x][y], ji[u][v] + 1);

                qu.push(mk(x, y));
            }
        }        
    }

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        if(!g[i][j]) continue;
        if(dis[i][j] % 2 == 0) ou[i][j] = dis[i][j];
        else ji[i][j] = dis[i][j];
        for(int k = 0; k < 8; k++){
            int x = i + dt[k][0], y = j + dt[k][1];
            // if(i == 5){
            //     cout << i << " " << j << " ";
            //     cout << x << " " << y << endl;
            // }
            if(x >= 1 && y >= 1 && x <= n && y <= m && g[x][y]){
                if(dis[x][y] & 1) ou[i][j] = min(ou[i][j], dis[x][y] + 1);
                else ji[i][j] = min(ji[i][j], dis[x][y] + 1);
                if(ou[x][y] != inf) ji[i][j] = min(ji[i][j], ou[x][y] + 1);
                if(ji[x][y] != inf) ou[i][j] = min(ou[i][j], ji[x][y] + 1);
            }
        }
    }
    // for(int i = 1; i <= n; i++)
    // for(int j = 1; j <= m; j++)
    // cout << (dis[i][j] == inf? 0 : dis[i][j]) << " \n"[j == m];
    // cout << endl;
    // for(int i = 1; i <= n; i++)
    // for(int j = 1; j <= m; j++)
    // cout << (ou[i][j] == inf ? 0 : ou[i][j]) << " \n"[j == m];
    // cout << endl;
    // for(int i = 1; i <= n; i++)
    // for(int j = 1; j <= m; j++)
    // cout << (ji[i][j] == inf  ?  0 : ji[i][j]) << " \n"[j == m];

    // cout << endl;
    
    int ans = inf;
    
    if (l == r) {
        // l == r 时每分钟恰好走 l 步，需要考虑奇偶性
        int step = l;
        if (ou[n][m] != inf) {
            int t = (ou[n][m] + step - 1) / step;
            // 若 step 为奇数且 t 为奇数，则 t*step 为奇，不满足"偶数步"要求
            if (step % 2 == 1 && t % 2 == 1) t++;
            ans = min(ans, t);
        }
        if (ji[n][m] != inf && step % 2 == 1) {  // step 为偶时 t*step 永远为偶，无法奇数步
            int t = (ji[n][m] + step - 1) / step;
            if (t % 2 == 0) t++;  // 需要 t*step 为奇，故 t 须为奇
            ans = min(ans, t);
        }
    } else {
        // l < r：区间必含奇偶，无需分类讨论 r 奇偶
        if (ou[n][m] != inf) ans = min(ans, (ou[n][m] + r - 1) / r);
        if (ji[n][m] != inf) ans = min(ans, (ji[n][m] + r - 1) / r);
    }
    
    if (ans == inf) cout << -1 << "\n";
    else cout << ans << "\n";
    
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