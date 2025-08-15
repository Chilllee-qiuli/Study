#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
int n, a[maxn];

vector <int> mp[maxn];
int f[maxn], siz[maxn], son[maxn];
int top[maxn], val[maxn], dep[maxn];

void dfs1(int x, int fa){
    f[x] = fa; siz[x] = 1;
    dep[x] = dep[fa] + 1;
    for(auto to : mp[x]){
        if(to == fa) continue;
        dfs1(to, x);
        siz[x] += siz[to];
        if(siz[to] > siz[son[x]]) son[x] =to;
    }
}

void dfs2(int x, int tp){
    top[x] = tp;
    if(!son[x]) return ;
    dfs2(son[x], tp);
    for(auto to : mp[x]){
        if(to == f[x] || to == son[x]) continue;
        dfs2(to, to);
    }
}

void dfs3(int x){
    for(auto to : mp[x]){
        if(to == f[x]) continue;
        dfs3(to);
        val[x] += val[to];
    }
}

int LCA(int x, int y){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        x = f[top[x]];
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
    cin >> n;
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1; i < n; i++){
        int x = read(), y = read();
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    dfs1(1, 0);
    dfs2(1, 1);

    for(int i = 1; i < n; i++){
        int lca = LCA(a[i], a[i+1]);
        val[a[i]]++; val[a[i+1]]++;
        val[lca]--; val[f[lca]]--;
    }
    dfs3(1);
    for(int i = 2; i <= n; i++){
        val[a[i]]--;
    }

    for(int i = 1; i <= n; i++)
        printf("%d\n", val[i]);


	return 0;
}
