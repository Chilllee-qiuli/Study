#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int maxn= 5e4+50;
int n; 
vector<int> ve [maxn];
queue<int> qu;
int center;
int siz[maxn];
int f[maxn];
int ans;
int fa[maxn];
int d[maxn];
int t;

void addedge(int u,int v){
	ve[u].push_back(v);
	ve[v].push_back(u);		
}

void getcenter(int u,int fa){
	siz[u]=1;
	for(int i=0; i< (int) ve[u].size(); i++){
		int v=ve[u][i];
		if(v == fa) continue;
		getcenter(v,u);
		siz[u]+= siz[v];
		f[u] = max(f[u], siz[v]);
	}
	f[u]= max(f[u], n- siz[u]);
	if( f[u] < f[center] || (f[u] == f[center] && u < center))
	center= u;
}

void bfs(){
	qu.push(center);
	while(!qu.empty()){
		int u= qu.front();
		qu.pop();
		for(int i=0 ; i < (int) ve[u].size(); i++){
			int v= ve[u][i];
			if(v == fa[u]) continue;
			fa[v]= u;
			d[v]= d[u]+1;
			ans+=d[v];
			qu.push(v);
		}
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
    cin >> t;
    while(t--){
	cin>>n;
	for(int a,b,i=1; i< n; i++){
		a=read();
		b=read();
		addedge(a,b);
	}
	center=0;
	f[center]=INF;
	getcenter(1,0);
	bfs();
	cout<<center<<' '<<ans<<endl;
}

	return 0;
}