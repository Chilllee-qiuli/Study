#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 10;
const int maxm = 5e4 + 10;
int n, m;
 
vector<int> mp[maxn];

int dfn[maxn], low[maxn], cnt;
int SCC, stk[maxn], top, out[maxn];
bool ins[maxn];
int bel[maxn];
vector<int> scc[maxn];
void dfs(int u){
    dfn[u] =  low[u] = ++cnt;
    stk[++top] = u;
    ins[u] = 1;
    for(auto v : mp[u]){
        if(dfn[v] == 0){
            dfs(v);
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
        }while(v != u);
    }
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
    }   

    for(int i = 1; i <= n; i++)
        if(!dfn[i]) dfs(i);

    for(int u = 1; u <= n; u++)
    for(auto v : mp[u])
    {
       // printf("bel[%d]=%d -> bel[%d]=%d\n", u, bel[u], v, bel[v]);
        if(bel[v] != bel[u]) {
            out[bel[u]]++;
           // cout << "u= " << u << " v= " << v << endl;
        }
    }

    int tmp = 0;
    for(int i = 1; i <= SCC; i++)
        if(out[i] == 0) {
            if (tmp) tmp = -1;  
            else tmp = i;  
        }
    

    if(tmp <= 0) cout << 0 << endl;
    else cout << scc[tmp].size() << endl;
   // cout << "tmp= " << tmp << endl;

	return 0;
}
