#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n, m;

vector<int> mp[maxn];
int f[maxn], cnt;
char color[maxn];
string s;
void dfs(int u, int fa){
    f[u] = cnt;
    //cout << "u: " << u << " f[u]: " << f[u] << endl;
    for(int v : mp[u]){
        if(v == fa || s[v] != s[u]) continue;
        dfs(v, u);
    }
}

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;  
    cin >> s;
    s = "1" + s;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){
        if(f[i]) continue;
        cnt++;
        color[cnt] = s[i];
        dfs(i, 0);
    }

    for(int i = 1; i <= m; i++){
        int a, b;
        char c;
        cin >> a >> b >> c;
        if(f[a] == f[b] && color[f[a]] != c)
            cout << 0;
        else cout << 1;
        
    }cout << endl;




}