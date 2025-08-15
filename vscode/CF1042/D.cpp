#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int n;

vector<int> mp[maxn];

void work(){

}

int sum[maxn];
ll cnt;

void dfs2(int u, int fa){
    if(mp[u].size() == 1) sum[u] = 1;
    for(auto v : mp[u]){
        if(v == fa) continue;
        dfs2(v, u);
        sum[u] += sum[v];
    }
}
int leaf[maxn];
int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        cnt = 0;
        for(int i = 1; i <= n; i++) mp[i].clear(), sum[i] = 0;
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        if(n == 2){cout << 0 << endl; continue;}

        int leaf_total = 0;
        for(int i = 1; i <= n; i++)
            if(mp[i].size() == 1) leaf_total++;
        

        int ans = 0x3f3f3f3f;
        for(int u = 1; u <= n; u++){
            leaf[u] = 0;
            for(auto v : mp[u]) if(mp[v].size() == 1) leaf[u]++;
            ans = min(ans, leaf_total - leaf[u]);
        }

        cout << ans << endl;

    }

	return 0;
}
