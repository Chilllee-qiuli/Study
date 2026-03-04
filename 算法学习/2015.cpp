#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
int n, Q;
int son[maxn][2], val[maxn][2];
int dp[maxn][maxn];
int siz[maxn]; // 记录节点 i 为根的树的边数

/*
树形背包：将树的每个子树视为一个 “物品组”，选择子树中的若干条边（对应背包的 “选物品”），
然后将不同子树的选择结果合并，得到当前节点的状态。
本质是把 01 背包的 “单个物品选择” 扩展为 “子树内一组物品的选择”。*/

void dfs(int u){
    int a = son[u][0], b = son[u][1];
    if(!a && !b) return;
    dfs(a); dfs(b);
    siz[u] = siz[a] + siz[b] + 2;
    for(int i = -1; i <= siz[a]; i++) // 遍历树形背包（底层逻辑是01背包）
    for(int j = -1; j <= siz[b]; j++){ 
        // -1 表示没选这个子树且没选到这个子树的边，0表示没选这个子树但是选了到这个子树的边
        // i 表示选了到这个子树的边且这个子树选了 i 条边
        // 统计边数花费的时候，要用 (i + 1) + (j + 1)。用 -1 很自然符合式子
        
        // 不仅要记录子节点 a 子树的最优解，还要加上 u -> a 这条边的贡献
        int vala = i == -1 ? 0 : dp[a][i] + val[u][0]; 
        int valb = j == -1 ? 0 : dp[b][j] + val[u][1];
        dp[u][i + j + 2] = max(dp[u][i + j + 2], vala + valb);
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> Q;
    for(int i = 2; i <= n; i++) {
        int u, v;
        cin >> u;
        int b = son[u][0] ? 1 : 0;
        cin >> son[u][b] >> val[u][b];
    }

    dfs(1);
    cout << dp[1][Q] << "\n";



	return 0;
}
