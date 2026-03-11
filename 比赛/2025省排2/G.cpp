#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int a[maxn];
int n;
vector<int> g[maxn];
int dp[maxn], ans[maxn];

void dfs1(int u, int fa){
    for(auto v : g[u]){
        if(v == fa) continue;
        dfs1(v, u);
        dp[u] += max(0, dp[v]);
    }
    if(a[u]) dp[u]++;
    else dp[u]--;
}

void dfs2(int u, int fa, int tmp){
    tmp -= max(0, dp[u]); // 摘除当前子树u，父亲的ans
    ans[u] = max(tmp, 0) + dp[u];

    for(auto v : g[u]) {
        if(v == fa) continue;
        dfs2(v, u, ans[u]);
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs1(1, 0);
    dfs2(1, 0, 0);

    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;




	return 0;
}
