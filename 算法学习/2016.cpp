#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3003;
int n;
vector<int> g[maxn];
int dp[2][maxn];


void dfs(int u, int fa){
    dp[0][u] = 0;
    dp[1][u] = 1;

    for(auto v : g[u]){
        if(v == fa) continue;
        dfs(v, u);
        dp[1][u] += min(dp[1][v], dp[0][v]);
        dp[0][u] += dp[1][v];
    }   
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        int u, k;
        cin >> u >> k;
        u++;
        while(k--){
            int x;
            cin >> x;
            x++;
            g[u].push_back(x);
            g[x].push_back(u);
        }
    }

    dfs(1, 0);

    cout << min(dp[1][1], dp[0][1]) << endl;

	return 0;
}
