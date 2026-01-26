#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = 2e6 + 20;
vector<int> g[maxm];
int in[maxm];
int n, m;
vector<int> ans;
priority_queue<int, vector<int>, greater<int>> pr;

int main(){
   // freopen("1.in", "r", stdin);
   // freopen("1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
        in[a]++;
    }

    for(int i = 1; i <= n; i++) 
        if(!in[i]) pr.push(i);

    while(!pr.empty()){
        int u = pr.top();
        pr.pop();
        ans.push_back(u);
        for(auto v : g[u])
            if(--in[v] == 0) pr.push(v);   
    }
    if(ans.size() < n) cout << 0 << endl;
    else for(auto v : ans) cout << v << endl;



	return 0;
}