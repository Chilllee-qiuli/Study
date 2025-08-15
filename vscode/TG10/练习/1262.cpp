#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3030;
const int inf = 0x3f3f3f3f;
int n;
int p;
int money[maxn];

vector<int> mp[maxn], G[maxn];
vector<int> scc[maxn];

int dfn[maxn], low[maxn], cnt;
int stk[maxn], top;
bool ins[maxn];
int SCC, cost[maxn], bel[maxn];
int can[maxn];
void dfs1(int u){
    dfn[u] = low[u] = ++cnt;
    stk[++top] = u;
    ins[u] = 1;
    for(auto v : mp[u]){
        if(dfn[v] == 0){
            dfs1(v);
            low[u] = min(low[u], low[v]);
        }
        else if(ins[v]) low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]){
        ++SCC;
        int v;
        do{
            v = stk[top--];
            scc[SCC].push_back(v);
            ins[v] = 0;
            bel[v] = SCC;
            if(money[v] != inf) can[SCC] = 1;
            cost[SCC] = min(cost[SCC], money[v]);
        }while(v != u);
    }

}

void dfs2(int u){
    for(auto v : G[u]){
        can[v] = 1;
        dfs2(v);
    }
}

int in[maxn];

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> p;
    
    for(int i = 1; i <= n; i++) {
        money[i] = inf;
        cost[i] = inf;
    }
    for(int i = 1; i <= p; i++){
        int x, y;
        cin >> x >> y;
        money[x] = y;
    }   
    int r;
    cin >> r;
    while(r--){
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
    }
    for(int i = 1; i <= n; i++)
    if(!dfn[i]) dfs1(i);

    for(int i = 1; i <= n; i++)
    for(auto v : mp[i]){
        if(bel[i] != bel[v]) G[bel[i]].push_back(bel[v]), in[bel[v]]++; 
    }

    ll ans = 0;
    int flag = 0;

    for(int i = 1; i <= SCC; i++){
        if(!in[i]) {
            //cout << "scc= " << i << endl;
            if(cost[i] == inf)  flag = 1;
            ans += cost[i];
        }
    }
    if(flag){
        cout << "NO" << endl;
        for(int i = 1; i <= SCC; i++) if(can[i]) dfs2(i);
        int ans_no = inf;
        for(int i = 1; i <= SCC; i++)
        {
            
            if(can[i] == 0){
            cout << "scc: " << i << " " << scc[i][0] << endl;
                sort(scc[i].begin(), scc[i].end());
                ans_no = min(ans_no, scc[i][0]);
            }
        }
        cout << ans_no << endl;

        return 0;
    }
    cout << "YES" << endl;
    cout << ans << endl;


	return 0;
}
