#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k;
const int maxn = 4e5+10;
int f[maxn*2], attack[maxn*2], v[maxn*2], ans[maxn*2];

vector<int> e[maxn];

int find(int x){
    return x == f[x] ? x : (f[x] = find(f[x]));
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
    iota(f+1, f+1+n, 1);
    for(int i=1; i<=m; i++) {
        int x = read(), y = read();
        ++x; ++y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    cin >> k;
    for(int i=1; i<=k; i++) attack[i] = read(), v[++attack[i]] = 1;
    int now = n - k;

    // 关键思想：逆序
    // 并查集维护合并很方便，但是这里是分裂，不妨逆序操作离线记录修改
    
    for(int i=1; i<=n; i++) {
        if(!v[i]){
            for(int x : e[i]){
                if(!v[x] && find(x) != find(i))
                f[find(x)] = find(i), --now;
            }
        }
    }
    

    for(int i=k; i; i--){
        ans[i] = now;
        int x = attack[i];
        v[x] = 0;
        ++now;
        for(int y : e[x])
            if(!v[y] && find(x) != find(y))
                f[find(x)] = find(y), --now; 
    }
    ans[0] = now;
    for(int i=0; i<=k; i++) 
        cout << ans[i] << endl;

	return 0;
}
