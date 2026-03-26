#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3030;
const int inf = 0x3f3f3f3f;
#define pr pair<int, int>
#define mk make_pair
#define fi first
#define se second
int val[maxn];
int dp[maxn][maxn]; // dp[u][j] 表示节点u为根的子树，接入j个用户的最大收益，注意可能是负数
int n, m;
int siz[maxn];
vector<pr> g[maxn];

void dfs(int u){
    if(g[u].empty()){
        siz[u]++;
        dp[u][0] = 0;
        dp[u][1] = val[u];
        return;
    }
    for(int i = 1; i <= n; i++) dp[u][i] = -inf;
    for(auto [v, c] : g[u]){
        dfs(v);
        siz[u] += siz[v];
        // 对于每个子树，跑一个分组背包
        for(int j = n; j >= 0; j--) // 枚举总用户数，或者说“代价”
        for(int k = 1; k <= min(siz[v], j); k++){ // 枚举组内的所有物品
            dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k] - c);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> m;

    for(int i = 1; i <= n - m; i++){
        int k;
        cin >> k;
        while(k--){
            int a, c;
            cin >> a >> c;
            g[i].push_back(mk(a, c)); // 编号，费用
        }
    }

    for(int i = n - m + 1; i <= n; i++) cin >> val[i];

    dfs(1);

    int ans = 0;
    for(int i = n; i >= 0; i--){
        if(dp[1][i] >= 0) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

	return 0;
}
