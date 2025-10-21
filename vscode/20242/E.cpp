#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int n, m, d, k;

int vis[2][maxn];

struct node{
    int x, step;
};

int dth[maxn];

vector<int> mp[maxn];

queue<node> q;

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m >> d;
        memset(vis, 0, sizeof(vis));
        memset(dth, 0, sizeof(dth));
        while(!q.empty()) q.pop();
        for(int i = 1; i <= n; i++) mp[i].clear();

        for(int i = 1,u, v; i <= m; i++){
            cin >> u >> v;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        cin >> k;
        for(int i = 1, x; i <= k; i++){
            cin >> x;
            q.push({x, 0});
            vis[0][x] = 2;
        }

        while(!q.empty()){
            node now = q.front();
            int u = now.x;
            int step = now.step + 1;
            q.pop();
            for(auto v : mp[u]){
                if(vis[step & 1][v]) continue;
                vis[step & 1][v] = step;
                q.push({v, step});
            }
        }

        while(!q.empty()) q.pop();

        q.push({1, 0});
        int flag = 0;

        while(!q.empty()){
            node now = q.front();
            int u = now.x;
            int step = now.step + 1;
            dth[u] = now.step;
            if(u == n) {
                flag = 1;
                break;
            }
            q.pop();
            for(auto v : mp[u]){
                if(vis[step & 1][v] && step >= vis[step & 1][v]) continue;
                q.push({v, step});
            }
        }

        if(!flag) cout << -1 << endl;
        else {
            vector<int> ans;
            int u = n;
            ans.push_back(u);
            while(u != 1){
                if(dth[u] == 0) {
                    cout << "zhuiji " << endl;
                    break;
                } 
                for(auto v : mp[u]){
                    if(dth[v] == 1){ans.push_back(u = v); u = 1; break;}
                    if(dth[v] == dth[u] - 1) {ans.push_back(u = v); break;}
                }
            }
            ans.push_back(1);
            for(int i = ans[ans.size() - 1]; i >= 0; i--) cout << ans[i] << " ";
            cout << endl;
            
        }


        
    }

	return 0;
}