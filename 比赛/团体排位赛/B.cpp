#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int t;
int n;
int cnt = 0;
int vis[maxn];
map<int, int> fl;
int xx[maxn], yy[maxn];
vector <int> mp[maxn];

void dfs(int u, int fa){
    cnt++;
    vis[u] = 1;
    for(auto v : mp[u]){
        if(v == fa) continue;
        if(vis[v]) continue;
        dfs(v, u);
    }
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cnt = 0;
        cin >> n;
        fl.clear();
        int dc = 0;
        for(int i = 1; i <= n; i++) {
            vis[i] = 0;
            cin >> xx[i] >> yy[i];
            if(!fl[xx[i]]) fl[xx[i]] = ++dc;
            if(!fl[yy[i]]) fl[yy[i]] = ++dc;
        }
        for(int i = 1; i <= dc; i++) mp[i].clear();
            
        for(int i = 1; i <= n; i++){
            int u = fl[xx[i]], v = fl[yy[i]];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }   
        int ans = 0;

        for(int i = 1; i <= n; i++){
            if(vis[i]) continue;
            cnt = 0;
            dfs(i, 0);
            ans = max(ans, cnt);
        }
        cout << ans << endl;
        
    }



    return 0;
}