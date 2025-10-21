#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int t;
int n;
int cnt = 0;
int fa[maxn];
int ans[maxn];
map<int, int> lisan;
map<int, int> mp;

int find(int x){
    if(x == fa[x]) return fa[x];
    else return fa[x] = find(fa[x]);
}

void merge(int u, int v){
    u = find(u); v = find(v);
    fa[u] = v;

}

int main(){
   // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        int dc = 0;
        cnt = 0;
        lisan.clear();
        mp.clear();

        cin >> n;
        for(int i = 1; i <= n + 1; i++) {
            fa[i] = i;
            ans[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            int u, v;
            cin >> u >> v;
            if(!lisan[u]) lisan[u] = ++dc;
            if(!lisan[v]) lisan[v] = ++dc;
            u = lisan[u];
            v = lisan[v];
            merge(u, v);
        }
        vector<int> an(n + 1);
        for(int i = 1; i <= n; i++){
            mp[find(i)]++;
        }
        int maxx = 0;
        for(auto it : mp){
            maxx = max(maxx, (int)it.second);
        }
        cout << maxx << endl;
        // cout << "sum: " << sum << endl;
    }



    return 0;
}