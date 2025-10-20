#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
int stx, sty;
int vis[110][110];
int ans;

int walk[9][2] = {{0, 0}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}};

bool check(int x, int y){
    return x >= 1 && y >= 1 && x <= n && y <= n && !vis[x][y];
}

struct node{
    int x, y;
};

void bfs(){
    vector<node> st;
    int l = 0;
    st.push_back({stx, sty});
    vis[stx][sty] = 1;
    ans++;
    while(l < st.size()){
        node now = st[l];
        l++;
        
        for(int i = 1; i <= 8; i++){
            int nxtx = now.x + walk[i][0];
            int nxty = now.y + walk[i][1];
            if(check(nxtx, nxty)){
                    vis[nxtx][nxty] = vis[now.x][now.y] + 1;
                    if(vis[nxtx][nxty] > k + 1) continue;
                    ans++;
                    //cout << nxtx << " " << nxty << endl;
                st.push_back({nxtx, nxty});
            }
        }
    }   
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;

    cin >> stx >> sty;
    bfs();
    cout << ans << endl;


	return 0;
}
