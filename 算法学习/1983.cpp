#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1010;
int n, m;
vector<int> g[maxn];
int in[maxn], vis[maxn];

void adde(int u, int v){
    g[u].push_back(v);
    in[v]++;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        int y;
        vector<int> vc;
        for(int j = 1; j <= x; j++){
            cin >> y;
            vc.push_back(y);
        }
        int fl = 0;
        vector<int> small;
        for(int j = vc[0]; j < vc[x-1]; j++){
            if(j == vc[fl]) fl++;
            else {
                small.push_back(j);
            }
        }
        // 方向改为 small -> ita
        for(auto ita : vc)
            for(auto itb : small){
                adde(ita, itb);
            }
    }

    int cnt = 0, ans = 0;
    while(cnt < n){
        vector<int> cur;
        for(int i = 1; i <= n; i++){
            if(!in[i] && !vis[i]){
                cur.push_back(i);
            }
        }
        if(cur.empty()) break; // 安全检查（理论上不会发生）
        ans++;
        for(int u : cur){
            vis[u] = 1;
            cnt++;
        }
        for(int u : cur){
            for(auto v : g[u]){
                in[v]--;
            }
        }
    }
    cout << ans << endl;

    return 0;
}