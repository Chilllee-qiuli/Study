#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
int n;
vector<int> g[maxn];
int in[maxn];
vector<int> ans;
void tp(){
    queue<int > qu;
    for(int i = 1; i <= n; i++){
        if(!in[i]) qu.push(i);
    }
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        ans.push_back(u);
        for(auto v : g[u]){
            if(--in[v] == 0) qu.push(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        while(x){
            g[i].push_back(x);
            in[x]++;
            cin >> x;
        }
    }

    tp();

    for(auto it : ans) cout << it << " ";
    cout << endl;

    return 0;
}