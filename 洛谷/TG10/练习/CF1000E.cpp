#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
const int maxm = 6e5 + 10;
int n, m;

int head[maxn], nxt[maxm], to[maxm], tot = 1;
void adde(int u, int v){
    nxt[++tot] = head[u];
    to[head[u] = tot] = v;
}

int dfn[maxn], low[maxn], cnt;
int stk[maxn], top;
int EBCC, bel[maxn];

void dfs(int u, int lst){
    dfn[u] = low[u] = ++cnt;
    stk[++top] = u;
    for(int i = head[u]; i; i = nxt[i]){
        if(i == lst) continue;
        int v = to[i];
        if(!dfn[v]){
            dfs(v, i ^ 1);
            low[u] = min(low[u], low[v]);
            // if(low[v] > dfn[u])
        }
        else low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]){
        int v; ++EBCC;
        do{
            v = stk[top--]; // !
            bel[v] = EBCC;
        }while(v != u);
    }

}

vector < int > mp[maxn];


void bfs(int start, int &endpoint, int &maxdis) {
    vector<int> dist(EBCC + 1, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    maxdis = 0;
    endpoint = start;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dist[u] > maxdis) {
            maxdis = dist[u];
            endpoint = u;
        }
        for (int v : mp[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1, x, y; i <= m; i++){
        cin >> x >> y;
        adde(x, y);
        adde(y, x);
    }

    for(int i = 1; i <= n; i++)
        if(!dfn[i]) dfs(i, 0);
    
    for(int u = 1; u <= n; u++) 
        for(int i = head[u]; i; i = nxt[i]) 
            if (i % 2 == 0) { 
                int v = to[i];
                if(bel[u] != bel[v]) {
                    mp[bel[u]].push_back(bel[v]);
                    mp[bel[v]].push_back(bel[u]);
                }
            }
       
    
    int A, B, maxdis;
    bfs(1, A, maxdis);
    bfs(A, B, maxdis);
    cout << maxdis << endl;

	return 0;
}