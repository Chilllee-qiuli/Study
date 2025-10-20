#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n;
int son[maxn], fa[maxn], dep[maxn];
vector<int> mp[maxn];

void dfs(int u, int f){
    dep[u] = dep[f] + 1;
    fa[u] = f;
    for(auto v : mp[u]){
        if(v == f) continue;
        son[u]++;
        dfs(v, u);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    dfs(1, -1);

    

	return 0;
}
