#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e4+10;
int f[maxn];
int n = 3e4, m, sz[maxn], d[maxn];

inline long long read(){
	char readch=getchar(); ll readtmp=0;
	ll readflag=1;
	while(readch<'0' || '9'<readch){if(readch=='-')readflag=-1;readch=getchar();}
	while('0'<=readch && readch<='9'){readtmp=readtmp*10+readch-'0';readch=getchar();}
	return readtmp*readflag;
}

int find(int x){
    if(x == f[x]) return x;
    int rt = find(f[x]); // ! 
    d[x] += d[f[x]]; // 注意这两条语句顺序。因为节点距root的距离是一层层累加下来的
    return f[x] = rt;
}

void merge(int x, int y){
    x = find(x); y = find(y);
    f[x] = y; d[x] = sz[y]; // x距离root距离是被合并集合原本整个集合的大小
    sz[y] += sz[x];
}

int ask(int x, int y){
    int rtx = find(x), rty = find(y);
    if(rtx != rty) return -1;
    return abs(d[x] - d[y]) - 1;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> m;

    // 千万要记得初始化！
    for(int i = 1; i <= n; i++)
        f[i] = i, sz[i] = 1;

    for(int i = 1, x, y; i <= m; i++){
        char ch;
        cin >> ch >> x >> y;
        if(ch == 'M') merge(x, y);
        else cout << ask(x, y) << endl;
    }
    

	return 0;
}
