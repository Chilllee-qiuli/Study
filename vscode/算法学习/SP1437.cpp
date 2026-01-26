
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4+10;
int n, dis[maxn];
int A, B;
vector<int> mp[maxn];

inline long long read(){
	char readch=getchar(); ll readtmp=0;
	ll readflag=1;
	while(readch<'0' || '9'<readch){if(readch=='-')readflag=-1;readch=getchar();}
	while('0'<=readch && readch<='9'){readtmp=readtmp*10+readch-'0';readch=getchar();}
	return readtmp*readflag;
}

void dfs(int x, int fa){
    dis[x] = dis[fa] + 1;
    for(auto to : mp[x]){
        if(to == fa) continue;
        dfs(to, x); 
    }
}


int main(){
    cin >> n;

    for(int i = 1; i < n; i++){
        int u = read(), v = read();
        mp[u].push_back(v);
        mp[v].push_back(u);
    }


    dfs(1, 0);
    for(int i = 1; i <= n; i++) 
        if(dis[i] > dis[A]) A = i;

    dis[A] = 0; dfs(A, 0);
    int ans = 0;
    for(int i = 1; i <= n; i++) 
        if(dis[i] > dis[B]) B = i, ans = dis[B] - dis[A];

    cout << ans << endl;

	return 0;
}
