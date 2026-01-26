#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
int t;
int n;
ll a[maxn];
ll in[maxn], out[maxn];

vector<ll> mp[maxn];

ll ans = 0;
void dfs(int u){
    for(auto v : mp[u]){
        if(v == u) continue;
        ans = max(ans, v);
        dfs(v);
    }   
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ans = n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            in[i] = a[i] + i - 1;
            out[i] = in[i] + i - 1;
           // printf("i=%d, in[i]=%d, out[i]=%d\n", i, in[i], out[i]);
            mp[in[i]].clear();
            mp[out[i]].clear();
        }
        
        for(int i = 1; i <= n; i++){
            
            mp[in[i]].push_back(out[i]);
        }

        dfs(n);

        cout << ans << endl;
    }

	return 0;
}
