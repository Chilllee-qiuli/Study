#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 220;
#define pr pair<int, int>
#define mk make_pair
int n, L;
int mp[maxn][maxn];
int model[5][9] = {{1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0, 0, 1, 0, 0, 1, 0, 1}, {1, 0, 0, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 1, 0, 0}, {1, 1, 1, 1, 1, 1, 1, 0, 0}};
int cnt[65566];

pr judge(int x, int y){
    int minn = mp[x][y], maxx = mp[x + 1][y + 1];
    for(int i = 0; i < 5; i++)
    for(int j = 0; j < 9; j++){
        if(model[i][j]) minn = min(minn, mp[x + i][y + j]);
        else maxx = max(maxx, mp[x + i][y + j]);
        //if(x == 2 && y == 1) printf("i = %d j = %d mp = %d model = %d minn = %d maxx = %d\n", i, j, mp[x + i][y + j], model[i][j], minn, maxx );
    }
    // cout << "final minn = " << minn << " maxx = " << maxx << endl;
    return mk(maxx, minn);
}


void work(){

    for(int i = 1; i <= n - 4; i++)
    for(int j = 1; j <= n - 8; j++){
        pr range = judge(i, j);
        if(range.first >= range.second) continue;
        else cnt[range.second + 1]--, cnt[range.first + 1]++;
        //cout << range.first << " " << range.second << endl;
        //cout << "i = " << i << " j = " << j << endl;
    }
}


int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> L;

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) 
    cin >> mp[i][j];

    work();
    for(int i = 1; i <= L; i++){
        cnt[i] += cnt[i - 1];
        if(cnt[i]) cout << i << endl; 
    }


j
	return 0;
}