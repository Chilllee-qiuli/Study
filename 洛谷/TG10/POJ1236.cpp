#include<bits/stdc++.h>
using namespace std; // luogu P2746
typedef long long ll;
const int maxn = 110;
const int maxm = maxn * maxn;
int n;

int head[maxn], to[maxm], nxt[maxm], tot;
void adde(int u, int v){
    nxt[++tot] = head[u];
    to[head[u] = tot] = v; 
}

int dfn[maxn], low[maxn], cnt;
int stk[maxn], top;
bool ins[maxn];
int bel[maxn], SCC, siz[maxn];
void dfs(int u){
    dfn[u] = low[u] = ++cnt;
    stk[++top] = u;
    ins[u] = 1;
    for(int i = head[u]; i; i = nxt[i]){
        if(!dfn[to[i]]){
            dfs(to[i]);
            low[u] = min(low[u], low[to[i]]);
        }
        else if(ins[to[i]]) low[u] = min(low[u], dfn[to[i]]);
    }
    if(low[u] == dfn[u]){
        ++SCC;
        int v;
        do{
            v = stk[top--];
            ins[v] = 0;
            bel[v] = SCC;
            siz[SCC]++;
        }while(v != u);
    }
}

vector <int> mp[maxn];
int ind[maxn], outd[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;

    for(int i = 1; i <= n; i++){
        int v;
        while(cin >> v){
            if(v == 0) break;
            adde(i, v);
        }
    }

    for(int i = 1; i <= n; i++)
        if(!dfn[i]) dfs(i);

    for(int u = 1; u <= n; u++)
        for(int i = head[u]; i; i = nxt[i])
            if(bel[u] != bel[to[i]]){
                mp[bel[u]].push_back(bel[to[i]]);
                ind[bel[to[i]]]++;
                outd[bel[u]]++;
            } 
        
    int IND = 0, OUTD = 0;

    for(int i = 1; i <= SCC; i++){
        if(ind[i] == 0) IND++;
        if(outd[i] == 0) OUTD++;
    }

    cout << IND << endl;

    if(SCC >= 2) cout << max(IND, OUTD) << endl;
    else cout << 0 << endl;


	return 0;
}
