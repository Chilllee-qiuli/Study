#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = 1e6;
int dis[maxm];
int t;

struct matrix{
    int a[4][4];
    bool operator == (matrix y){
        for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++){
            if(a[i][j] != y.a[i][j]) return 0;
        }
        return 1;
    }
    bool operator < (const matrix& y) const {
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                if (a[i][j] != y.a[i][j]) {
                    return a[i][j] < y.a[i][j];
                }
            }
        }
        return false;
    }
    void print(){
        for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
        cout << a[i][j] << " \n"[j == 3];
    }
    void read(){
        for(int i = 1; i <= 3; i++){
            int x;
            cin >> x;
            a[i][1] = x / 100;
            a[i][2] = x / 10 % 10;
            a[i][3] = x % 10;
        }
    }
} cur;

matrix right(matrix x, int row){
    matrix y = x;
    swap(y.a[row][1], y.a[row][2]);
    swap(y.a[row][1], y.a[row][3]);
    return y;
}
matrix down(matrix x, int column){
    matrix y = x;
    swap(y.a[1][column], y.a[2][column]);
    swap(y.a[1][column], y.a[3][column]);
    return y;
}
matrix rotate(matrix x){
    matrix y;
    for(int i = 1; i <= 3; i++)
    for(int j = 1; j <= 3; j++)
    y.a[j][3 - i + 1] = x.a[i][j];
    return y;
}


map<matrix, int> mp;
int tot = 0;

void bfs(){
    queue<matrix> q;
    q.push(cur);
    dis[1] = 1;
    mp[cur] = ++tot;
    while(!q.empty()){
        matrix now = q.front();
        q.pop();
        for(int row = 1; row <= 3; row++){
            matrix y = right(now, row);
            if(!mp.count(y)){
                mp[y] = ++tot;
                dis[mp[y]] = dis[mp[now]] + 1;
                q.push(y);
            }
        }
        
        for(int col = 1; col <= 3; col++){
            matrix y = down(now, col);
            if(!mp.count(y)){
                mp[y] = ++tot;
                dis[mp[y]] = dis[mp[now]] + 1;
                q.push(y);
            }
        }
        
        matrix y = rotate(now);
        if(!mp.count(y)){
            mp[y] = ++tot;
            dis[mp[y]] = dis[mp[now]] + 1;
            q.push(y);
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    for(int i = 1; i <= 3; i++)
    for(int j = 1; j <= 3; j++)
    cur.a[i][j] = (i - 1) * 3 + j;

    bfs();

    cin >> t;
    while(t--){
        matrix a, b;
        map<int, int> f;
        a.read();
        b.read();
        for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)
        f[a.a[i][j]] = (i - 1) * 3 + j;

        for(int i = 1; i <= 3; i++)   
        for(int j = 1; j <= 3; j++)
        b.a[i][j] = f[b.a[i][j]];

        cout << dis[mp[b]] - 1 << endl;


    }

	return 0;
}
