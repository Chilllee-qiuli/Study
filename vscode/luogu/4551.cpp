#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n;
int cnte;
int head[maxn], nxt[maxn], to[maxn], val[maxn];
int res[maxn];
int trie[maxn * 31][2];
int tot;

void adde(int u, int v, int w){
    to[++cnte] = v;
    nxt[cnte] = head[u];
    head[u] = cnte;
    val[cnte] = w;
}

void dfs1(int u, int fa){
    for(int i = head[u]; i; i = nxt[i]){
        if(to[i] == fa) continue;
        res[to[i]] = res[u] ^ val[i];
        dfs1(to[i], u);
    } 
}

void insert(int val){
    int u = 0;
    for(int i = (1 << 30); i; i >>= 1){
        int a = bool(val & i);
        if(!trie[u][a]) trie[u][a] = ++tot;
        u = trie[u][a];
    }
}


int ask(int x){
    int u = 0, ans = 0;
    for(int i = (1 << 30); i; i >>= 1){
        int a = bool(i & x);
        if(trie[u][!a]) {
            ans += i;
            u = trie[u][!a];
        }
        else u = trie[u][a];  
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n ;
    for(int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adde(u, v, w);
        adde(v, u, w);
    }

    dfs1(1, 0);
    for(int i = 1; i <= n; i++)
    insert(res[i]);

    int ans = 0;
    for(int i = 1; i <= n; i++)
    ans = max(ans, ask(res[i]));

    cout << ans << endl;

	return 0;
}

