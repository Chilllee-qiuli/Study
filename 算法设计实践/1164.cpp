#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<int,int>
#define mp make_pair
const int maxn = 5000 + 20;
int n;
int vis[maxn];
pr node[maxn];
vector<int> now;
double ans;
double dis[maxn];
double d(pr x, pr y){
    return sqrt(pow((x.first - y.first), 2) + pow((x.second - y.second), 2) );
}
void prim(){

    for(int i = 0; i <= n; i++) dis[i] = 1e6;
    dis[1] = 0;
    while(1){
        int u = 0;
        for(int i = 1; i <= n; i++)
        if(!vis[i] && dis[i] < dis[u]) u = i;
        if(!u) break;
        vis[u] = 1;
       // cout << "nowu: " << u << endl;
        ans += dis[u];
        for(int i = 1; i <= n; i++){
            if(vis[i]) continue;
            double dtmp = d(node[u], node[i]);
            dis[i] = min(dis[i], dtmp);
        }
    }
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;  
        node[i] = mp(x, y);
    }

    prim();

    printf("%.2lf\n", ans);


	return 0;
}