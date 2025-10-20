#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5007;
int dp[N][N]={-1};
struct edge{
    int to;
    int w;
};
vector<edge> e[N];
vector<vector<int>> e2;
int dfs(int u,int k){
    if(u==1) return 0;
    if(dp[u][k]>=0) return dp[u][k];
    if(k==0) goto here;
    for(int j=0;j<e2[u].size();j++){
        if(dp[u][k-1]>=0) dp[u][k-1]=min(dp[u][k-1],dfs(e2[u][j],k-1));
        else if(dp[u][k-1]<0) dp[u][k-1]=dfs(e2[u][j],k-1);
    }
    here:
    for(int j=0;j<e[u].size();j++){
        if(dp[u][k]<0) dp[u][k]=dfs(e[u][j].to,k)+e[u][j].w;
        else dp[u][k]=min(dp[u][k],dfs(e[u][j].to,k)+e[u][j].w);
    }
    
    return min(dp[u][k],dp[u][k-1]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    e2.resize(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w}),e[v].push_back({u,w});
    }
    for(int i=1;i<=m;i++){
        int p,q;
        cin>>p>>q;
        e2[p].push_back(q),e2[q].push_back(p);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=dfs(i,0);
    }
    cout<<ans<<endl;
    return 0;
}