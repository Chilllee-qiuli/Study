#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
const int maxn = 1e5+7, maxm = 1e5+7;

int h[maxn], to[maxm], nxt[maxm], cnt;
int ans[maxm];

inline void add(int u, int v){
    to[++cnt] = v;
    nxt[cnt] = h[u];
    h[u] = cnt;
}

void dfs(int x, int y){
    ans[x] = y;
    for(int i=h[x]; i; i = nxt[i]){
        if(ans[to[i]]) continue;
        dfs(to[i], y);
    }
}

inline long long read(){
	char readch=getchar(); ll readtmp=0;
	ll readflag=1;
	while(readch<'0' || '9'<readch){if(readch=='-')readflag=-1;readch=getchar();}
	while('0'<=readch && readch<='9'){readtmp=readtmp*10+readch-'0';readch=getchar();}
	return readtmp*readflag;
}

int main(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u = read(), v = read();
        add(v, u);
    }
    // 本题核心在于建反向图，从最大下表节点开始搜索，能搜到的点的答案自然是最先遍历到的下标

    for(int i=n; i; i--)
        if(!ans[i]) dfs(i, i);

    for(int i=1; i<=n; i++)
    cout << ans[i] << " \n"[i == n];

	return 0;
}
