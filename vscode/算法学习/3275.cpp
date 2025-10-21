#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pr;
#define mk make_pair
const int maxn = 1e5 + 10;
int n, k, m;
ll dp[maxn];
vector<pr> g[maxn];

void adde(int u, int v, int w){
    g[u].push_back(mk(v, w));
}

int A[maxn];
int dfn[maxn], low[maxn], T;
int stk[maxn], top;
bool ins[maxn];
int S[maxn], SCC;

int sum[maxn];
int f[maxn], in[maxn];

void dfs(int u){
    dfn[u] = low[u] = ++T;
    stk[++top] = u;
    ins[u] = 1;
    for(auto it : g[u]){
        int v = it.first;
        if(dfn[v] == 0){
            dfs(v);
            low[u] = min(low[v], low[u]);
        }
        else if(ins[v]) low[u] = min(low[u], dfn[v]);
    }

    if(dfn[u] == low[u]){
        ++SCC;
        while(stk[top] != u){
            int p = stk[top--];
            ins[p] = 0;
            S[p] = SCC;
            sum[SCC] ++;
        }
        ins[u] = 0;
        S[u] = SCC;
        sum[SCC] ++;
        --top;
    }

} 

queue<int> q;
vector<pr> G[maxn];


int main(){
    freopen("P3275_2.in", "r", stdin);
    freopen("1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        int x, a, b;
        cin >> x >> a >> b;
        if(x == 1){
            adde(a, b, 0);
            adde(b, a, 0);
        } else if(x == 2){
            // a < b
            adde(a, b, 1);
        } else if(x == 3){
            // a >= b  => b -> a (0)
            adde(b, a, 0);
        } else if(x == 4){
            // a > b  => b -> a (1)
            adde(b, a, 1);
        } else if(x == 5){
            // a <= b
            adde(a, b, 0);
        }
    }   

    for(int i = 1; i <= n; i++)
    if(!dfn[i]) dfs(i);

    for(int i = 1; i <= n; i++)
    for(auto it : g[i])
        if(S[i] != S[it.first]) G[S[i]].push_back(mk(S[it.first], it.second)), in[S[it.first]]++;
        else if(it.second == 1){
            cout << -1 << endl;
            return 0;
            // SCC 内部不应该有边长为1的边
        }

    for(int i = 1; i <= SCC; i++)
    if(!in[i]) q.push(i), dp[i] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto it : G[u]){
            int v = it.first, w = it.second;
            dp[v] = max(dp[v], dp[u] + w);
            in[v]--;
            if(!in[v]) q.push(v);
        }
    }

    ll ans = 0;
    for(int i = 1; i <= SCC; i++)
        ans += dp[i] * sum[i];

        cout << ans << endl;


	return 0;
}
