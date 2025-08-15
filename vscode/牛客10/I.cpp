#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
int n, m;
//vector<vector<int>> mp;
int mp[1001][1001];


bool work(int id, int x, int y){

    if(id == n*m && !mp[x][y]) {mp[n][m] = id; return 1;}
    else if(id == n*m) return 0;
    if(!mp[x][y]){
        mp[x][y] = id;
        printf("mp[%d][%d]= %d\n", x, y, mp[x][y]);
        if(id % 4 == 1){
            if(!mp[(x + id + n * m - 1) % n + 1][y]) return work(id + 1, (x + id + n * 2 - 1) % n + 1, y);
            else if(!mp[x][(y - id + m * n - 1) % m + 1]) return work(id + 1, x, (y - id + m * 2 - 1) % m + 1);
            else if(!mp[(x - id + n * m - 1) % n + 1][y]) return work(id + 1, (x - id + n * 2 - 1) % n + 1, y);
            else if(!mp[x][(y + id + m * n - 1) % m + 1]) return work(id + 1, x, (y + id + m * 2 - 1) % m + 1);
            else return 0;
        }
        else if(id % 4 == 2){
            if(!mp[x][(y + id + m * n - 1) % m + 1]) return work(id + 1, x, (y + id + m * 2 - 1) % m + 1);
            else if(!mp[(x - id + n * m - 1) % n + 1][y]) return work(id + 1, (x - id + n * 2 - 1) % n + 1, y);
            else if(!mp[x][(y - id + m * n - 1) % m + 1]) return work(id + 1, x, (y - id + m * 2 - 1) % m + 1);
            else if(!mp[(x + id + n * m - 1) % n + 1][y]) return work(id + 1, (x + id + n * 2 - 1) % n + 1, y);
            else return 0;
        }
        else if(id % 4 == 3){
            if(!mp[(x - id + n * m - 1) % n + 1][y]) return work(id + 1, (x - id + n * 2 - 1) % n + 1, y);
            else if(!mp[x][(y - id + m * n - 1) % m + 1]) return work(id + 1, x, (y - id + m * 2 - 1) % m + 1);
            else if(!mp[(x + id + n * m - 1) % n + 1][y]) return work(id + 1, (x + id + n * 2 - 1) % n + 1, y);
            else if(!mp[x][(y + id + m * n - 1) % m + 1]) return work(id + 1, x, (y + id + m * 2 - 1) % m + 1);
            else return 0;
        }
        else {
            if(!mp[x][(y - id + m * n - 1) % m + 1]) return work(id + 1, x, (y - id + m * 2 - 1) % m + 1);
            else if(!mp[(x + id + n * m - 1) % n + 1][y]) return work(id + 1, (x + id + n * 2 - 1) % n + 1, y);
            else if(!mp[x][(y + id + m * n - 1) % m + 1]) return work(id + 1, x, (y + id + m * 2 - 1) % m + 1);
            else if(!mp[(x - id + n * m - 1) % n + 1][y]) return work(id + 1, (x - id + n * 2 - 1) % n + 1, y);
            else return 0;
        }
        
    }
    else return 0;
}

int main(){
 //   freopen("1.in", "r", stdin);
  //  ios::sync_with_stdio(0);
  //  cin.tie(0), cout.tie(0);
    cin >> n >> m;
    //mp.resize(n + 1, vector<int>(m + 1, 0));

    if(work(1, 1, 1)) {
        cout << "Yes" << endl;
        

    }
    else cout << "No" << endl;
    for(int i = 1; i <= n; i++, cout << endl)
        for(int j = 1; j <= m; j++)
        cout << mp[i][j] << " ";
	return 0;
}
