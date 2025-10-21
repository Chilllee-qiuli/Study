#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
ll n;
ll m;

int fa[maxn];
int find(int x){
    if(x == fa[x]) return x;
    else return fa[x] = find(fa[x]);
}
ll edge[maxn];

map<int, pair<ll, ll> > mp;
vector<ll> no;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1, u, v; i <= m; i++){
        cin >> u >> v;
        int x = find(u), y = find(v);
        if(x != y) fa[x] = fa[y];
        edge[u]++;
        edge[v]++;
    }
    // 连通块点数边数计数
    for(int i = 1; i <= n; i++){
        mp[find(i)].first++;
        mp[find(i)].second += edge[i];
    }
 
        // 非完全子图连通块统计
    for(auto it : mp){
        ll ver = it.second.first;
        if(it.second.second/2 != ver*(ver-1)/2) no.push_back( ver*(ver-1)/2 - it.second.second/2 );

        //printf("tetstt: %d %lld %lld\n", it.first, it.second.first, it.second.second/2);
    }

    if(no.empty()){ // 都是完全子图，找最小的两个子图连块
        for(auto it : mp) no.push_back(it.second.first);
        sort(no.begin(), no.end());
        ll ver = no[0] + no[1];
        cout << ver * (ver - 1) / 2 - no[0] * (no[0] - 1) / 2 - no[1] * (no[1] - 1) / 2  << endl;
    
    }
    else { // 有非完全子图，找连边数最小的块
        ll ans = 0;
        for(int i = 0; i < no.size(); i++){
            ans += no[i];
        }
        cout << ans << endl;
    }

    


    return 0;
}