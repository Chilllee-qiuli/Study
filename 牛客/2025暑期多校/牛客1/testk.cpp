#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+12;
int n;

int vis_door[maxn][4];

int mp[maxn][4];
int vis[maxn][4];
int f[maxn][4];
//vector<pair<int, int>> vc;

int walk(int now, int fa_door, int depth){
    int next_door = 0, son_door = 0;
    if(fa_door == 0 || fa_door == mp[now][0]) next_door = 1;
    else next_door = fa_door + 1;

    int son = mp[now][next_door];
    for(int i = 1; i <= mp[son][0]; i++) if(mp[son][i] == now) son_door = i;
       

    if(vis[now][next_door] >= 2) return depth;
    else if(f[now][next_door]) return f[now][next_door];
    else {
        vis[now][next_door]++;
        f[now][next_door] = walk(mp[now][next_door], son_door, depth + 1) - (vis_door[son][son_door] == 0);
        vis_door[son][son_door] = 1;
        vis_door[now][next_door] = 1;

        //printf("f[%d][%d] = %d\n", now, next_door, f[now][next_door]);
        return f[now][next_door];
    }
}

int main(){
    //freopen("k.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> mp[i][0];
        for(int j = 1; j <= mp[i][0]; j++){
            cin >> mp[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        if(!f[i][1]){ 
            walk(i, 0, 0);
            //printf("now_walk: node: %d\n", i);
            memset(vis, 0, sizeof(vis));
            memset(vis_door, 0, sizeof(vis_door));
        }
        cout << f[i][1] << endl;
    }

	return 0;
}
