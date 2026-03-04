#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 330;
const int inf = 0x3f3f3f3f;
int head[maxn], to[maxn], nxt[maxn];
int cnt = 0;
int dp[maxn][maxn];
int w[maxn];
int n, m;

void adde(int u, int v){
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}

void dfs(int u){
    for(int i = 1; i <= n; i++){
        dp[u][i] = -inf;
    }
    for(int v = head[u]; v; v = nxt[v]){
        dfs(v);
        static int g[maxn * 2]; // 使用滚动数组
        for(auto &gg : g) gg = -inf; 
        for(int j = 0; j <= m; j++)
        for(int k = 0; k <= m; k++){
            // 对子树进行分组背包
            /* 每个子树视为一个物品组
               选择子树内的若干条边（对应背包的选物品，i 条边就是物品 i）
               然后将不同子树的选择结果合并，得到当前节点的状态*/
            g[j + k] = max(g[j + k], dp[u][j] + dp[v][k]); 
        }
        memcpy(dp[u], g, (m + 1) << 2);
    }

    if(u == 0) return;
    // 考虑当前根选不选
    for(int i = m; i; i--)
    dp[u][i] = dp[u][i - 1] + w[u];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int k;
        cin >> k >> w[i];
        adde(k, i);
    }
    dfs(0);

    cout << dp[0][m] << "\n";



	return 0;
}
