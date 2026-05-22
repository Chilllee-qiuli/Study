#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1010;

int n, m;
ll l, r;
int g[N][N];
int D[N][N][2];   // D[i][j][p]: (1,1) → (i,j) 步数奇偶为 p 的最短距离

int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

inline ll ceil_div(ll a, ll b) { return (a + b - 1) / b; }

void solve(){
    cin >> n >> m >> l >> r;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        for(int j = 1; j <= m; j++){
            g[i][j] = s[j-1] - '0';
            D[i][j][0] = D[i][j][1] = -1;
        }
    }

    // 拆点 BFS：状态 (i, j, parity)
    queue<tuple<int,int,int>> q;
    D[1][1][0] = 0;
    q.push({1, 1, 0});
    while(!q.empty()){
        auto [x, y, p] = q.front(); q.pop();
        int np = p ^ 1;
        for(int k = 0; k < 8; k++){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(!g[nx][ny]) continue;
            if(D[nx][ny][np] != -1) continue;
            D[nx][ny][np] = D[x][y][p] + 1;
            q.push({nx, ny, np});
        }
    }

    int D0 = D[n][m][0];   // 偶数步最短路
    int D1 = D[n][m][1];   // 奇数步最短路

    if(D0 == -1 && D1 == -1){
        cout << -1 << "\n";
        return;
    }

    ll ans = LLONG_MAX;

    if(l != r){
        // 情况 1：l ≠ r，直接用最短路
        ll dis;
        if(D0 == -1)      dis = D1;
        else if(D1 == -1) dis = D0;
        else              dis = min(D0, D1);
        ans = ceil_div(dis, r);
    } else {
        // l == r：每分钟必须正好走 r 步，总步数 = t·r
        if(r % 2 == 0){
            // 情况 2：r 偶 → t·r 必为偶 → 只能用偶路径
            if(D0 != -1) ans = ceil_div((ll)D0, r);
        } else {
            // 情况 3：r 奇 → t·r 奇偶 = t 奇偶
            if(D0 != -1){
                ll t = ceil_div((ll)D0, r);
                if(t & 1) t++;          // 偶路径要 t 偶
                ans = min(ans, t);
            }
            if(D1 != -1){
                ll t = ceil_div((ll)D1, r);
                if(!(t & 1)) t++;       // 奇路径要 t 奇
                ans = min(ans, t);
            }
        }
    }

    if(ans == LLONG_MAX) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
