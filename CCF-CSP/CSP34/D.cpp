#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1010;
const int maxw = 4e4 + 10; // 最大代价
const int inf = 0x3f3f3f3f;
vector<int> hw[maxn]; // 货物
int n, m, v;
int b[maxn], c[maxn];
int dp[2][maxw]; // (20n + 20m)
// 定义dp 0， j 表示这个仓库不选东西，代价为j时的最大收益
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> v;
    for(int i = 1; i <= n; i++)
        cin >> b[i] >> c[i];

    for(int i = 1; i <= m; i++){
        int a, t;
        cin >> a >> t;
        hw[t + 1].push_back(a);
    }
    for(int i = 1; i < maxw; i++) dp[0][i] = dp[1][i] = -inf;
    for(int i = 1; i <= n + 1; i++){
        for(int j = 1; j < maxw; j++){
             // 这一个仓库不选的最大值等于上一个仓库选了和没选的共同最大值
            dp[0][j] = max(dp[0][j], dp[1][j]);
            if(j >= b[i]) // 选这个仓库要先付出代价，且至少选一个物品?
            dp[1][j] = dp[0][j - b[i]];
            else dp[1][j] = 0;
        }
        for(auto it : hw[i]){ // 对这个仓库的货物跑一个01背包
            for(int j = maxw - 1; j >= b[i] + c[i]; j--)
            dp[1][j] = max(dp[1][j], dp[1][j - c[i]] + it);
        }
    }
    int ans;
    for(int i = 1; i < maxw; i++){
        if(dp[0][i] >= v + i){
            ans = i; break;
        }
    }

    cout << ans << endl;




	return 0;
}
