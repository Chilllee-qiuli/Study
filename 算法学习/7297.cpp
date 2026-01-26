#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pr; // 题解1讲的真的很好
#define mk make_pair
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int n, k;
int b[maxn];
char s[55][55];
int dis[maxn * 50];
int vis[maxn * 50];

vector<pr> g[maxn * 50];

void adde(int u, int v, int w = 0, int f = 0){
    g[u].push_back(mk(v, w));
    if(f) g[v].push_back(mk(u, w));
}

struct node{
    int w, u;
    friend bool operator < (node x, node y){
        return x.w > y.w;
    }
};
priority_queue<node> qu;
void dijk(){
    //for(int i = 1; i <= n; i++) dis[i] = inf;
    memset(dis, 0x3f, sizeof(dis));

    dis[1] = 0;
    node tmp = {0, 1};
    qu.push(tmp);

    while(!qu.empty()){
        int u = qu.top().u;
        qu.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto it : g[u]){
            int v = it.first, w = it.second;
            if(dis[v] > (ll) dis[u] + w)
                dis[v] = dis[u] + w;
                tmp = {dis[v], v};
                qu.push(tmp);
            
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> b[i];

    for(int i = 1; i <= k; i++){
        cin >> s[i] + 1;
    }
    // 除了第0层之外，建立连边
    for(int j = 1; j <= k; j++)
    for(int i = 1; i <= n - 1; i++) adde(i + j * n, i + 1 + j * n, 1, 1);

    // 建立第0层到对应颜色层的单向边
    for(int i = 1; i <= n; i++) adde(i, b[i] * n + i);

    // 如果可以从某种颜色到这个点的本色，就连单向边
    for(int j = 1; j <= n; j++)
    for(int i = 1; i <= k; i++)
        if(s[i][b[j]] == '1') adde(i * n + j, j);
    

    // 注意不能在每一层取min来输出ans，因为要有对应的传递关系才有1-k层到第0层的回边
    dijk();
    if(dis[n] == inf) cout << -1 << endl;
    else cout << dis[n] << endl;

	return 0;
}