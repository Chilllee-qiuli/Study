#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e5 + 10;
int t;
int n;

vector<int> mp[maxn];
int out[maxn];
int ans[maxn];

int main(){
   // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i <= n; i++) {
            out[i] = 0;
            mp[i].clear();
        }
        for(int i = 1; i < n; i++){
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            mp[u].push_back(v);
            mp[v].push_back(u);
            if(x >= y)  out[u]++;
            else out[v]++;            
        }

        queue<int> qu;

        for(int i = 1; i <= n; i++)
        if(!out[i]) qu.push(i);

        int cnt = 1;
        while(!qu.empty()){
            int u = qu.front();
            //cout << "nowu : " << u << endl;
            qu.pop();
            ans[u] = cnt++;
            for(int i = 0; i < mp[u].size(); i++){
                out[mp[u][i]]--;
                if(out[mp[u][i]] == 0) qu.push(mp[u][i]);
            }
        }
        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
    }

	return 0;
}
