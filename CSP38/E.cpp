#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n, m, q;

vector<int> mp[maxn];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    while(q--){
        int c;
        cin >> c;
        for(int i = 1; i <= n; i++){
            0
        }
    }

	return 0;
}