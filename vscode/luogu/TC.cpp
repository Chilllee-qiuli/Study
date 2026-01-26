#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 550;
int n, m, k;
int mp[maxn][maxn];
int bfsvis[maxn][maxn];
int vis[maxn];
int dis[maxn][maxn];
int dis_box[100];
int stx, sty;

struct Box{
    int x, y;
}box[maxn];
int cntb ;

struct node{
    int x, y;
};
int to[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
queue<node> qu;
void bfs(int nowx, int nowy){
    memset(dis, -1, sizeof(dis));
    dis[nowx][nowy] = 0;
    while(!qu.empty()) qu.pop();
    qu.push({nowx, nowy});
    while(!qu.empty()){
        node now = qu.front();
        qu.pop();
        for(int k = 0; k < 4; k++){
            int x = now.x + to[k][0], y = now.y + to[k][1];
            if(x < 1 || x > n || y < 1 || y > m || dis[x][y] != -1 || !mp[x][y]) continue;
            dis[x][y] = dis[now.x][now.y] + 1;
            qu.push({x, y});
        }
    }
}

struct jiesheng{
    int a, b, sum;
    bool operator < (jiesheng y){
        return sum > y.sum;
    }
};

vector<jiesheng> tmpjs;
ll ans = 0;
int work(){
    bfs(stx, sty);
    for(int i = 1; i <= k; i++){
        if(dis[box[i].x][box[i].y] == -1) return -1;
        dis_box[i] = dis[box[i].x][box[i].y];
    }
    for(int i = 1; i < k; i++){
        bfs(box[i].x, box[i].y);
        for(int j = i + 1; j <= k; j++){
            tmpjs.push_back({i, j, dis_box[i] + dis_box[j] - dis[box[j].x][box[j].y]});
        }
    }

    sort(tmpjs.begin(), tmpjs.end());
    for(auto it : tmpjs){
        if(vis[it.a] || vis[it.b]) continue;
        vis[it.a] = vis[it.b] = 1;
        ans += 2ll * dis_box[it.a] + 2ll * dis_box[it.b] - it.sum;
    }
    for(int i = 1; i <= k; i++){
        if(!vis[i]) ans += 2ll * dis_box[i];
    }
    return ans ;
}

int main(){
    freopen("1.in", "r", stdin);
    //ios::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < str.size(); j++){
            if(str[j] != '#') mp[i][j + 1] = 1;
            else continue;
            if(str[j] == 'S'){
                stx = i; sty = j + 1;
            }
            else if(str[j] == 'X') {
                box[++cntb] = {i, j + 1};
                //printf("in: %d %d\n", i, j + 1);
                //mp[i][j + 1] = cntb;
            }
        }
    }

    cout << work() << endl;

	return 0;
}
