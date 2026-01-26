#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 25;
int s[maxn];
int vis[maxn];
int flag;
int n;
ll  m;

void dfs(int x, ll sum){
    if(sum == m){
        flag = 1;
        return ;
    }
    if(sum > m || x > n) return ;
    if(flag) return ;
    vis[x] = 1;
    dfs(x + 1, sum + s[x]);
    if(flag) return ;
    vis[x] = 0;
    dfs(x + 1, sum);
}

vector<int> vc;

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> s[i];
    sort(s + 1, s + 1 + n);

    dfs(1, 0);

    for(int i = 1; i <= n; i++)
    if(vis[i]) vc.push_back(s[i]);

    for(int i = 0; i <= vc.size() - 1; i++)
    cout << vc[i] << " \n"[i == vc.size() - 1];

	return 0;
}