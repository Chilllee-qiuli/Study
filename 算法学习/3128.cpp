#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e4+9; // 点差分模板

int N, T;
vector <int> vec[maxn];
int val[maxn];
int fa[maxn], siz[maxn], son[maxn];
int dep[maxn], top[maxn];


void dfs1(int x, int f){
    fa[x] = f; siz[x] = 1; dep[x] = dep[f] + 1;
    for(auto to : vec[x]){
        if(to == f) continue;
        dfs1(to, x);
        siz[x] += siz[to];
        if(siz[to] > siz[son[x]]) son[x] = to;
    }
}

void dfs2(int x, int tp){
    top[x] = tp;
    if(!son[x]) return ;
    dfs2(son[x], tp);
    for(auto to : vec[x]){
        if(to == fa[x] || to == son[x]) continue;
        dfs2(to, to);
    }
}

int ans;

void dfs3(int x){
    for(auto to : vec[x]){
        if(to == fa[x]) continue;
        dfs3(to);
        val[x] += val[to];
    }
    ans = max(ans, val[x]);
}

int LCA(int x, int y){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    if(dep[x] < dep[y]) return x;
    return y;
}


inline long long read(){
	char readch=getchar(); ll readtmp=0;
	ll readflag=1;
	while(readch<'0' || '9'<readch){if(readch=='-')readflag=-1;readch=getchar();}
	while('0'<=readch && readch<='9'){readtmp=readtmp*10+readch-'0';readch=getchar();}
	return readtmp*readflag;
}

int main(){
    cin >> N >> T;
    for(int i = 1, x, y; i < N; i++){
        x = read(); y = read();
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    dfs1(1, 0);
    dfs2(1, 1);
    while(T--){
        int x = read(), y = read();
        int lca = LCA(x, y);
        val[x]++; val[y]++;
        val[lca]--; val[fa[lca]]--;

    }
    dfs3(1);
    cout << ans << endl;

	return 0;
}
