#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int n, q;
int a[maxn];
int fa[maxn];
int w[maxn];
map<int, ll> cnt[maxn];
vector< pair<int, int> > mp[maxn];

void dfs(int now, int f){
    fa[now] = f;
    for(auto it : mp[now]){
        if(it.first == f) {
            w[now] = it.second;
            continue;
        }
        dfs(it.first, now);
        cnt[now][a[it.first]] += it.second;
    }
}


int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> q;
        
        ll cost = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt[i].clear();
            mp[i].clear();
        }

        for(int i = 1, u, v, c; i < n; i++) {
            cin >> u >> v >> c;
            if(a[u] != a[v]) cost += c;
            mp[u].push_back({v, c});
            mp[v].push_back({u, c});
        }

        dfs(1, 0);

        while(q--){
            int v, x;
            cin >> v >> x;

            cost += cnt[v][a[v]];
            cost -= cnt[v][x];

            if(v != 1){
                cnt[fa[v]][a[v]] -= w[v];   
                if(a[fa[v]] == a[v]) cost += w[v];
                cnt[fa[v]][x] += w[v];
                if(a[fa[v]] == x) cost -= w[v];
            }
            
            a[v] = x;         
            
            cout << cost << endl;
        }
    }


	return 0;
}
