#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
int f[maxn];
int n, m, sze[maxn], ans[maxn];


struct node{
    int x, y, z;
    friend bool operator < (node cmpx, node cmpy){
        return cmpx.z > cmpy.z;
    }
}e[maxn], q[maxn];

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

void merge(int x, int y){
    x = find(x); y = find(y);
    f[x] = y; sze[y] += sze[x];
}

// 离线思想

int main(){
    cin >> n >> m;
    for(int i = 1; i < n; i++){
        e[i].x = read();
        e[i].y = read();
        e[i].z = read();
    }

    for(int i = 1; i <= m; i++)
        q[i].x = i, cin >> q[i].z >> q[i].y;
    
    sort(e + 1, e + n);
    sort(q + 1, q + 1 + m);
    for(int i=1; i<=n; i++) sze[i] = 1, f[i] = i;

    int cnt = 1;

    for(int i = 1; i <= m; i++){
        int id = q[i].x;
        int k = q[i].z, v = q[i].y;
        while(cnt < n && e[cnt].z >= k){
            merge(e[cnt].x, e[cnt].y);
            ++cnt;
        }
        ans[id] = sze[find(v)] - 1;
    }

    for(int i=1; i<=m; i++)
        printf("%d\n", ans[i]);

	return 0;
}