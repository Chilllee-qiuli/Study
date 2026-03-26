#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 16060;
int bea[maxn];
int n;
vector<int> g[maxn];
ll ans = -0x3f3f3f3f; 
ll dp[maxn];
void dfs(int u, int fa){
    dp[u] = bea[u];
    for(auto v : g[u]){
        if(v == fa) continue;
        dfs(v, u);
        dp[u] += max(0ll, dp[v]);
    }
    ans = max(ans, dp[u]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> bea[i];
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 0);


    cout << ans << endl;

	return 0;
}
